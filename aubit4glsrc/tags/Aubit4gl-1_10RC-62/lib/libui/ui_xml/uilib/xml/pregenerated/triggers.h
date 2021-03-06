/* XML processor/application API for triggers.dtd.
 * Generated 2009/05/27 18:27:43.
 *
 * This program was generated with the FleXML XML processor generator.
 * FleXML is Copyright (C) 1999-2005 Kristoffer Rose.  All rights reserved.
 * FleXML is Copyright (C) 2003-2006 Martin Quinson.  All rights reserved.
 * (Id: flexml.pl,v 1.61 2006/09/13 16:34:33 wdowling Exp).
 * 
 * There are two, intertwined parts to this program, part A and part B.
 *
 * Part A
 * ------
 * 
 * Some parts, here collectively called "Part A", are found in the 
 * FleXML package.  They are Copyright (C) 1999-2005 Kristoffer Rose
 * and Copyright (C) 2003-2006 Martin Quinson. All rights reserved.
 *
 * You can redistribute, use, perform, display and/or modify "Part A"
 * provided the following two conditions hold:
 *
 * 1. The program is distributed WITHOUT ANY WARRANTY from the author of
 *    FleXML; without even the implied warranty of MERCHANTABILITY or
 *    FITNESS FOR A PARTICULAR PURPOSE.
 *
 * 2. The program distribution conditions do not in any way affect the
 *    distribution conditions of the FleXML system used to generate this
 *    file or any version of FleXML derived from that system.
 *
 * Notice that these are explicit rights granted to you for files
 * generated by the FleXML system.  For your rights in connection with
 * the FleXML system itself please consult the GNU General Public License.
 * 
 * Part B
 * ------
 * 
 * The other parts, here collectively called "Part B", and which came 
 * from the DTD used by FleXML to generate this program, can be 
 * distributed (or not, as the case may be) under the terms of whoever
 * wrote them, provided these terms respect and obey the two conditions 
 * above under the heading "Part A".
 *
 * The author of and contributors to FleXML specifically disclaim
 * any copyright interest in "Part B", unless "Part B" was written 
 * by the author of or contributors to FleXML.
 * 
 */

#ifndef _FLEXML_triggers_H
#define _FLEXML_triggers_H

/* XML application entry points. */
extern void STag_TRIGGERED(void);
extern void ETag_TRIGGERED(void);
extern void STag_SYNCROWS(void);
extern void ETag_SYNCROWS(void);
extern void STag_ROW(void);
extern void ETag_ROW(void);
extern void STag_SYNCVALUES(void);
extern void ETag_SYNCVALUES(void);
extern void STag_SYNCVALUE(void);
extern void ETag_SYNCVALUE(void);

/* XML application data. */
typedef int AT_TRIGGERED_SCRLINE;
#define AU_TRIGGERED_SCRLINE NULL
typedef int AT_TRIGGERED_INFIELD;
#define AU_TRIGGERED_INFIELD NULL
typedef int AT_TRIGGERED_ARRLINE;
#define AU_TRIGGERED_ARRLINE NULL
typedef int AT_SYNCVALUE_TOUCHED;
#define AU_SYNCVALUE_TOUCHED NULL
typedef int AT_TRIGGERED_BUFFERTOUCHED;
#define AU_TRIGGERED_BUFFERTOUCHED NULL
typedef int AT_TRIGGERED_ARRCOUNT;
#define AU_TRIGGERED_ARRCOUNT NULL
typedef int AT_TRIGGERED_ID;
#define AU_TRIGGERED_ID NULL
typedef int AT_TRIGGERED_LASTCURSOR;
#define AU_TRIGGERED_LASTCURSOR NULL
typedef int AT_ROW_SUBSCRIPT;
#define AU_ROW_SUBSCRIPT NULL
typedef int AT_TRIGGERED_LASTKEY;
#define AU_TRIGGERED_LASTKEY NULL
typedef int AT_TRIGGERED_FILEID;
#define AU_TRIGGERED_FILEID NULL
typedef int AT_TRIGGERED_DATA;
#define AU_TRIGGERED_DATA NULL
typedef int AT_TRIGGERED_xmlns_c_xsd;
#define AU_TRIGGERED_xmlns_c_xsd NULL
typedef int AT_SYNCVALUE_FIELDNAME;
#define AU_SYNCVALUE_FIELDNAME NULL
typedef int AT_SYNCVALUE_FIELDTYPE;
#define AU_SYNCVALUE_FIELDTYPE NULL
typedef int AT_TRIGGERED_TYPE;
#define AU_TRIGGERED_TYPE NULL
typedef int AT_TRIGGERED_xmlns_c_xsi;
#define AU_TRIGGERED_xmlns_c_xsi NULL
typedef int AT_TRIGGERED_FILELEN;
#define AU_TRIGGERED_FILELEN NULL
typedef int AT_TRIGGERED_PROGRAMNAME;
#define AU_TRIGGERED_PROGRAMNAME NULL

