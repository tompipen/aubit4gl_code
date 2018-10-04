function onKeyHandler() {
	this.callback(this.ID, "ONKEY");
}





function getIconClassInternal(currentApplication, nm) {
	var activeFormName;
	var windowName=currentApplication.currentWindow.A4GL_name;
	if (currentApplication.currentWindow && currentApplication.currentWindow.activeForm) { activeFormName=currentApplication.currentWindow.activeForm.A4GL_name; }

	return getIconClass(nm,activeFormName,windowName);
}


function getKeyNameInternal(currentApplication, s) {
var rval;
var activeFormName;
var windowName=currentApplication.currentWindow.A4GL_name;
if (currentApplication.currentWindow && currentApplication.currentWindow.activeForm) { activeFormName=currentApplication.currentWindow.activeForm.A4GL_name; }
rval=getKeyName(s, activeFormName,windowName);
if (rval) return rval;

switch (s) {
		case "6": return "^F";
		case "25": return "^Y";
		case "2000": return "DOWN";
		case "2001": return "UP";
		case "2002": return "LEFT";
		case "2003": return "RIGHT";

		case "3000": return "F1";
		case "3001": return "F2";
		case "3002": return "F3";
		case "3003": return "F4";
		case "3004": return "F5";
		case "3005": return "F6";
		case "3006": return "F7";
		case "3007": return "F8";
		case "3008": return "F9";
		case "3009": return "F10";
		case "3010": return "F11";
		case "3011": return "F12";
}
return s;
}


function getKeyDescriptionInternal(currentApplication, s) {
var activeFormName;
var windowName=currentApplication.currentWindow.A4GL_name;
if (currentApplication.currentWindow && currentApplication.currentWindow.activeForm) { activeFormName=currentApplication.currentWindow.activeForm.A4GL_name; }
rval=getKeyDescription(s, activeFormName,windowName);


if (rval) return rval;

switch (s) {
		case "6": return "^F";
		case "25": return "^Y";
		case "2000": return "DOWN";
		case "2001": return "UP";
		case "2002": return "LEFT";
		case "2003": return "RIGHT";

		case "3000": return "F1";
		case "3001": return "F2";
		case "3002": return "F3";
		case "3003": return "F4";
		case "3004": return "F5";
		case "3005": return "F6";
		case "3006": return "F7";
		case "3007": return "F8";
		case "3008": return "F9";
		case "3009": return "F10";
		case "3010": return "F11";
		case "3011": return "F12";
}
return s;
}


function generateToolbar(context, events, callback) {
    var pan;

    // items should be populated with ON KEY
    // and ON ACTION commands from 'events'
    var items=[];
    var tailitems= [
			//'->',
			{
				iconCls:"icon-ok",
				text: "OK",
				qtip: "Accept",
				tooltip: "Accept",
				formBind:true,
				handler: function() {
					callback("ACCEPT","ACCEPT");
				}
			},
			{
				iconCls:"icon-cancel",
				text: "Cancel",
				qtip: "Cancel",
				tooltip: "Cancel",
				handler: function() {
					callback("INTERRUPT","INTERRUPT");
				}
			}
		];


	var a;
	if (events && events.ONKEY_EVENT && events.ONKEY_EVENT.length) {
		// 
		// Need to add toolbar items for ON KEY stuff...
		//
		for  (a=0;a<events.ONKEY_EVENT.length;a++) {
			var evt=events.ONKEY_EVENT[a];
			evt.context=context;
			evt.callback=callback;
					var itm= {
						iconCls: getIconClassInternal(context.activeApplication, evt.KEY.trim()),
                                		text: getKeyNameInternal(context.activeApplication, evt.KEY.trim()),
                                		qtip: getKeyDescriptionInternal(context.activeApplication, evt.KEY.trim()),
                                		tooltip: getKeyDescriptionInternal(context.activeApplication, evt.KEY.trim()),
                                		handler: onKeyHandler,
						scope: evt
                                	}
					items.push(itm);
					break;

		}
	}
	items=items.concat(tailitems);


	// Hide anything with a "hide" for the iconCls..
	var a;
	for(a=0;a<items.length;a++) {
		if (items[a].iconCls=="hide" || items[a].iconCls=="hidden") {
			items[a].hidden=true;
		}
	}

        pan= Ext.create('Ext.toolbar.Toolbar', {
    		A4GL_Context: context,
		originalEvents: events,
        	flex:1,
		items: items,
		//height:90,
		//minWidth:100,

	});

	return pan;
}


