/*******************************************************************************
 SCCS ID : @(#) Mod: random.c Ver: 1.2 Date: 08/13/99 17:01:19
*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int aclfgl_randomize();

int aclfgl_randomize()
{
time_t t;

	srand((unsigned) time(&t));
	return(0);
}

int aclfgl_rnd(noargs)
{
int c;
int modulus;

	popint(&modulus);
	c = rand() % modulus;
	pushint(c);
  	return(1);   
}
