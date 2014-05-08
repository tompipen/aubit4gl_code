


var socket;

function initializeSocket(p_username,p_password, p_program , callback) {
	 socket = io.connect(':8080');


	if (socket==null) {
		alert("Server doesnt seem to be running");
		return false;
	}


	if (!p_username) p_username='mike';
	if (!p_password) p_password='CM';
	if (!p_program) p_program='Bibble';
	socket.on('handshake', function () {
		socket.emit('handshake_response', {
			username:p_username,
			password:p_password,
			program:p_program,
			protocol:'UIVERSION 1.0'
		});
	});


	var allLines="";


	socket.on('envelope', function (data) {
		console.log("ENVELOPE\n---------------------\n");
		pidAsString=""+data.PID;
		console.log(data.ID+" "+data.PID);
		console.dir(data);
		console.log("COMMANDS...");
		//var oldCurrent=currentApplication;
		var currentApplication;
                currentApplication=applicationsByPid[pidAsString];
		if (currentApplication==null) {
		        var app=createApplication(data);
                	applications.push(app);
                	currentApplication=app;
                	applicationsByPid[pidAsString]=app;
		}

		console.log("Setting app to app associated with PID : " + pidAsString);

		for (var a in data.Commands) {

			if (data.Commands[a]==null) {
				continue;
			}
			callback(currentApplication, data.Commands[a]);

		}

                //currentApplication=oldCurrent;
	});


	socket.on('welcome', function() {
		console.log("we got a welcome!");
		// Handshake was OK..
	});
	
	var haveFatal=false;
	socket.on('error', function(err) {
		console.log("Fatal error : " + err.errorMsg);
		console.dir(err);
		
		if (err && err.errorMsg) {
			alert("Fatal Error : " + err.errorMsg);
		} else {
			alert("Fatal Error" + err);
		}
		location.href="/index.html";
		haveFatal=true;
	});
	

	socket.on('disconnect', function () {
		if (!haveFatal) {
			console.log("disconnect");
			alert("Disconnect");
			location.href="/index.html";
		}
	});

return true;
}
