function createPrompt(currentApplication, d) {
  var win;
  var dtype=d.DTYPE_HINT&0xffff;
  var dtype_sz=d.DTYPE_HINT>>16;
  var prmpt={ 
		activeApplication: currentApplication,
		ContextActivate: function() {
		cfg={
                                cls: "PROMPT"+d.FIELDATTRIBUTE.trim(),
                                listeners: {
                                        specialkey: function(field, e) {
                                                if (e.getKey()==e.ENTER) {
                                                        win.OK();
                                                }
                                                if (e.getKey()==e.ESC) {
                                                        win.Cancel();
                                                }
                                        }
                                }
		}


		// Restrict to the length of the string..
		// we can extend this later for vtypes for datatypes..
		if (dtype==0 && dtype_sz) {
			cfg.enforceMaxLength=true;
			cfg.maxLength=dtype_sz
		}

		var tField=Ext.widget('textfield',  cfg );


		win=Ext.create('Ext.window.Window', {
			modal:true,
			title:d.TEXT,
			cls: "PROMPT"+d.PROMPTATTRIBUTE.trim(),
			minWidth:200,
			closable:false,
	    		layout: 'fit',
    			items: [ tField ],
			OK: function() {
				var val={ID:"ACCEPT", SVS:[{ "Value":tField.getValue() }]};
                         	sendResponse(val,  prmpt.activeApplication);
				win.close();
			},
			Cancel: function() {
			        var val={ID:"INTERRUPT",  SVS:[{ "Value":"" }]};
                         	sendResponse(val, prmpt.activeApplication);
				win.close();
			},
			listeners: {
				close: function() {
					console.log("close prompt");
				}
			},
		        buttons:[ 
				{ text:'Ok', handler:function() { win.OK(); }},
				{ text:'Cancel', handler: function() { win.Cancel(); } }

			]
                }
		);
		win.show();

			/*
			Ext.Msg.prompt('Name', 'Please enter your name:', function(btn, text){
    				if (btn == 'ok'){ 
var val={ID:"ACCEPT", SVS:[{ "Value":text }]};
                                		sendResponse(val);
                		} else {
					        var val={ID:"INTERRUPT"};
                                		sendResponse(val);
				}
        		});
			*/
		},
		ContextDeactivate: function() {
			// Do nothing
		},
		ContextFree: function() {
			if (win) {
				win.close();
				win=null
			}
		}
		
	}

    currentApplication.Contexts["C"+d.CONTEXT]=prmpt

}
	
