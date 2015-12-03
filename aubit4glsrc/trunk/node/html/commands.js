function optionsDecode(s) {

	switch (s) {
		case "C": return "CommentLine";
		case "E": return "ErrorLine";
		case "F": return "FormLine";
		case "M": return "MenuLine";
		case "m": return "MessageLine";
		case "P": return "PromptLine";
		case "A": return "AcceptKey";
		case "D": return "DeleteKey";
		case "I": return "InsertKey";
		case "N": return "NextKey";
		case "p": return "PreviousKey";
		case "H": return "HelpKey";
		case "Z": return "DisplayAttrFormWin";
		case "Y": return "InputAttrFormWin";
		case "W": return "InputWrap";
		case "f": return "FieldOrderConstrained";
	}

	return s;
}


function processCommand(currentApplication, d) {
if (d==null) return;

console.log("Process : " + d.type);

switch (d.type) {
	case "DISPLAYAT": 
		console.log("DISPLAYAT:" + d.Data);
		return ;

	case "DISPLAY":
		console.log(d.Data);
		return;

 	case "ERROR":
		if (!currentApplication.currentWindow) {
		Ext.Msg.show({
   			title:'Error',
			closable:true,
			modal:true,
   			msg: d.Data,
			buttons:Ext.window.MessageBox.OK
		});
		} else {
			currentApplication.currentWindow.setError(d.Data);
		}
		return;

 	case "MESSAGE":
		if (!currentApplication.currentWindow) {
		Ext.MessageBox.show({
   			title: 'Message',
   			msg: d.Data,
			modal:true,
			buttons:Ext.window.MessageBox.OK
			});
		} else {
			currentApplication.currentWindow.setMessage(d.Data);
		}
		return;


	case "PROMPT":
		createPrompt(currentApplication, d);
		return;

	case "CONSTRUCT":
		createConstruct(currentApplication, d);
		return;

	case "INPUT":
		createInput(currentApplication, d);
		return;

	case "DISPLAYARRAY": 
		createDisplayArray(currentApplication,d);
		return;
  
	case "FREE":
		var context=d.CONTEXT;
		var c=currentApplication.Contexts["C"+context];
		if (!c) {
			console.log("FREE No context "+d.CONTEXT);
			alert("FREE No context"+d.CONTEXT);
			return;
		}

		if (c.ContextFree) {
			c.ContextFree(d);
		}
		currentApplication.Contexts["C"+context]=null;
		break;


	case "MENU":
		createMenu(currentApplication, d);
		return;


	case "WAITFOREVENT":
		var context=d.CONTEXT;
		var c=currentApplication.Contexts["C"+context];
		if (!c) {
			console.log("WAITFOREVENT No context"+d.CONTEXT);
			alert("WAITFOREVENT No context"+d.CONTEXT);
			return;
		}
		if (c.ContextActivate) {
			c.ContextActivate(d);
		}
		console.log("Now - wait for event ..");
		console.dir(c);
		break;



	case "PROGRAMSTOP": 
		Ext.Msg.alert( "Program stopped - edit code : " +d.EXITCODE, d.Data.join("<br>"));
		socket.disconnect();
		break;

	case "PROGRAMSTARTUP":
               //PROGRAMSTARTUP=d;
		//var app=createApplication(d);
		//applications.push(app);
		//currentApplication=app;
		//applicationsByPid[d.PID]=app;
		currentApplication.programStartup(d);
		var screen=createWindow(currentApplication, null);
		if (false) { // Doing full screen ...
                	document.title=d.ProgramName;
			screen.show();
		} else {
			screen.setTitle(d.ProgramName);
			screen.show();
		}
		console.log("Shown 'screen'");
		 //

	break;

	case "OPTIONS" :
			currentApplication.options[optionsDecode(d.option)]=d.value;
			break;




	case "OPENFORM":
		if (d.Form && d.Form.Data) {
			var frm=createForm(d.Form.Data);

			currentApplication.Forms[d.FORMNAME]={
				source: d.SOURCE,
				form: frm
			}
		}
		break;

	case "CURRENTWINDOW":
		var cwin=d.WINDOW;
		var cw_win=currentApplication.windows[cwin];

		if (cw_win) {
			cw_win.ensureCurrent();
		}
		break;


	case "CLEARWINDOW":
		var cwin=d.WINDOW;
		console.log("@Fixme - clear window " +cwin);
		break;

		

	case "CLEARFORM": 
		clearForm(currentApplication, d.TODEFAULTS);
		console.log("@Fixme - clear form");
		break;

	case "DRAWBOX": 
		console.log("DRAWBOX is not implemented");
		break;

	case  "CREATEWINDOW":
		createWindow(currentApplication, d);
		break;

	case "CLOSEWINDOW": 
		var clsWindow=d.WINDOW;
		var cls_win=currentApplication.windows[clsWindow];
		cls_win.closeWindow();
		break;
		
		
		
/*
		, "NAME":"a4gl_helpw1","X":1,"Y":1,"W":80,"H":24,"FORM_LINE":255,"ERROR_LINE":255,"PROMPT_LINE":255,"MENU_LINE":1,"COMMENT_LINE":255,"MESSAGE_LINE":255,"BORDER":0,"ATTRIBUTE":0,"STYLE":"","TEXT":"" },
*/


	case "SHOWHELP":
			var w;
			w = new Ext.Window({
  			autoLoad: {
    			    url: "/"+helpFilePrefix+"/"+d.HelpId+".html",
    			//discardUrl: true,
    			nocache: false,
    			text: "Loading...",
    			//timeout: 60,
    			//scripts: false 
  			},
  			height: 300,
  			width: 600,
			title: 'Application Help',
			buttons: [
				{text:'OK', handler: function () {
					w.close();
				}}
			]
			});
			w.show();
		
		//"HelpId":1002
		break;

	case "SETHELPFILE":
		helpFilePrefix=d.FileName;
		break;
		//"FileName":"helpdemo"


	case "DISPLAYTO":
		displayTo(currentApplication, d.Fields,d.Values);
		break;

	case "NEXTOPTION":
		// Doesnt have any meaning with this type of menu..
		break;

	case "DISPLAYFORM":
		var frm=currentApplication.Forms[d.FORMNAME].form;

		if (currentApplication.currentWindow) {
			currentApplication.currentWindow.setActiveForm(frm);
		} else {
			console.log("Uuurrgghh - no current application window");

			var win=Ext.create("Ext.window.Window", {
        			//width:200,
        			//height:200,
        			layout:'fit',
				items: [
					frm
        			]
			});
			win.show();
		}
		break;

	case "HIDEOPTION":
		var context=d.CONTEXT;
		var c=currentApplication.Contexts["C"+context];
		c.hideOption(d.OPTION);
		break;
	case "SHOWOPTION":
		var context=d.CONTEXT;
		var c=currentApplication.Contexts["C"+context];
		c.showOption(d.OPTION);
		break;

	case "FIELDDELIMITERS": 
		break;
		
	case "OPENWINDOWWITHFORM":
		var frm=createForm(d.FORM.Data);
		createWindow(currentApplication, d,frm);
		break;


/*
ATTRIBUTE: 0
BORDER: 1
COMMENT_LINE: 255
ERROR_LINE: 255
FORM: Object
FORM_LINE: 255
MENU_LINE: 255
MESSAGE_LINE: -1
PROMPT_LINE: 255
SOURCE: "cq_browse"
STYLE: ""
TEXT: ""
WINDOW: "w_browse"
X: 2
Y: 2
type: "OPENWINDOWWITHFORM"
*/

	default:
		console.log("Unhandled : " + d.type);
		console.dir(d);

}


}
