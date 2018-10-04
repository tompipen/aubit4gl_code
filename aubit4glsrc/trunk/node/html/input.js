

function createInput(currentApplication, d)  {

var input;


var toolbar;


var flds=findFields(currentApplication, d.fieldlist);
var a;


// @todo to defaults ? 
for (a=0;a<flds.length;a++) {
	flds[a].setFormFieldValue(flds[a], "");
}

input={
	first:true,
	active:false,
	activeWindow: currentApplication.currentWindow,
        activeApplication: currentApplication,
 	contextType:  AubitDesktop.FGLContextType.contextInput,
	OriginalFields:d.fieldlist,
	Fields: flds,
	events: d.events,
        beforeField: function(eventId) {
                input.action(eventId,"BeforeField");
        },
        afterField: function(eventId) {
                input.action(eventId,"AfterField");
        },

        getLastFocusFieldName:function() {
              if (input.lastFocusField) {
                        return input.lastFocusField.A4GL_fullname;
              }
              return null;
        },

	getSyncValues: function() {
		var syncValues = {
	        	SVS:[
			]
		};
		var a;
		for (a=0;a<input.Fields.length;a++) {
			var fldVal=input.Fields[a].getFormFieldValue(input.Fields[a]);
				var itm={
					FN:    input.Fields[a].A4GL_colname,
					Value: fldVal,
					FT:    input.Fields[a].A4GL_sqlType,
					T:     input.Fields[a].isTouched(input.Fields[a])
				};
				syncValues.SVS.push(itm);
		}
		return syncValues;
	},
	action: function(toolbarActionId, eventType) {
		switch (eventType) {

			case "INTERRUPT":
				var val={ID:"INTERRUPT"};
				input.ContextDeactivate();
				currentApplication.sendResponse(val,  input.activeApplication);
				break;

			// Need to get field values for these 
			// too..
			case "ACCEPT":
				var val={
						ID:"ACCEPT",
						INFIELD: input.getLastFocusFieldName()
					};
				Ext.apply(val, input.getSyncValues());
				// @todo - Check isFormFieldValid
				input.ContextDeactivate();
				console.dir(val);
				currentApplication.sendResponse(val, input.activeApplication);
				break;

			default:
				var val={ID:toolbarActionId,
					INFIELD: input.getLastFocusFieldName()
				};
				Ext.apply(val, input.getSyncValues());
				input.ContextDeactivate();
				currentApplication.sendResponse(val, input.activeApplication);
				break;
				
		}
	},
	ContextActivate: function(d) {
		console.log("Input : ContextActivate");
		input.active=true;
		input.activeWindow.ensureCurrent();
		input.activeWindow.setMenu(toolbar);
		toolbar.enable();
		toolbar.setVisible(true);
		var a;
		if (d.vs) { 
			var values=d.vs[0].V;
			if (values && values.length && d.changed) {
				for (a=0;a<flds.length;a++) {
					if (values[a] && values[a].CHANGED) {
        					flds[a].setFormFieldValue(flds[a], values[a].Data);
					}
				}
			}
		}

		enableActiveFields(currentApplication, input.Fields, input);


		if (input.first) {
			console.log("Input : first");
    			if (input.Fields && input.Fields.length>0) {
				console.log("Fields : "+input.Fields.length);
				var a;
				for (a=0;a<input.Fields.length;a++) {
					if (input.Fields[a].currentContext && input.Fields[a].fldIsEnabled && !(input.Fields[a].readOnly || input.Fields[a].disabled)) {
						console.log("Setting focus ...");
						
						input.Fields[a].focus(false, 10);
						break;
					}
				}
    			}
		}
		input.first=false;

	},
	ContextDeactivate: function() {
		input.active=false;
		toolbar.setVisible(false);
		disableAllFields(currentApplication);
	},
	ContextFree: function() {
		if (input.active) {
			input.ContextDeactivate();
		}
		delete currentApplication.Contexts["C"+d.context];
		input.activeWindow.removeMenu(toolbar);
	}
    };


    toolbar= generateToolbar(input, d.events[0], function(toolbarActionId, eventType) {
	input.action(toolbarActionId, eventType);
    }) ;

    //currentWindow.setMenu(pan);
    currentApplication.Contexts["C"+d.context]=input;
}


