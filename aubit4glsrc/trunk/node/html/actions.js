function sendResponse(d, app) {
	if (!app) {
		app=currentApplication; // This should never get hit - should always be set....
	}

	if (app && app.currentWindow) {
		app.currentWindow.clearError();
	}

	console.log("Respond to WAITFOREVENT with : ");
	console.dir(d);
	socket.emit('trigger',d);
}
