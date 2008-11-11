/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: clobber.c,v 1.4 2008-11-11 17:56:35 mikeaubury Exp $
#
*/

#include "a4gl_4glc_int.h"

/*
struct s_exchange_clobber
{
  char *orig;
  char *new;
  char *important;
};

struct s_exchange_clobber *mod->clobberings.clobberings_val = 0;
int mod->clobberings.clobberings_len = 0;
*/


static int
has_clobber (module_definition *mod, char *s)
{
  int a;
  if (mod->clobberings.clobberings_len == 0)
    return 0;
  for (a = 0; a < mod->clobberings.clobberings_len; a++)
    {
      if (strcmp (mod->clobberings.clobberings_val[a].orig, s) == 0)
	{
	  return 1;
	}
    }
  return 0;
}


static char *
get_clobber (module_definition *mod, char *s)
{
  int a;
  if (mod->clobberings.clobberings_len == 0)
    return s;
  for (a = 0; a < mod->clobberings.clobberings_len; a++)
    {
      if (strcmp (mod->clobberings.clobberings_val[a].orig, s) == 0)
	{
	  return mod->clobberings.clobberings_val[a].new;
	}
    }
  return s;
}

char *
A4GL_get_important_from_clobber (module_definition *mod, char *s)
{
  int a;
  if (mod->clobberings.clobberings_len == 0)
    return s;
  for (a = 0; a < mod->clobberings.clobberings_len; a++)
    {
      if (strcmp (mod->clobberings.clobberings_val[a].orig, s) == 0)
	{
	  return mod->clobberings.clobberings_val[a].important;
	}
    }
  return s;
}



char *
A4GL_get_clobber_from_orig (module_definition *mod, char *s)
{
  int a;
  if (mod->clobberings.clobberings_len == 0)
    return s;
  for (a = 0; a < mod->clobberings.clobberings_len; a++)
    {
      if (strcmp (mod->clobberings.clobberings_val[a].new, s) == 0)
	{
	  return mod->clobberings.clobberings_val[a].orig;
	}
    }
  return s;
}


static char *
add_clobber (module_definition *mod, char *buff_orig, char *important)
{
  static char buff_new[256];
  static int p = 0;
  char b1[256];

  strcpy (buff_new, buff_orig);

  if (has_clobber (mod, buff_orig))
    return get_clobber (mod, buff_orig);

  mod->clobberings.clobberings_len++;
  mod->clobberings.clobberings_val =
    acl_realloc (mod->clobberings.clobberings_val, sizeof (struct s_exchange_clobber) * mod->clobberings.clobberings_len);
  if (mod->clobberings.clobberings_val == 0)
    {
      a4gl_yyerror ("Unable to allocate buffer...");
      return 0;
    }



  if (strlen (buff_orig) <= 20)
    {				/* Extra 2 for the quotes... */
      mod->clobberings.clobberings_val[mod->clobberings.clobberings_len - 1].orig = acl_strdup (buff_orig);
      mod->clobberings.clobberings_val[mod->clobberings.clobberings_len - 1].new = acl_strdup (buff_new);
      mod->clobberings.clobberings_val[mod->clobberings.clobberings_len - 1].important = acl_strdup (important);
      return buff_orig;
    }

  strcpy (b1, important);
  b1[9] = 0;
  SPRINTF2 (buff_new, "a4gl_%03d_%s", p++, b1);
  mod->clobberings.clobberings_val[mod->clobberings.clobberings_len - 1].orig = acl_strdup (buff_orig);
  mod->clobberings.clobberings_val[mod->clobberings.clobberings_len - 1].new = acl_strdup (buff_new);
  mod->clobberings.clobberings_val[mod->clobberings.clobberings_len - 1].important = acl_strdup (important);
  return buff_new;
}

char *
do_clobbering (module_definition *mod, char *f, char *s)
{
  static char buff[256];
int l;
int a;
  if (A4GL_isyes (acl_getenv ("A4GL_NOCLOBBER")))
    {
      SPRINTF1 (buff, "%s", s);
      if (!has_clobber (mod, buff))
	{
	  add_clobber (mod, buff, s);
	}
      return buff;
    }

  if (strlen(f)) {
  	SPRINTF2 (buff, "%s_%s", f, s);
  } else {
  	SPRINTF1 (buff, "%s",  s);
  }
  l=strlen(buff);
  for (a=0;a<l;a++) {
	if (buff[a]>='a'&& buff[a]<='z') continue;
	if (buff[a]>='A'&& buff[a]<='Z') continue;
	if (buff[a]>='0'&& buff[a]<='9') continue;
	if (buff[a]=='_') continue;
	buff[a]='_';
  }

  if (A4GL_isyes (acl_getenv ("A4GL_ALWAYSCLOBBER")))
    {
      if (!has_clobber (mod, buff))
	{
	  add_clobber (mod, buff, s);
	}
      return buff;
    }

  if (has_clobber (mod, buff))
    {
      return get_clobber (mod, buff);
    }
  return add_clobber (mod, buff, s);
}

char *
do_clobbering_sql (module_definition *mod, char *f, char *s)
{
  static char buff[256];
int a;
int l;

  if (A4GL_isyes (acl_getenv ("A4GL_NOSQLCLOBBER")))
    {
      SPRINTF1 (buff, "%s", s);
      if (!has_clobber (mod, buff))
	{
	  add_clobber (mod, buff, s);
	}
      return buff;
    }

  if (strlen(f)) {
	if (f[0]>='a'&&f[a]<='z' || f[0]>='A'&&f[a]<='Z') {
  		SPRINTF2 (buff, "%s_%s", f, s);
	} else {
  		SPRINTF2 (buff, "a%s_%s", f, s);
	}
  } else {
  	SPRINTF1 (buff, "%s",  s);
  }

  l=strlen(buff);
  for (a=0;a<l;a++) {
	if (buff[a]>='a' && buff[a]<='z') continue;
	if (buff[a]>='A' && buff[a]<='Z') continue;
	if (buff[a]>='0'&& buff[a]<='9') continue;
	if (buff[a]=='_') continue;
	buff[a]='_';
  }
  if (A4GL_isyes (acl_getenv ("A4GL_ALWAYSSQLCLOBBER")))
    {
      if (!has_clobber (mod, buff))
	{
	  add_clobber (mod, buff, s);
	}
      return buff;
    }

  if (has_clobber (mod, buff))
    {
      return get_clobber (mod, buff);
    }
  return add_clobber (mod, buff, s);
}



