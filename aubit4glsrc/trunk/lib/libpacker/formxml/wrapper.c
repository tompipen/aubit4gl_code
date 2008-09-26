#include "a4gl_libaubit4gl.h"
#include "a4gl_API_packer_lib.h"


void write_xml_form(FILE *wofile, char *fname, struct_form *f) ;
/**
 *  *
 *   * @todo Describe function
 *    */
int
A4GLPACKER_initlib (void)
{
  return 1;
}

/**
 *  *
 *   * @todo Describe function
 *    */
int
A4GLPacker_A4GL_can_pack_all (char *name)
{
    return 1;
}

/*
 *    We don't need to worry about these two functions
 *       as we're doing the whole thing in one go using xdr
 *       */
int
A4GLPacker_A4GL_open_packer (char *fname, char dir,char *packname)
{
  return 1;
}

void
A4GLPacker_A4GL_close_packer (char dir)
{
  return;
}



int A4GLPacker_A4GL_pack_remove_file(char *fname) {
        char buff[512];
        sprintf (buff, "%s.xml",fname);
        return A4GL_delete_file(buff);
}



/**
 *  *
 *   * @todo Describe function
 *    */
int
A4GLPacker_A4GL_pack_all (char *name, void *s, char *filename)
{
		FILE *ofile;
        if (strcmp(name,"struct_form")==0) {
                char buff[256];
                char *override;
                override=acl_getenv_not_set_as_0("OVERRIDE_OUTPUT");

                if (override) {
                        strcpy(buff,override);
                } else {
                        if (!A4GL_env_option_set ("A4GL_LOCALOUTPUT")) {
                                strcpy(buff,filename);
                        } else {
                                char *ptr;
                              ptr = filename;
                                if (rindex (ptr, '/')) {
                                        ptr = rindex (ptr, '/') + 1;
                                }
                                strcpy(buff,ptr);

                        }
                        strcat(buff,".xml");
                }
                ofile=fopen(buff,"wb");
		if (ofile ) {
			// write_xml_form will close the file for us...
			write_xml_form(ofile, filename, s);
		} else {
			return 0;
		}
	
        	return 1;
        }
	A4GL_assertion(1,"Unhandled datatype for FORMXML packer");
	return 0;

}

