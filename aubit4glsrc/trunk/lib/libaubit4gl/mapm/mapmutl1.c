
/* 
 *  M_APM  -  mapmutl1.c
 *
 *  Copyright (C) 2003 Michael C. Ring
 *
 *  Permission to use, copy, and distribute this software and its
 *  documentation for any purpose with or without fee is hereby granted, 
 *  provided that the above copyright notice appear in all copies and 
 *  that both that copyright notice and this permission notice appear 
 *  in supporting documentation.
 *
 *  Permission to modify the software is granted, but not the right to
 *  distribute the modified code.  Modifications are to be distributed 
 *  as patches to released version.
 *  
 *  This software is provided "as is" without express or implied warranty.
 */

/*
 *      $Id: mapmutl1.c,v 1.2 2007-08-25 11:45:04 mikeaubury Exp $
 *
 *      This file contains the utility function 'M_apm_log_error_msg'
 *
 *	This is the only function in this file so a user can supply
 *	their own custom version easily without changing the base library.
 *
 *      $Log: not supported by cvs2svn $
 *      Revision 1.1  2007/07/26 12:04:28  mikeaubury
 *      fix some issues with decimals
 *      fix issue with freeing sql memory
 *      fix REQUIRED on input and input array (set INPUTREQUIREDTYPE=INPUT)
 *      fix character erase in fields
 *      Add ALWAYSOUTPUTREPORT to force a blank page from a report
 *
 *      Revision 1.3  2003/07/21 21:00:34  mike
 *      Modify error messages to be in a consistent format.
 *
 *      Revision 1.2  2003/05/05 18:38:27  mike
 *      fix comment
 *
 *      Revision 1.1  2003/05/04 18:19:14  mike
 *      Initial revision
 */

#include "m_apm_lc.h"
#include "a4gl_libaubit4gl_int.h"

/****************************************************************************/
void	M_apm_log_error_msg(int fatal, char *message)
{
if (fatal)
  {
	
	A4GL_debug("MAPM Error: %s",message);
   	A4GL_exitwith("MAPM Error");
   exit(100);
  }
else
  {
	A4GL_debug("MAPM Warning: %s",message);
   	A4GL_exitwith("MAPM Warning");
  }
}
/****************************************************************************/

