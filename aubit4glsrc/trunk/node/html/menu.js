function createMenu(currentApplication, d) {

  var itms=[];
  var pan;
  var menu;

var menucommands;
	
menucommands=Aubit4GL.client.convertToType(d.menucommands[0].MENUCOMMAND,"MENUCOMMAND");
menucommands=Ext.Array.merge(menucommands, Aubit4GL.client.convertToType(d.menucommands[0].MENUACTION,"MENUACTION"));


  Ext.Array.each(menucommands, function(v) { 
	if (v==null) return;
	var item;

	if (v.ACTION) {
		if (v.ACTION=="fgl_exit_menu")  {
			return;
		}

		item={      
				iconCls: getIconClassInternal(currentApplication, v.ACTION),
				tooltip: v.DESCRIPTION,
				A4GL_ID: v.ID,
				A4GL_ACTION: v.ACTION,
				handler: function() {
					var val={ID:this.A4GL_ID};
					currentApplication.sendResponse(val, pan.activeApplication);
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
					currentApplication.sendResponse(val,  pan.activeApplication);
					pan.ContextDeactivate();
				}
	
			};
			if (v.TEXT=="") {
				item.hidden=true;
			}
	}

	itms.push(item);
  });

 

  menu = Ext.create('Ext.toolbar.Toolbar', {
    			activeWindow: currentApplication.currentWindow,
			//activeApplication: currentApplication,
			//icon:d.IMAGE,
			//title:d.TITLE,
			layout:menuPosition=="right"?'vbox':'hbox',
//resizable:true,

			A4GLContext: d.context,
			items : itms
			
  });


  pan=Ext.create('Ext.panel.Panel', {
    title: d.title,
    activeApplication: currentApplication,
	events: d.events,
    A4GL_Context: d.context,
	flex:1,
    //minWidth: 800,
    //closable:false,
    //layout: 'fit',
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
		delete currentApplication.Contexts["C"+d.context];
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

    currentApplication.Contexts["C"+d.context]=pan;
}


