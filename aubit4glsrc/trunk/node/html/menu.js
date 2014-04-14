function createMenu(currentApplication, d) {

  var itms=[];
  var pan;
  var menu;

  for (var vv=0;vv<d.MenuCommands.length;vv++) {

	var v=d.MenuCommands[vv];

	if (v==null) continue;

	if (vv==null) {
	 continue; 
	}


	var item;

	if (v.ACTION) {
		if (v.ACTION=="fgl_exit_menu")  {
			continue;
		}

		item={      
				iconCls: getIconClassInternal(currentApplication, v.ACTION),
				tooltip: v.DESCRIPTION,
				A4GL_ID: v.ID,
				A4GL_ACTION: v.ACTION,
				handler: function() {
					var val={ID:this.A4GL_ID};
					sendResponse(val, pan.activeApplication);
					pan.ContextDeactivate();
				}
	
			};
	} else {
		item={      
				iconCls: getIconClassInternal(currentApplication, v.TEXT),
				text: v.TEXT,
				A4GL_option: v.TEXT,
				qtip: v.DESCRIPTION,
				tooltip: v.DESCRIPTION,
				A4GL_ID: v.ID,
				A4GL_ACTION: v.ACTION,
				handler: function() {
					var val={ID:this.A4GL_ID};
					sendResponse(val,  pan.activeApplication);
					pan.ContextDeactivate();
				}
	
			};
			if (v.TEXT=="") {
				item.hidden=true;
			}
	}

	itms.push(item);
  }

 

  menu = Ext.create('Ext.toolbar.Toolbar', {
    			activeWindow: currentApplication.currentWindow,
			//activeApplication: currentApplication,
			//icon:d.IMAGE,
			//title:d.TITLE,
			A4GLContext: d.CONTEXT,
			items : itms
			
  });


  pan=Ext.create('Ext.panel.Panel', {
    title: d.TITLE,
    activeApplication: currentApplication,
    A4GL_Context: d.CONTEXT,
	flex:1,
    //minWidth: 800,
    //closable:false,
    layout: 'fit',
	//anchor: '100% 100%'
	ContextActivate: function() {
		menu.activeWindow.ensureCurrent();
    		menu.activeWindow.setMenu(pan);

		if (!pan.visible) {
			pan.show();
		}
		menu.enable();
	},
	ContextDeactivate: function() {
		menu.disable();
	},
	ContextFree: function() {
		pan.setVisible(false);
		//pan.close();
		menu.activeWindow.removeMenu(pan);
		delete currentApplication.Contexts["C"+d.CONTEXT];
		pan=null;
	},
	showOption: function(opt) {
		var opts;
		if (opt=="_AlL_") {
			opts=pan.query("[A4GL_option]");
		} else {
			opts=pan.query("[A4GL_option="+opt+"]");
		}
		// _AlL_
		if (opts) {
			for (a=0;a<opts.length;a++) {
				opts[a].setVisible(true);
			}
		}
	},
	hideOption: function(opt) {
		var opts;
		if (opt=="_AlL_") {
			opts=pan.query("[A4GL_option]");
		} else {
			opts=pan.query("[A4GL_option="+opt+"]");
		}
		if (opts) {
			for (a=0;a<opts.length;a++) {
				opts[a].setVisible(false);
			}
		}
	},
        items: 
		[ 
			menu
		]
    });

    currentApplication.Contexts["C"+d.CONTEXT]=pan;
}


