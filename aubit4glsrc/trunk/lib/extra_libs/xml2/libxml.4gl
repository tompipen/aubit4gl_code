code
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <libxml/SAX.h>

endcode

WHENEVER ERROR CONTINUE
WHENEVER ANY ERROR CONTINUE
WHENEVER SQLERROR CONTINUE


function createDocument(lv_version)
define lv_document integer
define lv_version char(512)
code
{
void *vp;
vp=lv_version;
A4GL_trim(lv_version);
if (strlen(vp)==0) vp=0;
lv_document=(long)xmlNewDoc((xmlChar*)vp);
}
endcode
return lv_document
end function

function getDocumentNode(p_document)
define p_document integer
define lv_node integer
code
{
lv_node=(long)xmlDocGetRootElement((void*)p_document);
}
endcode
return lv_node
end function


code
static void
print_element_names(xmlNode * a_node)
{
#ifdef DO_ANOTHER_TIME
    xmlNode *cur_node = NULL;

    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
            printf("node type: Element, name: %s\n", cur_node->name);
        }

        print_element_names(cur_node->childs);
    }
#endif
}
endcode



function debugPrint(lv_doc)
define lv_doc integer
display " " # Force line mode...
code
{
xmlNode *root;
  root=xmlDocGetRootElement((void *)lv_doc);
  print_element_names(root);
}

endcode
end function

function setRootElement(lv_doc,lv_node)
define lv_doc,lv_node integer
code
xmlDocSetRootElement(lv_doc, lv_node);
endcode

end function

function createElement(doc,name,value) 
define name char(512)
define value char(512)
define node integer
define doc integer

code
{
	char *valuep;
	valuep=value;
	A4GL_trim(name);
	A4GL_trim(value);
	if (strlen(value)==0) valuep=NULL;

	node = (long)xmlNewDocNode((void *)doc, NULL, (xmlChar*)name, (xmlChar*)valuep);
}
endcode

return node
end function


function appendChild(node, childnode)
define node, childnode integer
define new_child integer

code
new_child = (long)xmlAddChild((void *)node, (void *)childnode);
endcode

return new_child
end function




function setAttribute(node,key,value)
define name char(512)
define value char(512)
define key char(512)
define node integer
define doc integer
define lv_ok integer
define name_valid integer
code
{
	void *attr;
	lv_ok=1;
	A4GL_trim(key);
	A4GL_trim(value);

                attr = (xmlNodePtr)xmlSetProp((void *)node, (xmlChar *) key, (xmlChar *)value);
        	if (!attr) {
			lv_ok=0;
        	}
}
endcode

return lv_ok
end function



function saveXml(p_doc, p_filename)
define p_doc integer
define p_filename char(512)
code
A4GL_trim(p_filename);
	xmlSaveFile(p_filename,(void *) p_doc);
endcode
end function

function freeXml(p_doc)
define p_doc integer
code
	xmlFreeDoc((void*)p_doc);
endcode
end function

