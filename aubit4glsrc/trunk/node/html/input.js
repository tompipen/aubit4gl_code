

function createInput(currentApplication, d)  {

var input;


var toolbar;


var flds=findFields(currentApplication, d.Fields);
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
	OriginalFields:d.Fields,
	Fields: flds,
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
				sendResponse(val,  input.activeApplication);
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
				sendResponse(val, input.activeApplication);
				break;

			default:
				var val={ID:toolbarActionId,
					INFIELD: input.getLastFocusFieldName()
				};
				Ext.apply(val, input.getSyncValues());
				input.ContextDeactivate();
				sendResponse(val, input.activeApplication);
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
		if (d.Values && d.Values.length && d.CHANGED) {
			for (a=0;a<flds.length;a++) {
				if (d.Values[a] && d.Values[a].Changed) {
        				flds[a].setFormFieldValue(flds[a], d.Values[a].Data);
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
					if (input.Fields[a].A4GL_noentry===false) {
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
		delete currentApplication.Contexts["C"+d.CONTEXT];
		input.activeWindow.removeMenu(toolbar);
	}
    };


    toolbar= generateToolbar(input, d.Events, function(toolbarActionId, eventType) {
	input.action(toolbarActionId, eventType);
    }) ;

    //currentWindow.setMenu(pan);
    currentApplication.Contexts["C"+d.CONTEXT]=input;
}


