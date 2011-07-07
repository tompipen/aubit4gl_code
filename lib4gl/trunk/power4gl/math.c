/******************************************************************************\
 Miscelaneous math functions.
 
 Copyright (C) 2001 John H. Frantz, Pétur K. Hilmarsson.
 
 This file is part of Power-4gl.
 
 Power-4gl is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or   
 (at your option) any later version.
 
 Power-4gl is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with Power-4gl; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
\******************************************************************************/

#include <math.h>
#include <stdio.h>
/*
#include "/usr/informix/incl/decimal.h"
*/

/******************************************************************************\
 Fatal error handling. Message displayed and program terminated.
 Parameters: Error message.
\******************************************************************************/

static void ferr(msg)

char *msg;
{
fprintf(stderr,"%s",msg);
exit(1);
}


/*
aclfgl_cpower(nargs)
  int nargs;
{
dec_t x,y;
double dx,dy;
  if (nargs != 2) ferr("power: wrong number of arguments.");
  popdec(&y);popdec(&x);
  dectodbl(&y,&dy);  dectodbl(&x,&dx);
  printf("x: %f  y: %f",dx,dy);
  dx = pow(dx , dy);
  printf("retv: %f",dx);
  deccvdbl(dx,&x);
  retdec(&x);
  return(1);
}
*/
aclfgl_cpower(nargs)
  int nargs;
{
double x,y;
  if (nargs != 2) ferr("power: wrong number of arguments.");
  popdub(&y); popdub(&x);
  x = x/100000000/100000000;
  y = y/100000000/100000000;
  x = pow(x,y);
  retdub(&x);
  return(1);
}
aclfgl_cpower2(nargs)
  int nargs;
{
double x,y;
  if (nargs != 2) ferr("power: wrong number of arguments.");
  popdub(&y); popdub(&x);
  x = pow(x,y);
  retdub(&x);
  return(1);
}

