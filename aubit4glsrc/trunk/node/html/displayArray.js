function displayArrayDblClickHandler(displayArray) {
this.action("ACCEPT","ACCEPT");
}

function createDisplayArray(currentApplication, d)  {

var displayArray;


var toolbar;


var tab=findTable(currentApplication, d.Fields[0]);
var a;
var rowData=[];
for (a=0;a<d.Rows.length;a++) {
	// The last one is normally null so we dont need to worry about "," in the json object
	if (d.Rows[a]==null) continue;
    var f=tab.store.createNewRow(d.Rows[a].Data);
    rowData.push(f);
}

tab.store.loadData(rowData,false);

displayArray={
	first:true,
	active:false,
	activeWindow: currentApplication.currentWindow,
        activeApplication: currentApplication,
	Table: tab,
	action: function(toolbarActionId, eventType) {
		switch (eventType) {

			case "INTERRUPT":
				var val={ID:"INTERRUPT"};
				displayArray.ContextDeactivate();
				sendResponse(val, displayArray.activeApplication);
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
				sendResponse(val, displayArray.activeApplication);
				break;

			default:
				var val={ID:toolbarActionId };
				Ext.apply(val, displayArray.getSyncValues());
				displayArray.ContextDeactivate();
				sendResponse(val, displayArray.activeApplication);
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
		delete currentApplication.Contexts["C"+d.CONTEXT];
		displayArray.activeWindow.removeMenu(toolbar);
	}
    };


    toolbar= generateToolbar(displayArray, d.Events, function(toolbarActionId, eventType) {
	displayArray.action(toolbarActionId, eventType);
    }) ;

    //currentWindow.setMenu(pan);
    currentApplication.Contexts["C"+d.CONTEXT]=displayArray;
}


