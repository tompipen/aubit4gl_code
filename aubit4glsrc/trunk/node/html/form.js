/**
*  Base64 encode / decode
*  http://www.webtoolkit.info/
**/

 
var Base64 = { 
  // private property
  _keyStr : "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",
 
  // public method for encoding
  encode : function (input) {
    var output = "";
    var chr1, chr2, chr3, enc1, enc2, enc3, enc4;
    var i = 0;
 
    input = Base64._utf8_encode(input);
 
    while (i < input.length) {
      chr1 = input.charCodeAt(i++);
      chr2 = input.charCodeAt(i++);
      chr3 = input.charCodeAt(i++);
 
      enc1 = chr1 >> 2;
      enc2 = ((chr1 & 3) << 4) | (chr2 >> 4);
      enc3 = ((chr2 & 15) << 2) | (chr3 >> 6);
      enc4 = chr3 & 63;
 
      if (isNaN(chr2)) {
        enc3 = enc4 = 64;
      } else if (isNaN(chr3)) {
        enc4 = 64;
      }
 
      output = output +
      this._keyStr.charAt(enc1) + this._keyStr.charAt(enc2) +
      this._keyStr.charAt(enc3) + this._keyStr.charAt(enc4);
    }
 
    return output;
  },
 
  // public method for decoding
  decode : function (input) {
    var output = "";
    var chr1, chr2, chr3;
    var enc1, enc2, enc3, enc4;
    var i = 0;
 
    input = input.replace(/[^A-Za-z0-9\+\/\=]/g, "");
 
    while (i < input.length) {
      enc1 = this._keyStr.indexOf(input.charAt(i++));
      enc2 = this._keyStr.indexOf(input.charAt(i++));
      enc3 = this._keyStr.indexOf(input.charAt(i++));
      enc4 = this._keyStr.indexOf(input.charAt(i++));
 
      chr1 = (enc1 << 2) | (enc2 >> 4);
      chr2 = ((enc2 & 15) << 4) | (enc3 >> 2);
      chr3 = ((enc3 & 3) << 6) | enc4;
 
      output = output + String.fromCharCode(chr1);
 
      if (enc3 != 64) {
        output = output + String.fromCharCode(chr2);
      }
      if (enc4 != 64) {
        output = output + String.fromCharCode(chr3);
      }
    }
 
    output = Base64._utf8_decode(output);
 
    return output;
  },

  // private method for UTF-8 encoding
  _utf8_encode : function (string) {
    string = string.replace(/\r\n/g,"\n");
    var utftext = "";
 
    for (var n = 0; n < string.length; n++) {
      var c = string.charCodeAt(n);
 
      if (c < 128) {
        utftext += String.fromCharCode(c);
      }
      else if((c > 127) && (c < 2048)) {
        utftext += String.fromCharCode((c >> 6) | 192);
        utftext += String.fromCharCode((c & 63) | 128);
      }
      else {
        utftext += String.fromCharCode((c >> 12) | 224);
        utftext += String.fromCharCode(((c >> 6) & 63) | 128);
        utftext += String.fromCharCode((c & 63) | 128);
      }
    }
 
    return utftext;
  },

  // private method for UTF-8 decoding
  _utf8_decode : function (utftext) {
    var string = "";
    var i = 0;
    var c = c1 = c2 = 0;
 
    while ( i < utftext.length ) { 
      c = utftext.charCodeAt(i);
 
      if (c < 128) {
        string += String.fromCharCode(c);
        i++;
      }
      else if((c > 191) && (c < 224)) {
        c2 = utftext.charCodeAt(i+1);
        string += String.fromCharCode(((c & 31) << 6) | (c2 & 63));
        i += 2;
      }
      else {
        c2 = utftext.charCodeAt(i+1);
        c3 = utftext.charCodeAt(i+2);
        string += String.fromCharCode(((c & 15) << 12) | ((c2 & 63) << 6) | (c3 & 63));
        i += 3;
      }
    }
 
    return string;
  }
}



var xMultiplier=10;
var yMultiplier=24;


