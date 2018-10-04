var applications=[]
var applicationsByPid={};
//var currentApplication;


function createApplication(envelope, socket) {

	var app;
	app={
		windows:{},
		socket:socket, 
		windowsStack:[],
		pid: envelope.PID,
		currentWindow:null,
		executionGuid:null,
		lastFocusField:null,
		connGuid:envelope.connGuid,
		execGuid:envelope.execGuid,
		Contexts:{},
		options:{ },
		Forms:{},
		sendResponse: function (d, app) {
        		if (app && app.currentWindow) {
                		app.currentWindow.clearError();
        		}
		
        		console.log("Respond to WAITFOREVENT with : ");
        		console.dir(d);
			// If we've got an array - send it as a package..
			if (Ext.isArray(d)) {
				var cnt=1;

				Ext.Array.each(d, function(r) {
					r.CNT=cnt++;
					r.MAXCNT=d.length;
	
					console.dir(r);
        				app.socket.emit('trigger',r);
				});
			} else {
        			app.socket.emit('trigger',d);
			}
		},
		sendError: function ( d, app) {
        		app.socket.emit('uierror',d);
		},
		programStartup: function(d) {
			app.environmentVariables={};
			Ext.Array.each(d.env, function(v) {
				app.environmentVariables[v.NAME]=v.VALUE;
			});
			app.executionGuid=app.environmentVariables["EXECUTIONGUID"];
			AubitDesktop.FGLUtils._dbdate=app.environmentVariables["DBDATE"];
		}
	}

	return app;
}
