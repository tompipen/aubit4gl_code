var express = require('express');
var net = require('net');
var userid = require('userid');
var Guid=require('guid');
var xml2json = require('xml2json');
var compression=require('compression');
var xmlescape = require('xml-escape');


var app = express(),
    httpServer = require('http').createServer(app),
    io = require('socket.io').listen(httpServer, {'transports': ['websocket', 'polling']});



var toJsonOptions={object:true, arrayNotation: true, alternateTextNode:'Data' };

var childProcesses = {};
//var childSockets = {};

var executionPort = 1234;


function xmlEscapeQuotes(v) {
console.log("Escaping : " + v);
	return xmlescape(v);
}

function getDataFromSV(sv) {
	var r="<SV FN=\""+xmlEscapeQuotes(sv.FN)+"\" ";
	if (sv.FT) { r+=" FT=\""+sv.FT+"\""; }
	if (sv.T) { r+=" T=\""+sv.T+"\""; }
	r+=">";
	if (sv.Value) { r+=xmlEscapeQuotes(sv.Value); }
	r+="</SV>";
	return r;
}
function getDataFromSVS(svs) {
	var i;
	var r="<SVS>";
	for(i=0;i<svs.length;i++) {
		r+=getDataFromSV(svs[i]);
	}
	r+="</SVS>";
	return r;
}

function convertTriggerJsonToXML(json) {
	console.log("Need to fixup triggered json to xml");
	console.log(json);
	var jObj=JSON.parse(json);
	var r="<TRIGGERED ";
	r+=" ID=\""+jObj.ID+"\"";
	if (jObj.INFIELD) {
		r+=" INFIELD=\""+jObj.INFIELD+"\"";
	}
	if (jObj.BUFFERTOUCHED) {
		r+=" BUFFERTOUCHED=\""+jObj.BUFFERTOUCHED+"\"";
	}
	if (jObj.ENVELOPEID) {
		r+=" ENVELOPEID=\""+jObj.ENVELOPEID+"\"";
	}
	if (jObj.LASTCURSOR) {
		r+=" LASTCURSOR=\""+jObj.LASTCURSOR+"\"";
	}
	r+=">";
	if (jObj.SVS) {
		r+=getDataFromSVS(jObj.SVS);
	}
	r+="</TRIGGERED>\n";
	

	console.log ("transforms to : "+r);
	return r;
}
// Convert from XML into some usable JSON object
// 
function convertXMLEnvelopeToObject(xml) {
console.log("XML="+xml);
try { 
var x=xml2json.toJson(xml,  toJsonOptions );
} catch (Err) {
console.log("Error reading XML : " );
console.log(xml);
console.log(Err);
return null
}
if (x && x.ENVELOPE) {
	console.log("xml2json.toJson returns:");
        console.dir(x,{ depth:null});
        var y={
                id: x.ENVELOPE[0].ID,
                pid: x.ENVELOPE[0].PID,
                commands: []
        };
        var a;
        for (a=0;a<x.ENVELOPE[0].COMMANDS.length;a++) {
                for (var k in x.ENVELOPE[0].COMMANDS[a])  {
			if (k=="$t" || k=="Data") {
				continue;
			}
			console.dir(x.ENVELOPE[0].COMMANDS[a][k]);
			for (var oCnt=0;oCnt<x.ENVELOPE[0].COMMANDS[a][k].length; oCnt++) { 
                        	var cmd={ type:k};
                        	for (var k2 in x.ENVELOPE[0].COMMANDS[a][k][oCnt]) {
					var newName=k2.toLowerCase();
					if (cmd[newName]) {
                                		cmd["_"+newName]= x.ENVELOPE[0].COMMANDS[a][k][oCnt][k2];
					} else {
                                		cmd[newName]= x.ENVELOPE[0].COMMANDS[a][k][oCnt][k2];
					}
                        	}
                        	y.commands.push( cmd);
			}
                }
        }
	return y;
}
return x;
}