function createLabel(lvl, d,miny) {
var style="";
if (d.guessAlign=="R") {
        style="text-align:right;"
} 
//style+="font-family: Courier;display:block;width:"+d.gridWidth*xMultiplier+"px;";
style+="display:inline-block; width:"+d.gridWidth*xMultiplier+"px; line-height:"+yMultiplier+"px";

return Ext.widget("label", {
        style: style,
	x: d.posX*xMultiplier,
	y: (d.posY-miny)*yMultiplier,
	tabIndex:-1,
	text: d.text
	});
}


function afterField(itm) {
//validateField
console.log("After Field");
}

function beforeField() {
console.log("Before Field");
}


function createFormField(lvl, d,miny) {
if (d.noEntry===undefined) {
	d.noEntry=false;
}
// All the default stuff...
var cfg= { 
		A4GL_definition : d,
		A4GL_name: d.name,
		A4GL_colname: d.colName,
		A4GL_fullname: d.sqlTabName+"."+d.colName,
		A4GL_fieldId: d.fieldId,
		A4GL_tabname: d.sqlTabName,
		A4GL_sqlType: d.sqlType,
		A4GL_noentry: d.noEntry,
		constructName: d.colName,
		//vtype ? ??
		readOnly : d.noEntry,
		tooltip:d.widget.comments,
		enforceMaxLength:true,
      fieldValidationFailed:function(widget, txt) {
		console.log("fieldValidationFailed : " + txt);
		switch(txt) {
			case "FIELD_CONSTR_EXPR": txt= "Error in expression";break;
			case "FIELD_REQD_MSG": txt="This field required an entered value";break;
			case "FIELD_ERROR_MSG": txt= "Error in field"; break;
			case "FIELD_INCL_MSG": txt= "This value is not among the valid possibilities";break;
		}
		widget._errors.push(txt);
	},
      getErrors: function(t1)  {
		var txt;
		var me=this;
	console.log("getErrors...");
		
		if (t1===undefined) {
			txt=me.getFormFieldValue(me);
		} else {
			txt=t1;
		}
		me._errors=[];
		if (me.readOnly || me.disabled) {
		return [];
		}
		if (me.validateField(txt)) {
			return [];
		}

		if (me._errors.length==0) {
			console.log("Error List: ");
			console.dir(me._errors);
		} else {
			console.log("No errors!");
		}
		return me._errors;
	},
      validateField:function(txt)
        {
            var me=this;
	    var s_d=d;
	    var currentContextType=me.currentContext.contextType;

	    me.datatype=AubitDesktop.FGLConstruct.decode_datatype(me.A4GL_sqlType);

	    me.datatype_length=AubitDesktop.FGLConstruct.decode_datatype_length(me.A4GL_sqlType);
		console.log("currentContextType="+currentContextType);
            if (currentContextType == AubitDesktop.FGLContextType.contextConstruct)
            {
                var cstr=AubitDesktop.FGLConstruct.getConstructString(me.constructName, txt, me.datatype, me.datatype_length);
		console.log("cstr="+cstr);
                if (cstr==null) 
                {
                    var ign = false;
		    if(me.fieldValidationFailed) {
                    	ign=me.fieldValidationFailed(me, "FIELD_CONSTR_EXPR");
		    }

                    if (!ign)
                    {
                        return false;
                    }
                }
                return true;
            }

            if (currentContextType == AubitDesktop.FGLContextType.contextInput || currentContextType == AubitDesktop.FGLContextType.contextInputArray)
            {
                var ign = false;
                if (me.Required) //@Fixme
                {
                    if (txt.length == 0)
                    {
                        if (me.fieldValidationFailed != null)
                        {
                            ign=me.fieldValidationFailed(me, "FIELD_REQD_MSG");
                        }
                        if (!ign)
                        {
                            return false;
                        }
                    }

                }

                if (!FGLUtils.IsValidForType(me.datatype, txt, me.format,me.datatype_length))
                {
                    if (me.fieldValidationFailed != null)
                    {
                        ign=me.fieldValidationFailed(me, "FIELD_ERROR_MSG");
                    }
                    if (!ign)
                    {
                        return false;
                    }
                }

                if (me.includeValues != null)
                {
                    var ok = false;
                    Ext.each(me.includeValues,function(s)
                    {
                        if (s.Contains(":"))
                        {
                            var l, r;
                            var arr;
                            arr = s.Split(':');
                            l = arr[0];
                            r = arr[1];

                            if (FGLUtils.compare_range(txt, l, r, me.datatype, me.datatype_length, me.format))
                            {
                                ok = true;
                            }
                        }
                        else
                        {
                            if (s == "NULL" && txt == "")
                            {
                                ok = true;
				return;
                            }
                            if (s == txt)
                            {
                                ok = true;
				return;
                            }
                        }
                    });

                    ign = false;
                    if (!ok)
                    {
                        ign=me.fieldValidationFailed(me, "FIELD_INCL_MSG");


                        if (!ign)
                        {
                            return false;
                        }
                    }
                }
            }



            return true;
        },

	// These functions can be overridden if we need spcific actions
	// for a particular widget type...
		isTouched: function(widget) {
			return widget.isDirty();
		},
		isFormFieldValid: function(widget) {
			return widget.isValid();
		},
		clearField: function(widget,def) {
			if (def) console.log(" to defaults not implemented");
			widget.setValue("");
		},
		getFormFieldValue: function(widget) {
			// getRawValue
			// getSubmitValue
			return widget.getValue();
		},
		setFormFieldValue: function(widget, txt) {
			widget.setValue(txt.trim());
		},
		enableField: function(widget) {
			if (this.A4GL_noentry) return;
			else {
				this.setReadOnly(false);
			//this.setDisabled(false);
			}
		},
		disableField: function(widget) {
			if (this.A4GL_noentry) return;
			//this.setDisabled(true);
			this.setReadOnly(true);
		},
    		setCaretPosition: function(pos) {
        		var el = this.inputEl.dom;
        		if (typeof(el.selectionStart) === "number") {
            			el.focus();
            			el.setSelectionRange(pos, pos);
        		} else if (el.createTextRange) {
            			var range = el.createTextRange();
            			range.move("character", pos);
            			range.select();
        		} else {
            			throw 'setCaretPosition() not supported';
        		}
    		},
	
    		getCaretPosition: function() {
        		var el = this.inputEl.dom;
        		if (typeof(el.selectionStart) === "number") {
            			return el.selectionStart;
        		} else if (document.selection && el.createTextRange){
            			var range = document.selection.createRange();
            			range.collapse(true);
            			range.moveStart("character", -el.value.length);
            			return range.text.length;
        		} else {
            			throw 'getCaretPosition() not supported';
        		}
    		}
	};
	
if (d.noEntry) {
		cfg.hideTrigger=true;
		cfg.tabIndex=-1;
} else {
	cfg.tabIndex=1;
}

if (d.widget && d.widget.shift) {
		if (d.widget.shift=="up")  {
		    Ext.apply(cfg,{
			fieldStyle:'text-transform:uppercase', 
			listeners:{
				change: function(field, newValue, oldValue){  
					field.setValue(newValue.toUpperCase()); 
				} 
			}
			});
		 } 

		if (d.widget.shift=="down")  { 
		    Ext.apply(cfg,{
			fieldStyle:'text-transform:lowercase', 
			listeners:{
				change: function(field, newValue, oldValue){  
					field.setValue(newValue.toLowerCase()); 
				} 

			}
			});
		}

}

var item=null;

switch (d.widget.type) {
	case "Edit": 
		var minWidth= d.widget.gridWidth*xMultiplier;
		if (d.widget.gridWidth<=3) {
			minWidth+=10;
		}
		Ext.apply(cfg,{
			x: d.widget.posX*xMultiplier,
			y: (d.widget.posY-miny)*yMultiplier,
			width: minWidth,
			maxLength: d.widget.width,

		});

		item=Ext.widget("textfield",cfg);

		item.on('blur', function() {
			afterField(item);
		});

		item.on('focus', function() {
			beforeField(item);
			if (item.currentContext) {
				item.currentContext.lastFocusField=item;
			}
		});

		// textfield doesnt have a tooltip option
		// so we need to do it ourselves...
		item.on('render', function(c) {
			if (c.tooltip) {
      				Ext.QuickTips.register({
        			target: c.getEl(),
        			text: c.tooltip
      			});
			}
		});
		break;

	default:
		console.log("Unable to generate widget type : "+d.widget.type );	
		break;
	
}

item.disableField();

return item;
}




