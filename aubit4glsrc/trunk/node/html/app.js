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
			app.environmentVariables={};
			Ext.Array.each(d.EnvironmentVariables, function(v) {
				app.environmentVariables[v.name]=v.value;
			});
			AubitDesktop.FGLUtils._dbdate=app.environmentVariables["DBDATE"];
		}
	}

	return app;
}
