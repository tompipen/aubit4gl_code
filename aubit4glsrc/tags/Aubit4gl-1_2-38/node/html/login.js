function showLoginWindow(LoginCallback, CancelCallback) {

var win=Ext.create('Ext.window.Window', {
    title: 'Login',
    minHeight: 100,
    minWidth: 200,
    layout: 'fit',
    items: [
		{xtype:'form',items:[
				{
					xtype:'textfield',
                			fieldLabel:'Username', 
                			itemId:'loginUsername', 
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
          			}
		]}
	
	] ,

    buttons:[
		{ 
			text:'Login',
			handler:function () {
				if (LoginCallback(
					win.down("#loginUsername").value,
					win.down("#loginPassword").value 
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