function createHLine(lvl, d,miny) {
var w;

if (d.gridWidth) {
	w=xMultiplier*(0+d.gridWidth);
} else {
	w=780;
}

	return new Ext.form.Label({
		flex:1,
		x: d.posX*xMultiplier,
		y: (d.posY)*yMultiplier,
		width:w, //xMultiplier*d.gridWidth,
		html:'<hr />'
		});
}



/*
function generateModel(d,cnt) {
var a;

var modelName="TableModel"+cnt;

//fld.flex=d.items[a].widget.width;

Ext.define(modelName, {
            extend: 'Ext.data.Model',
        });
console


return modelName;
}
*/


function generateStore(d,cnt) {
var flds=[];
     for (a=0;a<d.items.length;a++) {
	//var fld={};
	//fld.name=d.items[a].colName;
	flds.push( d.items[a].colName);
     }
     var storeConfig = {
            fields: flds
     };
     var store = Ext.create('Ext.data.ArrayStore', storeConfig);
     store.createNewRow=function(arr) {
	var flds={};
     	for (a=0;a<d.items.length;a++) {
		flds[d.items[a].colName]=arr[a];
	}
	return flds
     }
     return store;
}

function generateColumns(d,cnt) {
var flds=[];
for (a=0;a<d.items.length;a++) {
	var fld={};
	fld.dataIndex=d.items[a].colName;
	//fld.name=d.items[a].colName;
	fld.colName=d.items[a].colName;
	fld.fieldId=d.items[a].fieldId;
	fld.sqlTabName=d.items[a].sqlTabName;

	if (d.items[a].text) {
		fld.header=d.items[a].text
	}

	
	if (d.items[a].widget) {
		var w=d.items[a].widget.width;
		if (w<3) {
			fld.width=5*xMultiplier;
		} else {
			fld.width=(w+2)*xMultiplier;
		}
	}
	
	flds.push(fld);
}

return flds;

}



