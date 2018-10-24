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
		console.log("DISPLAYAT:" + d.data);
		return ;

	case "DISPLAY":
		console.log(d.data);
		return;

 	case "ERROR":
		if (!currentApplication.currentWindow) {
		Ext.Msg.show({
   			title:'Error',
			closable:true,
			modal:true,
   			msg: d.data,
			buttons:Ext.window.MessageBox.OK
		});
		} else {
			currentApplication.currentWindow.setError(d.data);
		}
		return;

 	case "MESSAGE":
		if (!currentApplication.currentWindow) {
		Ext.MessageBox.show({
   			title: 'Message',
   			msg: d.data,
			modal:true,
			buttons:Ext.window.MessageBox.OK
			});
		} else {
			currentApplication.currentWindow.setMessage(d.data);
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
		var context=d.context;
		var c=currentApplication.Contexts["C"+context];
		if (!c) {
			console.log("FREE No context "+d.context);
			alert("FREE No context"+d.context);
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
		var context=d.context;
		var c=currentApplication.Contexts["C"+context];
		if (!c) {
			console.log("WAITFOREVENT No context"+d.context);
			alert("WAITFOREVENT No context"+d.context);
			return;
		}
		if (c.ContextActivate) {
			c.ContextActivate(d);
		}
		console.log("Now - wait for event ..");
		console.dir(c);
		break;



	case "PROGRAMSTOP": 
		currentApplication.stopping=true;
		if (d.exitcode===undefined) d.exitcode=-1;
		if (d.data) {
			if (d.data.join) {
				Ext.Msg.alert( "Program stopped - edit code : " +d.exitcode, d.data.join("<br>"), function() {location.href=location.href; });
			} else {
				Ext.Msg.alert( "Program stopped - edit code : " +d.exitcode, d.data, function() { location.href=location.href;});
			}
		} else {
				Ext.Msg.alert( "Program stopped - edit code : " +d.exitcode, "", function() {location.href=location.href; });
		}
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
                	document.title=getProgramName(d.programname);
			screen.show();
		} else {
			screen.setTitle(getProgramName(d.programname));
			screen.show();
		}
		console.log("Shown 'screen'");
		 //

	break;

	case "OPTIONS" :
			currentApplication.options[optionsDecode(d.option)]=d.value;
			break;




	case "OPENFORM":
		if (d.data) {
			var fObj=Ext.JSON.decode(d.data);
			var dt="";
			if (Ext.isArray(fObj.Data)) {
				dt=fObj.Data.join("");
			} else {
				dt=fObj.Data;
			}
			var frm=createForm(dt, d.formname, currentApplication);
			if (frm) { 
			currentApplication.Forms[d.formname]={
				source: d.source,
				form: frm
			}
			} else {
				currentApplication.sendError({errMsg:'Invalid form'});
			}
		}
		break;

	case "CURRENTWINDOW":
		var cwin=d.window;
		var cw_win=currentApplication.windows[cwin];

		if (cw_win) {
			cw_win.ensureCurrent();
		}
		break;


	case "CLEARWINDOW":
		var cwin=d.window;
		console.log("@Fixme - clear window " +cwin);
		break;

		
	case "CLEAR":
		clearFields(currentApplication,d.fieldlist, d.todefault);
		break;

	case "CLEARFORM": 
		clearForm(currentApplication, d.todefaults);
		console.log("@Fixme - clear form");
		break;

	case "DRAWBOX": 
		console.log("DRAWBOX is not implemented");
		break;

	case  "CREATEWINDOW":
		createWindow(currentApplication, d);
		break;

	case "CLOSEWINDOW": 
		var clsWindow=d.window;
		var cls_win=currentApplication.windows[clsWindow];
		cls_win.closeWindow();
		break;
		
		
		
/*
		, "NAME":"a4gl_helpw1","X":1,"Y":1,"W":80,"H":24,"FORM_LINE":255,"ERROR_LINE":255,"PROMPT_LINE":255,"MENU_LINE":1,"COMMENT_LINE":255,"MESSAGE_LINE":255,"BORDER":0,"ATTRIBUTE":0,"STYLE":"","TEXT":"" },
*/


	case "SHOWHELP":
			var helpWindow = new Ext.Window({
  			autoLoad: {
    			    url: "/"+helpFilePrefix+"/"+d.helpid+".html",
    			//discardUrl: true,
    			nocache: false,
    			text: "Loading...",
    			//timeout: 60,
    			//scripts: false 
  			},
  			height: 300,
			x:10,
			y:10,
  			width: 600,
			title: 'Application Help',
			buttons: [
				{text:'OK', handler: function () {
					helpWindow.close();
				}}
			]
			});
			helpWindow.show();
			 
			
		
		//"HelpId":1002
		break;

	case "SETHELPFILE":
		helpFilePrefix=d.filename;
		break;
		//"FileName":"helpdemo"


	case "DISPLAYTO":
		displayTo(currentApplication, d.fieldlist,d.vs,d.attribute);
		break;

	case "NEXTOPTION":
		// Doesnt have any meaning with this type of menu..
		break;

	case "DISPLAYFORM":
		var frm=currentApplication.Forms[d.formname].form;

		if (frm) { 
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
		}  else {
			currentApplication.sendError({ errMsg:'Invalid form', formName:d.formname});
		}
		break;

	case "HIDEOPTION":
		var context=d.context;
		var c=currentApplication.Contexts["C"+context];
		c.hideOption(d.option);
		break;

	case "SHOWOPTION":
		var context=d.context;
		var c=currentApplication.Contexts["C"+context];
		c.showOption(d.option);
		break;

	case "FIELDDELIMITERS": 
		break;
		
	case "OPENWINDOWWITHFORM":
		var owwf=Ext.JSON.decode(d.data);
			var dt="";
			if (Ext.isArray(owwf.Data)) {
				dt=owwf.Data.join("");
			} else {
				dt=owwf.Data;
			}
		try { 
			var frm=createForm(dt,"fixme",currentApplication);
			createWindow(currentApplication, d,frm);
		} catch (Err) {
			console.error(Err);
		}
		break;


	case "SLEEPING":
		currentApplication.windows["screen"].setLoading("Application is sleeping..");
		break;
	case "SLEPT":
		currentApplication.windows["screen"].setLoading(false);
		break;

	case "REPORTPAUSE": 
		// ignore it..
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
