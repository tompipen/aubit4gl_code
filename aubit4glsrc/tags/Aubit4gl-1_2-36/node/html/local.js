// publically editable file to set the icons for buttons..


function getIconClass(nm, parentFormName, parentWindowName) {
	console.log("getIconClass : " + nm+" "+parentFormName+" "+parentWindowName);

	
        switch(nm) {
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
