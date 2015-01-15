var applications=[]
var applicationsByPid={};
//var currentApplication;


function createApplication(envelope) {

	var app;
	app={
		windows:{},
		windowsStack:[],
		pid: envelope.PID,
		currentWindow:null,
		lastFocusField:null,
		Contexts:{},
		options:{ },
		Forms:{},
		programStartup: function(d) {
		}
	}

	return app;
}
