function createWindow(currentApplication, d, frm) {
var fullScreen=false;

if (frm) {
	d.NAME=d.WINDOW;
}

if (d==null) {
	d={ 
		NAME:'screen',
		H:25,
		W:80
	};
}



var menuLine=Ext.widget("toolbar",{dock:'top', hidden:false, flex:1,height:60 }  );


var tbMsg=Ext.widget('tbtext', {cls:'msg',  text:''});
var messageLine=Ext.widget("toolbar",{dock:'bottom', items:[tbMsg],flex:1});


var tbErr=Ext.widget('tbtext', { cls:'error', text:'!', });
var errorLine=Ext.widget("toolbar",{dock:'bottom', items:[tbErr], hidden:true, flex:1});


var formArea;
if (frm)  {
	formArea=Ext.widget('container', 
		{cls:'formArea', layout:'fit' , items : [ frm ]});
} else {
	formArea=Ext.widget('container', {cls:'formArea', layout:'fit' });
}


//
// 4GL windows are probably more like panels than windows
// but - we'll try this for now so they are movable
// 
var win;
var cfg={
	modal:true,
	closable:false,
	layout:'fit',

	dockedItems : [
		 menuLine,
		 errorLine,
		 messageLine
	],

	items : [
		formArea
	],
	activeForm: null,
	setActiveForm: function (frm) {
		win.activeForm=frm;
		var hasForm=false;
		
		for (a=0;a<formArea.items.items.length;a++) {
			if (formArea.items.items[a]!=frm) {
				var olderForm= formArea.items.items[a];
				formArea.items.removeAt(a);
				//olderForm.setVisible(false);
			} else {
				hasForm=true;
			}
		}
		

		if (!hasForm) {
			formArea.add(frm);
		}

		//if (formArea.items.items.length>0) {
			//formArea.setVisible(true);
		//}
	},

	listeners: {
		show: function() {
			if (this.y<0) {
				this.setPosition(this.x,10);
			}
		}
	},

	ensureCurrent: function() {
		if (currentApplication.currentWindow!=d.NAME) {
			win.makeCurrent(d.NAME);
		}
	},
	makeCurrent: function() {
		var winName=d.NAME;
		console.log("Current window is " + winName);
		if (currentApplication.windows[winName]!=null) {
		
			currentApplication.windows[winName].show();
			if (currentApplication.windows[winName].rendered) {
				if (winName=="screen") {
					//...
				} else {
					currentApplication.windows[winName].toFront();
				}
			}
			currentApplication.currentWindow=currentApplication.windows[winName];
		}

		// Make sure this window is at the top of our stack...
		var idx=currentApplication.windowsStack.indexOf(winName);
		if (idx!=-1) {
			delete currentApplication.windowsStack[idx];
			currentApplication.windowsStack.unshift(winName);
		}
	},
	closeWindow: function() {
		var winName=d.NAME;
		console.log("remove window " + winName);

		if (currentApplication.windows[winName]!=null) {
			currentApplication.windows[winName].close();
		}

		currentApplication.windows[winName]=null;
		
		var idx=currentApplication.windowsStack.indexOf(winName);
		if (idx!=-1) {
			delete currentApplication.windowsStack[idx];
		}
	},
	setMenu: function(menuPanel) {
		// Add a menuPanel to our list of menus
		// if it not already there..
		// We could optionally hide all current menus
		// or leave them visible for some 'history'..
		var hasMenu=false;
		for (a=0;a<menuLine.items.items.length;a++) {
			if (menuLine.items.items[a]!=menuPanel) {
				var olderMenu= menuLine.items.items[a];
				olderMenu.setVisible(false);
			} else {
				hasMenu=true;
			}
		}

		if (!hasMenu) {
			menuLine.add(menuPanel);
		}

		if (menuLine.items.items.length>0) {
			menuLine.setVisible(true);
		}
	},
	clearError:function() {
		win.setError(null);
	},
	setError:function(text) {
		if (text==null) {
			errorLine.setVisible(false);
		} else {
			tbErr.setText(text);
			if (text.length==0) {
				errorLine.setVisible(false);
			} else {
				errorLine.setVisible(true);
			}
		}
	},
	removeMenu: function(menuPanel) {
		var idx=menuLine.items.items.indexOf(menuPanel);
		var rval=menuLine.items.remove(menuPanel);
		console.log("rval="+rval);

		if (menuLine.items.items.length==0) {
			menuLine.setVisible(false);
		}
	},
	setMessage:function(text) {
		tbMsg.setText(text);
		if (text.length==0) {
			messageLine.setVisible(false);
		} else {
			messageLine.setVisible(true);
		}
	}
};



if (d.X) {
	cfg.x=d.X*xMultiplier;
	cfg.y=d.Y*yMultiplier;
}


if (d.BORDER) {
	cfg.cls="BorderWindow "+d.NAME;
} else {
	cfg.cls="BorderlessWindow "+d.NAME;
}

if (d.TEXT) {
	cfg.text=d.TEXT;
}

if (d.STYLE) {
	cfg.cls= d.STYLE
}

if (d.NAME=='screen' && !fullScreen) {
	cfg.constrain=true;
	cfg.renderTo='DivPanel';
	//cfg.closable=true;
	cfg.maximizable=true;
	//cfg.minimizable=true;
	cfg.collapsible=true;

}


if (fullScreen) {
   Ext.apply(cfg,{
	flex:1, 
	renderTo:'DivPanel',
	minHeight:600,
	//autoScroll:true,
	//title:'blah',
	layout:'fit'
	
	});
   win= Ext.widget("panel", cfg);
} else {
   if (!frm) {
   	Ext.apply(cfg,{
		height: d.H*yMultiplier,
		width: d.W*xMultiplier,
   	});
   } else {
   	Ext.apply(cfg,{
		layout: 'fit'
   	});
   }
   win= Ext.create("Ext.window.Window", cfg);
	win.doLayout();
}

console.log("height : " + cfg.height);
console.log("width  : " + cfg.width);

win.A4GL_name=d.NAME;
win.activeApplication=currentApplication;
currentApplication.windows[d.NAME]=win;
currentApplication.windowsStack.unshift(d.NAME);
currentApplication.currentWindow=win;
return win;
}