function findTable(currentApplication, screenRecord) {
	screenRecord=screenRecord.Name.replace(".*","");
	var res=currentApplication.currentWindow.activeForm.query("[ScreenRecordName]");
	if (res && res.length) {
		return res[0];
	}
	return null;
}

var crTableCnt=0;
function createTable(lvl, d,miny) {

crTableCnt++;
var height=null
if (d.pageSize) {
	height=(d.pageSize+1)*yMultiplier;
}


var store=generateStore(d, crTableCnt)

var row;
var col;
var fakeData=[];

for (row=0;row<d.pageSize;row++) {
	var dt={}
	for (col=0;col<d.items.length;col++){
		dt[d.items[col].colName]="";
	}
	fakeData.push(dt);
}
store.fakeData=fakeData;
store.loadData(fakeData,false);



var x=generateColumns(d, crTableCnt);
console.dir(x);




var grid=Ext.create('Ext.grid.Panel', {
    store: store,
    columns: generateColumns(d, crTableCnt) ,
    			minHeight:height,
			width:780,
			//minWidth:780,
});

grid.ScreenRecordName=d.tabName;


/*
var grid=Ext.create('Ext.grid.Panel', {
    			title: d.text,
    			minHeight:height,
			minWidth:780,
			flex:1,
    			//store: store,
    			columns: generateColumns(d, crTableCnt)
});
*/

return Ext.widget("container", {
    			minHeight:height,
			//width:780,
			items : [ grid ]
}
);


/*
 return new Ext.form.Label({
                flex:1,
		x:xMultiplier,
		width:780,
                html:'<hr />'
                });
*/

/*
	return new Ext.panel.Panel({
		flex:1,
		width:780, //xMultiplier*d.gridWidth,
		html:'<hr />'});
*/
}


