
if(!String.prototype.trim){  
  String.prototype.trim = function(){  
    return this.replace(/^\s+|\s+$/g,'');  
  };  
}

/*
 {"type":"DISPLAYTO", "ATTRIBUTE":1280,
         "Fields":[
            { "Name":"customer_num"} ,
            { "Name":"fname"} ,
            { "Name":"lname"} ,
            { "Name":"company"} ,
            { "Name":"address1"} ,
            { "Name":"address2"} ,
            { "Name":"city"} ,
            { "Name":"state"} ,
            { "Name":"zipcode"} ,
            { "Name":"phone"} ],
         "Values":[
         {"TYPE":2,"Text":"114"} ,
         {"TYPE":0,"Text":"Frank          "} ,
         {"TYPE":0,"Text":"Albertson      "} ,
         {"TYPE":0,"Text":"Sporting Place      "} ,
         {"TYPE":0,"Text":"947 Waverly Place   "} ,
         {"TYPE":0,"Text":""} ,
         {"TYPE":0,"Text":"Redwood City   "} ,
         {"TYPE":0,"Text":"CA"} ,
         {"TYPE":0,"Text":"94062"} ,
         {"TYPE":0,"Text":"415-886-6677      "} 
]},
*/


function findFields(currentApplication, fields) {
var Flds=[];
var a;
if (fields==null) {
	console.log("null fields ? ???");
	return;
}
for(a=0;a<fields[0].FIELD.length;a++) {
	var flds=findField(currentApplication, fields[0].FIELD[a]);
	if (flds==null) continue;
	var b;
	for (b=0;b<flds.length;b++) {
		Flds.push(flds[b]);
	}
}

return Flds;
}


function fieldIsNoEntry(fld, context) {

if ( context && context.contextType== AubitDesktop.FGLContextType.contextConstruct) {
	// Never explicitly blocked from a construct
	return false;
}

if (fld.A4GL_noentry  || fld.A4GL_noupdate ) {
	return true;
} else {
	return false;
}


}

function enableActiveFields(currentApplication, fldList, context) {
	var allFields=currentApplication.currentWindow.activeForm.query("[A4GL_fullname]");
	var a;
	for (a=0;a<allFields.length;a++) {
		if (fldList.indexOf(allFields[a])==-1) {
			allFields[a].currentContext=null;
			allFields[a].disableField();
			allFields[a].el.dom.setAttribute('tabIndex', -1);
			allFields[a].validate();
		} else {
			allFields[a].currentContext=context;
			allFields[a].enableField();
			allFields[a].el.dom.setAttribute('tabIndex', a);
			allFields[a].fieldIsLast=false;
			allFields[a].validate();
		}
	}

	for (a=allFields.length-1;a>=0;a--) {
			// Skip any disabled fields...
			if (fieldIsNoEntry(allFields[a]) || allFields[a].isDisabled()) {
				continue;
			}
			allFields[a].fieldIsLast=true;
			break;
	}
}

function disableAllFields(currentApplication) {
	var allFields= getAllFields(currentApplication) ;
	var a;
	for (a=0;a<allFields.length;a++) {
		allFields[a].disableField();
		allFields[a].el.dom.setAttribute('tabIndex', -1);
			allFields[a].validate();
	}
	var tabs=currentApplication.currentWindow.activeForm.query("[ScreenRecordName]");
        if (tabs && tabs.length) {
		for (a=0;a<tabs.length;a++) {
			tabs[a].setDisabled(true);
		}
        }
	
}

function clearForm(currentApplication, def) {
	var allFields= getAllFields(currentApplication) ;
	var a;
	for(a=0;a<allFields.length;a++) {
		allFields[a].clearField(allFields[a], def);
	}
}


function clearFields(currentApplication, fieldlist, todefault) {
	var allFields=findFields(currentApplication, fieldlist);
	var a;
	for(a=0;a<allFields.length;a++) {
		allFields[a].clearField(allFields[a], todefault);
	}
}


function getAllFields(currentApplication) {
	var fld_1=currentApplication.currentWindow.activeForm.query("[A4GL_fullname]");
	return fld_1;
}

function findField(currentApplication, fld) {
var flds=[];
	var matchAllWithPrefix;
	if (currentApplication.currentWindow==null) return null;
	if (currentApplication.currentWindow.activeForm==null) return null;
	var i=fld.NAME.indexOf(".*")
	if (i!=-1) {
		matchAllWithPrefix=fld.NAME.substr(0,i);
		console.log("MATCH : " + matchAllWithPrefix);
	}
	var fld_1=getAllFields(currentApplication); 
	var a;
	for ( a=0;a<fld_1.length;a++) {
		var found=null;
		if (fld_1[a].A4GL_fullname==fld.NAME || fld_1[a].A4GL_colname==fld.NAME) {
			found=true;
			console.log(fld_1[a]);
			flds.push(fld_1[a]);
		}

		// Does it match a table.* ? 
		if (!found && matchAllWithPrefix && fld_1[a].A4GL_tabname==matchAllWithPrefix) {
			found=true;
			console.log(fld_1[a]);
			flds.push(fld_1[a]);
		}

		// @fixme - Need to search in the screen records too
	}
	//#console.log("SRCH:" + fld);
	return flds;
}

function displayTo(currentApplication, fields, values) {
	var Flds=findFields(currentApplication, fields);

	if (values[0].TEXT.length!=Flds.length) {
		console.log("Internal error - field/values mismatch");
		return;
	}
	var a;

	for (a=0;a<Flds.length;a++) {
		Flds[a].setFormFieldValue(Flds[a], values[0].TEXT[a].Data, 
					values[0].TEXT[a].TYPE);
	}
}