var callbackServer = net.createServer((c) => {
    var connGuid=null;
    var execGuid=null;
    //var pid=0;

    var pendingData=[];
    var allLines="";

    console.log("CallBack Server Connected");


    // consolidate the lines untile we get a "}\n" - then send it as an envelope
    // to the socket associated with the connection GUID we detected in our stream
    var processLine=function(d) { 
				allLines+=d;
	//console.log("d="+d);
				// The protocol for Json should send the whole object with a trailing } + newline...
				// We'll do a test for that..
				if (d=="}\n" || d=="</ENVELOPE>\n") {
		//console.log("end of block");
					try {

						if (connGuid) {
							console.log("allLines="+allLines);
							var x=convertXMLEnvelopeToObject(allLines);
							x.connGuid=connGuid;
							x.execGuid=execGuid;
							//x.pid=pid;
        						var child=childProcesses[connGuid];
							if (child) {
								if (child.associatedWebSocket) { 
									console.log("Sending envelope to "+connGuid);
									console.dir(x,{ depth:null});
									console.log("\n\n\n");
									child.associatedWebSocket.emit('envelope',x);
								} else {
									console.error("Child.associatedWebSocket not set");
								}
							} else {
								consol.error("Child not found");
							}
						} else {
							console.error("connGuid not set???");
						}

					} catch (e) {
						console.log("Unable to parse :");
						console.log(allLines);
						console.log(e);
					}
					allLines="";
				}
	};
    
    	emitLines(c);


    	c.on('data', function(x) {
		if (connGuid==null && execGuid==null) { 
    			console.log("data:");
    			console.log(""+x);
			var o=convertXMLEnvelopeToObject(x);
			console.log("o=");
			console.dir(o, { depth :null} );

			console.log(o.commands);
			console.log("O.Pid="+o.pid);
			console.log(o.commands.length);
			console.log(o.commands[0].type);
			if (o.commands && o.pid && o.commands.length>0 && o.commands[0].type=="PROGRAMSTARTUP") {
				console.log("Looks like we have a startup...");
				var pid=o.PID
				var env=o.commands[0].env;
				var a;
				for (a=0;a<env.length;a++) {
					switch (env[a].NAME) {

						case "CONNECTIONGUID":
							connGuid=env[a].VALUE;
							break;

						case "EXECUTIONGUID":
							execGuid=env[a].VALUE;
							break;

						default: break;
					}
				}

				console.log("connGuid="+connGuid);
				console.log("execGuid="+execGuid);

				if (connGuid && execGuid) {
					var child=childProcesses[connGuid];

					if (child) {
						child.associatedProgramSocket=c;
						child.associatedPID=o.pid;
					}

					for (a=0;a<pendingData.length;a++) { 
						processLine(pendingData[a]);
					}
					pendingData=[];
					
				} else {
					console.error("Was expecting to have picked up the connGuid and execGuid :(");
				}

			}
		} else { 
			// We can just ignore it...
		}
    	}); 

    c.on('line', function(x) {
	if (connGuid==null || execGuid==null) {
		//console.log("Deferring :" + x);
		pendingData.push(x);	
		return;
	} 
	//console.log("Calling Process line:" + x);
	processLine(x);
    });



    c.on('disconnect', function(x) {
        console.log("program disconnect");
    });

});

callbackServer.listen(executionPort);

httpServer.listen(8080);

var spawn = require('child_process').spawn;


function emitLines(stream, re) {
    re = re && /\n/;
    var buffer = '';
    stream.on('data', stream_data);
    stream.on('end', stream_end);

    function stream_data(data) {
        buffer += data;
        flush();
    } //stream_data

    function stream_end() {
        if (buffer) stream.emit('line', buffer);
    } //stream_end


    function flush() {
        var re = /\n/;
        var match;
        while (match = re.exec(buffer)) {
            var index = match.index + match[0].length;
            stream.emit('line', buffer.substring(0, index));
            buffer = buffer.substring(index);
            re.lastIndex = 0;
        }
    } //flush

} //emitLines


//var allLines="";

/*
			emitLines(child.stdout);
		
			child.stdout.on('line', function( d ) {
				allLines+=d;
				// The protocol for Json should send the whole object with a trailing } + newline...
				// We'll do a test for that..
				if (d=="}\n") {
					try {
						// Convert what we got into a javascript object..
						var x=JSON.parse(allLines);
						socket.emit('envelope',x);
					} catch (e) {
						console.log("Unable to parse :");
						console.log(allLines);
						console.log(e);
					}
					allLines="";
				}
			});
			*/


