function showLoginWindow(LoginCallback, CancelCallback) {

var win=Ext.create('Ext.window.Window', {
    title: 'Login',
    minHeight: 100,
    minWidth: 200,
    layout: 'fit',
    items: [
		{xtype:'form',
			bodyPadding:6,
			items:[
				{
					xtype:'textfield',
                			fieldLabel:'Username', 
                			itemId:'loginUsername', 
					value:'aubit4gl',
                			name:'loginUsername', 
                			allowBlank:false 
            			},
				{ 
					xtype:'textfield',
                			fieldLabel:'Password', 
                			itemId:'loginPassword', 
                			name:'loginPassword', 
                			inputType:'password', 
					value:"aubit4gl",
                			allowBlank:false 
          			},
				{
					xtype:'textfield',
                			fieldLabel:'Program', 
                			itemId:'loginProgram', 
                			name:'loginProgram', 
					value:'fgldemo/fgldemo',
                			allowBlank:false 
            			},
		]}
	
	] ,

    buttons:[
		{ 
			text:'Login',
			handler:function () {
				if (LoginCallback(
					win.down("#loginUsername").value,
					win.down("#loginPassword").value ,
					win.down("#loginProgram").value 
				))  {
					win.close();
				}
			}
		},
		{ 
			text:'Cancel',
			handler:function () {
				win.close();
				CancelCallback();
			}
		},
	]
	});

	win.show();

}

