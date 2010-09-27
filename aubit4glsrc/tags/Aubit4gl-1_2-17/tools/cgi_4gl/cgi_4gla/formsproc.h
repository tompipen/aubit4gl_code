/*
 * Copyright (c) 1995 Brigham Young University.  All rights reserved.
 * 
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the 
 * above copyright notice and the following two paragraphs appear in 
 * all copies of this software.
 *
 * IN NO EVENT SHALL BRIGHAM YOUNG UNIVERSITY BE LIABLE TO ANY PARTY
 * FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF BRIGHAM YOUNG UNIVERSITY HAS BEEN ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * BRIGHAM YOUNG UNIVERSITY SPECIFICALLY DISCLAIMS ANY WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER
 * IS ON AN "AS IS" BASIS, AND BRIGHAM YOUNG UNIVERSITY HAS NO OBLIGATION
 * TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 */

/****************************************************************************
 * BRIAN K. HOLMAN             * E-Mail:               brian_holman@byu.edu *
 * Programmer/Systems Analyst  * URL: http://library.byu.edu/staff/bkh.html *
 * Library Information Systems * Mail:           2330 HBLL, Provo, UT 84602 *
 * Brigham Young University    * Phone:                      (801) 378-8162 *
 ****************************************************************************/

/* Constants */
#define ENTRY_SIZE  128
#define LF 10
#define CR 13
#define MAX_ENTRIES 1000

/* Type Definitions */
typedef struct
{
  char *name;
  char *val;
}
form_entry;

typedef struct
{
  char name[ENTRY_SIZE];
  char val[ENTRY_SIZE];
}
cmdln_entry;

/* Function Prototypes */
int load_form_entries ();
void free_form_entries ();
char *retrieve_form_entry (char *field_name);
int load_cmdln_entries ();
char *retrieve_cmdln_entry (char *field_name);
char *A4GL_trim (char *trim_str);
