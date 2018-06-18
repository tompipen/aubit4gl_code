function displayArrayDblClickHandler(displayArray) {
this.action("ACCEPT","ACCEPT");
}

function createDisplayArray(currentApplication, d)  {

var displayArray;


var toolbar;


var tab=findTable(currentApplication, d.fieldlist[0].FIELD[0]);
var a;
var rowData=[];
for (a=0;a<d.rows[0].ROW.length;a++) {
	// The last one is normally null so we dont need to worry about "," in the json object
	if (d.rows[0].ROW[a]==null) continue;
    var f=tab.store.createNewRow(d.rows[0].ROW[a]);
    rowData.push(f);
}

tab.store.loadData(rowData,false);

displayArray={
	first:true,
	active:false,
 	contextType:  AubitDesktop.FGLContextType.contextDisplayArray,
	activeWindow: currentApplication.currentWindow,
        activeApplication: currentApplication,
	Table: tab,
	action: function(toolbarActionId, eventType) {
		switch (eventType) {

			case "INTERRUPT":
				var val={ID:"INTERRUPT"};
				displayArray.ContextDeactivate();
				currentApplication.sendResponse(val, displayArray.activeApplication);
				break;

			case "ACCEPT":
				var val={ ID:"ACCEPT" };
				var x=tab.getSelectionModel().getSelection();
				if (x && x.length) {
					var r=tab.store.indexOf(x[0]);
					Ext.apply(val, {
								"ARRLINE":r,
								"SCRLINE":r
						});
				}

				displayArray.ContextDeactivate();
				console.dir(val);
				currentApplication.sendResponse(val, displayArray.activeApplication);
				break;

			default:
				var val={ID:toolbarActionId };
				Ext.apply(val, displayArray.getSyncValues());
				displayArray.ContextDeactivate();
				currentApplication.sendResponse(val, displayArray.activeApplication);
				break;
				
		}
	},
	ContextActivate: function() {
		console.log("Input : ContextActivate");
		displayArray.active=true;
		displayArray.activeWindow.ensureCurrent();
		displayArray.activeWindow.setMenu(toolbar);
		toolbar.enable();
		toolbar.setVisible(true);
		tab.setDisabled(false);
		tab.on('celldblclick', displayArrayDblClickHandler, displayArray);

		//enableTable(....
	},
	ContextDeactivate: function() {
		displayArray.active=false;
		tab.setDisabled(true);
		toolbar.setVisible(false);
		tab.un('celldblclick', displayArrayDblClickHandler, displayArray);
		disableAllFields(currentApplication);
	},
	ContextFree: function() {
		if (displayArray.active) {
			displayArray.ContextDeactivate();
		}
		delete currentApplication.Contexts["C"+d.context];
		displayArray.activeWindow.removeMenu(toolbar);
	}
    };


    toolbar= generateToolbar(displayArray, d.events[0], function(toolbarActionId, eventType) {
	displayArray.action(toolbarActionId, eventType);
    }) ;

    //currentWindow.setMenu(pan);
    currentApplication.Contexts["C"+d.context]=displayArray;
}


