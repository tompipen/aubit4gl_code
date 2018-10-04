function displayArrayDblClickHandler( grid, td, cellIndex, record, tr, rowIndex, e, eOpts ) {
	this.action("ACCEPT","ACCEPT");
}

function displayArrayClickHandler( grid, td, cellIndex, record, tr, rowIndex, e, eOpts ) {
var evt;
var lst=[];
if (this.lastRowIndex>=0) {
	if (this.events[0]["AFTER_ROW_EVENT"]) {
			evt=this.events[0]["AFTER_ROW_EVENT"];
			Ext.Array.each(evt, function(x) {
					var val={ID: x.ID};
                                        Ext.apply(val, {
                                            "ARRLINE":this.lastRowIndex,
                                            "SCRLINE":this.lastRowIndex
                                        });
					lst.push(val);
			});
	}
}

if (this.events[0]["BEFORE_ROW_EVENT"]) {
		evt=this.events[0]["BEFORE_ROW_EVENT"];
		Ext.Array.each(evt, function(x) {
				var val={ID: x.ID};
                                       Ext.apply(val, {
                                           "ARRLINE":rowIndex,
                                           "SCRLINE":rowIndex
                                       });
				lst.push(val);
		});
}

this.lastRowIndex=rowIndex;
this.sendResponse(lst);


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
	events: d.events,
 	contextType:  AubitDesktop.FGLContextType.contextDisplayArray,
	activeWindow: currentApplication.currentWindow,
        activeApplication: currentApplication,
	Table: tab,
	lastRowIndex:-1,
	sendResponse: function(val) {
		currentApplication.sendResponse(val, displayArray.activeApplication);
	},
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
		tab.on('cellclick', displayArrayClickHandler, displayArray);

		//enableTable(....
	},
	ContextDeactivate: function() {
		displayArray.active=false;
		tab.setDisabled(true);
		toolbar.setVisible(false);
		tab.un('celldblclick', displayArrayDblClickHandler, displayArray);
		tab.un('cellclick', displayArrayClickHandler, displayArray);
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


