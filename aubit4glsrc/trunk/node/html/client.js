



function initializeSocket(p_username,p_password, p_program , callback) {
var socket;

try { 
	 socket = io.connect(':8080', {'transports': ['websocket', 'polling']});


	if (socket==null) {
		alert("Server doesnt seem to be running");
		return false;
	}


	if (!p_username) p_username='mike';
	if (!p_password) p_password='CM';
	if (!p_program) p_program='prog';
	socket.on('handshake', function () {
		socket.emit('handshake_response', {
			username:p_username,
			password:p_password,
			program:p_program,
			protocol:'UIVERSION 1.0'
		});
	});


	var allLines="";

	socket.on('error', function(err) {
		console.error("err");
	});

	socket.on('envelope', function (data) {
		console.log("ENVELOPE\n---------------------\n");
		pidAsString=""+data.pid;
		console.log(data.id+" "+data.pid);
		console.dir(data);
		console.log("COMMANDS...");
		//var oldCurrent=currentApplication;
		var currentApplication;
                currentApplication=applicationsByPid[pidAsString];
		if (currentApplication==null) {
		        var app=createApplication(data, socket);
                	applications.push(app);
                	currentApplication=app;
                	applicationsByPid[pidAsString]=app;
		}

		console.log("Setting app to app associated with PID : " + pidAsString);

		for (var a in data.commands) {

			if (data.commands[a]==null) {
				continue;
			}
			callback(currentApplication, data.commands[a]);

		}

                //currentApplication=oldCurrent;
	});


	socket.on('welcome', function() {
		console.log("we got a welcome!");
		// Handshake was OK..
	});

	socket.on('stdout', function(dt) {
		if (console && console.log) { 
			console.log(dt.data);
		}
                var currApp=applicationsByPid[dt.pid];
		if (currApp) {
			if (currApp.stdOut) {
				currApp.stdOut.append(dt.data);
			}
		}
		//Ext.ComponentQuery.query('#stdOutLogField')[0].append(msg);
	});
	socket.on('stderr', function(dt) {
		if (console && console.error) { 
			console.error(dt.data);
		}
                var currApp=applicationsByPid[dt.pid];
		if (currApp) {
			if (currApp.stdErr) {
				currApp.stdErr.append(dt.data);
			}
		}
		//Ext.ComponentQuery.query('#stdErrLogField')[0].append(msg);
	});
	
	var haveFatal=false;
	socket.on('servererror', function(err) {
		console.log("Fatal error : " + err.errorMsg);
		console.dir(err);
		
		if (err && err.errorMsg) {
			Ext.MessageBox.alert("Fatal Error1" , err.errorMsg);
		} else {
		 	Ext.MessageBox.alert("Fatal Error2", err);
		}
		location.href="/index.html";
		haveFatal=true;
	});
	

	socket.on('programComplete', function(o) {
                currentApplication=applicationsByPid[o.pid];

		if (currentApplication && currentApplication.stopping) {
			haveFatal=true;
			return;
		}

		if (!haveFatal) { 
			haveFatal=true;
			Ext.MessageBox.alert("Program Complete" , "Program completed", function() {
				location.href="/index.html";
			});
		}
	});

	socket.on('disconnect', function () {
		if (!haveFatal) {
			//console.log("disconnect");
			//alert("Disconnect");
		 	Ext.MessageBox.alert("Fatal Error", "Disconnect", function() { 
				location.href="/index.html";
			});
		}
	});
} catch (Err) {
console.error(Err);
}

return true;
}


// Convert our 
function convertToType(obj,defType) {
	var arr=[];
	if (!obj) return [];

        if (Ext.isArray(obj)) {
		Ext.Array.each(obj, function(o) {
			o.type=defType;
		});
		return obj;
	} else { 
		if (Ext.isObject(obj)) {
			Ext.Object.each(obj, function(k,v) {
			if (Ext.isArray(v)) {
				Ext.Array.each(v, function(a) {
				a.type=k;
				arr.push(a);
				});
			} else {
				v.type=k;
				arr.push(v);
			}
		});
		}
	}
	return arr;
}