io.sockets.on('connection', function(socket) {
    var child = null;
    console.log("Got Connection/IOSockets "+socket);

    var authorised = false;



    socket.on('handshake_response', function(data) {
	console.log("handshake response");
        // UI should send these over
        // we're not going to worry too much about them for testing...
        console.log(data.username);
        console.log(data.password);
        console.log(data.protocol);
        console.log(data.program);

        if (data.protocol != "UIVERSION 1.0") {
            socket.emit('servererror', {
                errorMsg: "Incorrect protocol response - expectiong UIVERSION 1.0"
            });
	console.log("UIVERSION disconnect");
            socket.disconnect();
            return;
        }
        //
        // Check the password...
        // we should probably md5 encode this with some salt and check with that
        // again - just testing atm..
        // allLines
        //
        var uid = -1;
        try {
            var uid = userid.uid(data.username);
        } catch (Err) {}

        if (uid <= 0) { // Exclude root too ...
	    console.log("Invalid user");

            socket.emit('servererror', {
                errorMsg: "Invalid user"
            });

	console.log("invalid user disconnect");
            socket.disconnect();
            return;
        }


        console.log("data.password=" + data.password);

        if (data.password != "aubit4gl") {
		console.log("failed auth");
            socket.emit('servererror', {
                errorMsg: "Failed authentication"
            });
	console.log("auth failed disconnect");
            socket.disconnect();
            return;
        }

        authorised = true;

        //socket.emit('welcome', { success:true });


        console.log("Starting : " + "baseProgs/runProgram.sh " + data.program);
        var guid = Guid.raw();
	console.log("Guid="+guid);
        var env = Object.create(process.env);

        env.CONNECTIONGUID = guid;
        env.AFGLPORT = executionPort;
        env.AFGLSERVER = 'localhost';


        child = spawn("baseProgs/runProgram.sh", [data.program], {
            env: env,
            uid: uid,
            shell: true
        });


	console.log("child="+child);
	if (!child) {
            socket.emit('servererror', {
                errorMsg: "Failed to start program"
            });

		console.log("failed to start disconnect");
            socket.disconnect();
            return;
        }

	child.on('close', (code) => {
 		console.log("child process exited with code "+code);

		socket.emit('programComplete',{
				code,
				pid: child.associatedPID,
				//pid: child.pid,
				guid:guid
		});

            	delete childProcesses[guid];

		console.log("child close disconnect");
		socket.disconnect();
        });


        child.associatedWebSocket = socket;

        childProcesses[guid] = child;

        child.stdout.setEncoding('utf-8');
        child.stderr.setEncoding('utf-8');
        child.stdin.setEncoding('utf-8');



        child.stderr.on('data', function(d) {
		console.log("STDERR:" +d);
	console.log("On pid : " + child.associatedPID);
            child.associatedWebSocket.emit('stderr', {guid:guid, data: d, pid: child.associatedPID, a:1});
        });
        child.stdout.on('data', function(d) {
		console.log("STDOUT:" +d);
	console.log("On pid : " + child.associatedPID);
            child.associatedWebSocket.emit('stdout', {guid:guid, data: d, pid: child.associatedPID, a:2});
        });


        child.associatedWebSocket.on('trigger', function(d) {
            if (typeof d != "string") {
                d = JSON.stringify(d) + "\n";
            }

            console.log("Trigger!!!" + d);
            //child.stdin.write(d);
		if (child.associatedProgramSocket) {
            		console.log("Written to associatedProgramSocket");
			child.associatedProgramSocket.write(convertTriggerJsonToXML(d));
		}

        });

        child.stderr.on('close', function() {
            delete childProcesses[guid];
        });

        child.stdout.on('close', function() {
            delete childProcesses[guid];
        });

        child.stdin.on('close', function() {
            delete childProcesses[guid];
        });





    // Browser has died ? 
    child.associatedWebSocket.on('disconnect', function() {
        console.log("Disconnect - child.associatedWebSocket.on");
        try {
            if (child) {
                try {
                    child.stdin.write("{\"ID\":\"DIE\"\n}\n");
                    console.log("Child should be closed : " + child.pid);
                    child.stdin.end()
                } catch (e) {
		    // Dont care...
                    console.log("Couldnt send die:" + e);
                }
            }
        } catch (e) {}
    });




    });

    // Initiate the handshake
    socket.emit('handshake', {

    });

    console.log("Should have emitted handshake");
});


var oneDay = 86400000;
console.log("__dirname=" + __dirname);
app.use(compression())

app.use(express.static(__dirname + '/html')); //where /html is a subfolder of your app 

// Use this version if you want caching 
//  this greatly speeds up load times of the pages (mainly because of the extjs)
// but - means it wont always pick up browser javascript changes properly :(
//
// Should be safe to use it in production though when we get there..
//
//app.use(express.static(__dirname + '/html',  { maxAge: oneDay })); //where /html is a subfolder of your app 
//
