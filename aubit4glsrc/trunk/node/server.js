
var express = require('express');
var app = express()
  , server = require('http').createServer(app)
  , io = require('socket.io').listen(server);



// Port to accept http requests from
server.listen(8080);

var spawn = require('child_process').spawn;


function emitLines(stream, re){
    re = re && /\n/;
    var buffer = '';
    stream.on('data', stream_data);
    stream.on('end', stream_end);

    function stream_data(data){
	console.log("emitLine : " +data);
        buffer += data;
        flush();
    }//stream_data

    function stream_end(){
        if(buffer) stream.emit('line', buffer);
    }//stream_end


    function flush(){
        var re = /\n/;
        var match;
        while(match = re.exec(buffer)){
            var index = match.index + match[0].length;
            stream.emit('line', buffer.substring(0, index));
            buffer = buffer.substring(index);
            re.lastIndex = 0;
        }
    }//flush

}//emitLines


io.sockets.on('connection', function (socket) {
  var child=null;
  console.log("Connection");
  
  var authorised=false;



  socket.on('handshake_response', function(data) {
	// UI should send these over
	// we're not going to worry too much about them for testing :)
	console.log(data.username);
	console.log(data.password);
	console.log(data.protocol);
	console.log(data.program);

	if (data.protocol!="UIVERSION 1.0") {
		socket.emit('error', {
				errorMsg:"Incorrect protocol response - expectiong UIVERSION 1.0"
		});
		socket.disconnect();
	} else {
		//
		// Check the password...
		// we should probably md5 encode this with some salt and check with that
		// again - just testing atm..
		console.log("data.password="+data.password);
		if (data.password=="aubit4gl") {
			authorised=true;
			socket.emit('welcome', {
				success:true
			});


			console.log("Starting : " + "baseProgs/"+data.program);

			child = spawn("sh",[ "baseProgs/"+data.program ]);
			child.stdout.setEncoding('utf-8');
			child.stderr.setEncoding('utf-8');
			child.stdin.setEncoding('utf-8');
			

	
			child.stderr.on('data',function(d) {
				console.log("STDERR>>"+d);
			});

			var allLines="";

			emitLines(child.stdout);
		
			child.stdout.on('line', function( d ) {
				allLines+=d;
				// The protocol for Json should send the whole object with a trailing } + newline...
				// We'll do a test for that..
				if (d=="}\n") {
					try {
						// Convert what we got into a javascript object..
						var x=JSON.parse(allLines);
					} catch (e) {
						console.log("Unable to parse :");
						console.log(allLines);
						console.log(e);
						
					}
					socket.emit('envelope',x);
					allLines="";
				}
			});

			socket.on('trigger', function( d ) {
				if (typeof d !="string") {
					d=JSON.stringify(d)+"\n";
				} 
				console.log("Trigger!!!"+d);
				child.stdin.write( d );
				console.log("Written to stdin");
			});

			child.stdout.on('close', function() {
				//socket.disconnect();
				child=null;
			});

			child.stdin.on('close', function() {
				child=null;
				//socket.disconnect();
			});

		} else {
			socket.emit('error', {
					errorMsg:"Failed authentication"
			});
			socket.disconnect();
		}
	}
  });


  socket.emit('handshake', {
	
  });

  socket.on('disconnect', function () {
	console.log("Disconnect");
	try {
		if (child) {
			try {
				child.stdin.write("{\"ID\":\"DIE\"\n}\n");
				console.log("Child should be closed : " + child.pid);
				child.stdin.end()
			} catch (e) {
				console.log(e);
			}
		}
	}  catch (e) {
	}
  });
});


var oneDay = 86400000;
console.log("__dirname="+__dirname);
app.use(express.compress());

app.use(express.static(__dirname + '/html')); //where /html is a subfolder of your app 

// Use this version if you want caching 
//  this greatly speeds up load times of the pages (mainly because of the extjs)
// but - means it wont always pick up browser javascript changes properly :(
//
// Should be safe to use it in production though when we get there..
//
//app.use(express.static(__dirname + '/html',  { maxAge: oneDay })); //where /html is a subfolder of your app 
