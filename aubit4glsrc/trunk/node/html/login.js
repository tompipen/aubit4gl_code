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
					value:'mike',
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
					xtype:'combo',
                			fieldLabel:'Program', 
                			itemId:'loginProgram', 
                			name:'loginProgram', 
					store: [
						'ge_query',
						'fgldemo/fgldemo',
						'fgldemo/hideShowMenu',
						'fgldemo/dArrTest',
						'fgldemo/window'
					],
					value:'ge_query',
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