/* FleXML-provided data. */
extern int pcdata_ix;
extern char *bufferstack;
#define pcdata (bufferstack + pcdata_ix)
extern AT_TRIGGERED_SCRLINE AX_TRIGGERED_SCRLINE;
#define A_TRIGGERED_SCRLINE (bufferstack + AX_TRIGGERED_SCRLINE)
extern AT_TRIGGERED_INFIELD AX_TRIGGERED_INFIELD;
#define A_TRIGGERED_INFIELD (bufferstack + AX_TRIGGERED_INFIELD)
extern AT_TRIGGERED_ARRLINE AX_TRIGGERED_ARRLINE;
#define A_TRIGGERED_ARRLINE (bufferstack + AX_TRIGGERED_ARRLINE)
extern AT_SYNCVALUE_TOUCHED AX_SYNCVALUE_TOUCHED;
#define A_SYNCVALUE_TOUCHED (bufferstack + AX_SYNCVALUE_TOUCHED)
extern AT_TRIGGERED_BUFFERTOUCHED AX_TRIGGERED_BUFFERTOUCHED;
#define A_TRIGGERED_BUFFERTOUCHED (bufferstack + AX_TRIGGERED_BUFFERTOUCHED)
extern AT_TRIGGERED_ARRCOUNT AX_TRIGGERED_ARRCOUNT;
#define A_TRIGGERED_ARRCOUNT (bufferstack + AX_TRIGGERED_ARRCOUNT)
extern AT_TRIGGERED_ID AX_TRIGGERED_ID;
#define A_TRIGGERED_ID (bufferstack + AX_TRIGGERED_ID)
extern AT_TRIGGERED_LASTCURSOR AX_TRIGGERED_LASTCURSOR;
#define A_TRIGGERED_LASTCURSOR (bufferstack + AX_TRIGGERED_LASTCURSOR)
extern AT_ROW_SUBSCRIPT AX_ROW_SUBSCRIPT;
#define A_ROW_SUBSCRIPT (bufferstack + AX_ROW_SUBSCRIPT)
extern AT_TRIGGERED_LASTKEY AX_TRIGGERED_LASTKEY;
#define A_TRIGGERED_LASTKEY (bufferstack + AX_TRIGGERED_LASTKEY)
extern AT_TRIGGERED_FILEID AX_TRIGGERED_FILEID;
#define A_TRIGGERED_FILEID (bufferstack + AX_TRIGGERED_FILEID)
extern AT_TRIGGERED_DATA AX_TRIGGERED_DATA;
#define A_TRIGGERED_DATA (bufferstack + AX_TRIGGERED_DATA)
extern AT_TRIGGERED_xmlns_c_xsd AX_TRIGGERED_xmlns_c_xsd;
#define A_TRIGGERED_xmlns_c_xsd (bufferstack + AX_TRIGGERED_xmlns_c_xsd)
extern AT_SYNCVALUE_FIELDNAME AX_SYNCVALUE_FIELDNAME;
#define A_SYNCVALUE_FIELDNAME (bufferstack + AX_SYNCVALUE_FIELDNAME)
extern AT_SYNCVALUE_FIELDTYPE AX_SYNCVALUE_FIELDTYPE;
#define A_SYNCVALUE_FIELDTYPE (bufferstack + AX_SYNCVALUE_FIELDTYPE)
extern AT_TRIGGERED_TYPE AX_TRIGGERED_TYPE;
#define A_TRIGGERED_TYPE (bufferstack + AX_TRIGGERED_TYPE)
extern AT_TRIGGERED_xmlns_c_xsi AX_TRIGGERED_xmlns_c_xsi;
#define A_TRIGGERED_xmlns_c_xsi (bufferstack + AX_TRIGGERED_xmlns_c_xsi)
extern AT_TRIGGERED_FILELEN AX_TRIGGERED_FILELEN;
#define A_TRIGGERED_FILELEN (bufferstack + AX_TRIGGERED_FILELEN)
extern AT_TRIGGERED_PROGRAMNAME AX_TRIGGERED_PROGRAMNAME;
#define A_TRIGGERED_PROGRAMNAME (bufferstack + AX_TRIGGERED_PROGRAMNAME)

/* XML application utilities. */
extern int element_context(int);

/* XML processor entry point. */
extern int yylex(void);

/* Flexml error handling function (useful only when -q flag passed to flexml) */
const char * parse_err_msg(void);
#endif
