// publically editable file to set the icons for buttons..


function getProgramName(nm) {
if (Ext.String.endsWith(nm,"fgldemo.4ae")) {
	return "Informix 4GL FGL Demo";
}
return nm;
}

function getIconClass(nm, parentFormName, parentWindowName) {
	console.log("getIconClass : " + nm+" "+parentFormName+" "+parentWindowName);
	

        switch(nm) {

		case "Query": return "icon-"+nm;
		case "Next": return "icon-"+nm;
		case "Previous": return "icon-"+nm;
		case "Add": return "icon-"+nm;
		case "Update": return "icon-"+nm;
		case "Remove": return "icon-"+nm;
		case "Screen": return "icon-"+nm;
		case "Master": return "icon-"+nm;
		case "Detail": return "icon-"+nm;
		case "Exit": return "icon-"+nm;
		case "Output": return "icon-output";
		case "Current": return "icon-current";

		case "6":
			if (parentFormName=="custform") {
				return "hide";
			}
		case "25":
			if (parentFormName=="custform") {
				return "hide";
			}
        }
}



function getKeyDescription(nm, parentFormName, parentWindowName) {
	console.log("getKeyDescription : " + nm+" "+parentFormName+" "+parentWindowName);
	switch (nm) {
		case "3000":
			if (parentFormName=="custform") {
				return "Get help form the current field";
			}
			break;
		case "3001":
			if (parentFormName=="custform") {
				return "Return to the menu";
			}
			break;
	}
}

function getKeyName(nm, parentFormName, parentWindowName) {
	console.log("getKeyName : " + nm+" "+parentFormName+" "+parentWindowName);
	switch (nm) {
		case "3000":
			if (parentFormName=="custform") {
				return "Help";
			}
			break;
		case "3001":
			if (parentFormName=="custform") {
				return "Quit";
			}
			break;
	}
}