function createWidget(lvl, d,miny) {
	if (d==null) return null;
	s="";
	var a;
	for (a=0;a<lvl;a++) s+="   ";
	console.log(s+"create " + d.type);
	switch (d.type) {
		case "Label": return createLabel(lvl,d,miny);
		case "FormField": return createFormField(lvl,d,miny);
		case "VBox": return createVBox(lvl,d,miny);
		case "Screen":
		case "Grid": return createGrid(lvl,d,miny);
		case "HLine": return createHLine(lvl,d,miny);
		case "Table": return createTable(lvl,d,miny);
	
		default: 
			console.log("Unhandled widget: " + d.type);
			return null;
	}
}


function createWidgets(lvl,d,miny) {
	var items=[];
	var itemCnt;

	for(itemCnt=0;itemCnt<d.length;itemCnt++) {
		var item;
		item=createWidget(lvl+1, d[itemCnt],miny);
		if (item!=null) {
			items.push(item);
		}
	}

	return items;
}



function getPosMin(d) {
var a;
var miny=1000;
for (a=0;a<d.items.length;a++) {

	if (d.items[a].posY<miny) {
		miny=d.items[a].posY;
	}

	if (d.items[a].items) {
		if (getPosMin(d.items[a].items) < miny) {
			miny=d.items[a].posY;
		}
	}
}
return miny;
}


/*
function fixPosMin(d,miny) {
for (a=0;a<d.items.length;a++) {
	d.items[a].posY-=miny;
	if (d.items[a].items) {
		fixPosMin(d.items[a].items,miny);
	}
}
}
*/


function createGrid(lvl,d,miny) {
if (lvl) {
	miny=getPosMin(d);
} else {
	miny=0;
}
	console.log("miny="+miny);


	var items=createWidgets(lvl+1,d.items, miny);
	var frm=Ext.create("Ext.container.Container", {
			layout:'absolute',
			flex:1,
			margin:10,
			//minHeight: d.height*yMultiplier,
			//minWidth: d.width*xMultiplier,
				items : items
	});


	return frm;
}

function createVBox(lvl,d, miny) {
var items=createWidgets(lvl+1, d.items,miny);
var i;
// Setting flex on this will cause all the items
// to have the same height :(
for (i=0;i<items.length;i++) {items[i].flex=null}
return Ext.widget("container",{layout:{ type:'vbox', align:'stretch'},  items :items});
}



function fieldsValid(fieldList, mode) {
var a;
for (a=0;a<fieldList.length;a++) {
	if (!fieldList[a].isFormFieldValid(fieldList[a], mode)) {
		return false;
	}
}
return true;
}

function createForm(d) {
//d=Data


var str=Base64.decode(d.join());
var frmDefinition=JSON.parse(str);

if (!frmDefinition.layout) {
	console.log("No layout!");
	return null;
}
if (!Ext.isArray(frmDefinition.layout)) {
	console.log("layout should be an array!");
	return null;
}

var scr;
var screens=[];
for (scr=0;scr<frmDefinition.layout.length;scr++) {
	var screen;
	miny=0;
	screen=createWidget(0, frmDefinition.layout[scr],miny);
	/*
	if (frmDefinition.layout[scr].type=="Screen") {
		var items=createWidgets(frmDefinition.layout[scr].items);

		screen=Ext.create("Ext.panel.Panel", {
				layout:'absolute',
				minHeight: frmDefinition.layout[scr].height*yMultiplier,
				minWidth: frmDefinition.layout[scr].width*xMultiplier,
				items : items
			});
	}

	if (frmDefinition.layout[scr].type=="VBox") {
		screen=createWidget(frmDefinition.layout[scr]);
	}
	*/

	if (screen!=null) {
		screens.push(screen);
	}

	screen.title=" ";

	if (frmDefinition.layout[scr].title) {
		screen.title=frmDefinition.layout[scr].title;
	}
}

var rval=null;
// if we have more that one layout - put them in a tabpanel..
if (screens.length>1) {
	rval=Ext.create('Ext.tab.Panel', {
    	//width: 400,
    	//height: 400,
    	items: screens
	});
} else {
	rval=screens[0];
	rval.cls="screen";
}


/*
var win=Ext.create("Ext.window.Window", {
	//width:200,
	//height:200,
	layout:'fit',
	items : [
		rval
	]
});
win.show();
*/

rval.A4GL_name=frmDefinition.name;

return rval;
}
