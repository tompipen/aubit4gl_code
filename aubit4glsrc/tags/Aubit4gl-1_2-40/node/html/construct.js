

function createConstruct(currentApplication, d)  {

var construct;


var toolbar;


var flds=findFields(currentApplication, d.Fields);
var a;

for (a=0;a<flds.length;a++) {
	flds[a].setFormFieldValue(flds[a], "");
}

construct={
	first:true,
	active:false,
	contextType:  AubitDesktop.FGLContextType.contextConstruct,
	activeWindow: currentApplication.currentWindow,
	activeApplication: currentApplication,
	OriginalFields:d.Fields,
	Columns:d.Columns,
	Fields: flds,
	getLastFocusFieldName:function() {
              if (construct.lastFocusField) {
                        return construct.lastFocusField.A4GL_fullname;
              }
              return null;
        },
	getSyncValues: function() {
		var syncValues = {
	        	SVS:[
			]
		};
		var a;
		for (a=0;a<construct.Fields.length;a++) {
			var fldVal=construct.Fields[a].getFormFieldValue(construct.Fields[a]);
				var itm={
					FN:    construct.Fields[a].A4GL_colname,
					Value: fldVal,
					FT:    construct.Fields[a].A4GL_sqlType,
					T:     construct.Fields[a].isTouched(construct.Fields[a])
				};
				syncValues.SVS.push(itm);
		}
		return syncValues;
	},
	action: function(toolbarActionId, eventType) {
		switch (eventType) {

			case "INTERRUPT":
				var val={ID:"INTERRUPT"};
				construct.ContextDeactivate();
				sendResponse(val,  construct.activeApplication);
				break;

			// Need to get field values for these 
			// too..
			case "ACCEPT":
				var val={
					ID:"ACCEPT", 
				 	INFIELD: construct.getLastFocusFieldName()
				};

				if (!fieldsValid(construct.Fields,"CONSTRUCT")) {
					Ext.MessageBox.alert("Some fields are invalid!");
					return;
				}

				Ext.apply(val, construct.getSyncValues());
				// @todo - Check isFormFieldValid
				construct.ContextDeactivate();
				console.dir(val);
				sendResponse(val,  construct.activeApplication);
				break;

			default:
				var val={
					ID:toolbarActionId,
			 		INFIELD: construct.getLastFocusFieldName()
				};

				Ext.apply(val, construct.getSyncValues());
				construct.ContextDeactivate();
				sendResponse(val, construct.activeApplication);
				break;
				
		}
	},
	ContextActivate: function() {
		console.log("Construct : ContextActivate");
		construct.active=true;
		construct.activeWindow.ensureCurrent();
		construct.activeWindow.setMenu(toolbar);
		toolbar.enable();
		toolbar.setVisible(true);
		enableActiveFields(currentApplication, construct.Fields, construct);


		if (construct.first) {
			console.log("Construct : first");
    			if (construct.Fields && construct.Fields.length>0) {
				console.log("Fields : "+construct.Fields.length);
				var a;
				for (a=0;a<construct.Fields.length;a++) {
					if (construct.Fields[a].A4GL_noentry===false) {
						console.log("Setting focus ...");
						
						construct.Fields[a].focus(false, 10);
						break;
					}
				}
    			}
		}
		construct.first=false;

	},
	ContextDeactivate: function() {
		construct.active=false;
		toolbar.setVisible(false);
		disableAllFields(currentApplication);
	},
	ContextFree: function() {
		if (construct.active) {
			construct.ContextDeactivate();
		}
		delete currentApplication.Contexts["C"+d.CONTEXT];
		construct.activeWindow.removeMenu(toolbar);
	}
    };

    toolbar= generateToolbar(construct, d.Events, function(toolbarActionId, eventType) {
	construct.action(toolbarActionId, eventType);
    }) ;

    currentApplication.Contexts["C"+d.CONTEXT]=construct;
}


