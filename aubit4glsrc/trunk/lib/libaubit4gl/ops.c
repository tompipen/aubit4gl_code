/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: ops.c,v 1.8 2003-02-28 17:43:15 mikeaubury Exp $
#
*/

/**
 * @file
 * Data type operations functions
 *
 * This is complex stuff
 * What we want to be able to do is add datatypes programatically
 * We therefor maintain a list of available datatypes
 * and their various conversion routines..
 *
 * This is very much a work in progress....
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_libaubit4gl_int.h"


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void int_int_ops(int op) ;
#ifdef OLD_INCL
	void push_long(long a);
	void push_int(int a);
#endif
void add_default_operations(void) ;
void dt_in_ops(int op);
void in_dt_ops(int op);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/
/**
 * Add all the default operations to the system
 *
 * @return
 */
void
dt_in_ops(int op)
{
struct a4gl_dtime dt;
struct ival in;
int ival_data[10];
	
	#ifdef DEBUG
		debug("In dt_in_ops");
    #endif
	printf("DTIN Here\n");
	fflush(stdout);
	pop_param(&in,DTYPE_INTERVAL,-1);
	pop_param(&dt,DTYPE_DTIME,-1);
	printf("DTIN Here2\n");
	fflush(stdout);

	decode_interval (&in, &ival_data[0]);
	printf("Interval : Y=%d\n",ival_data[0]);
	printf("Interval : M=%d\n",ival_data[1]);
	
	printf("Interval : D=%d\n",ival_data[2]);
	printf("Interval : H=%d\n",ival_data[3]);
	printf("Interval : M=%d\n",ival_data[4]);
	printf("Interval : S=%d\n",ival_data[5]);
	printf("Interval : F=%d\n",ival_data[6]);
	fflush(stdout);




	push_int(0);
}

/**
 * Add all the default operations to the system
 *
 * @return
 */
void
in_dt_ops(int op)
{
struct a4gl_dtime dt;
struct ival in;
int ival_data[10];
int dtime_data[10];
int d1;
int s1;
void *ptr1;
struct ival *pi;
struct a4gl_dtime *pd;
int ok=0;
char buff[256];
int start;
char *ptr;

	get_top_of_stack (2, &d1, &s1, (void **) &pd);

	get_top_of_stack (1, &d1, &s1, (void **) &pi);


	if ((d1&DTYPE_MASK)!=DTYPE_INTERVAL) {
		printf("Confused... %d != %d\n",d1&DTYPE_MASK,DTYPE_INTERVAL);
	}


	in.stime=pi->stime;
	in.ltime=pi->ltime;
	dt.stime=pd->stime;
	dt.ltime=pd->ltime;
	pop_var2(&in,DTYPE_INTERVAL,in.stime*16+in.ltime);


	pop_param(&dt,DTYPE_DTIME,dt.stime*16+dt.ltime);


	decode_interval (&in, &ival_data[0]);
/*
	printf("\n\nInterval : Y=%d\n",ival_data[0]);
	printf("Interval : M=%d\n",ival_data[1]);
	printf("Interval : D=%d\n",ival_data[2]);
	printf("Interval : H=%d\n",ival_data[3]);
	printf("Interval : M=%d\n",ival_data[4]);
	printf("Interval : S=%d\n",ival_data[5]);
	printf("Interval : F=%d\n",ival_data[6]);
*/

	decode_datetime (&dt, &dtime_data[0]);

/*
	printf("Datetime : Y=%d\n",dtime_data[0]);
	printf("Datetime : M=%d\n",dtime_data[1]);
	printf("Datetime : D=%d\n",dtime_data[2]);
	printf("Datetime : H=%d\n",dtime_data[3]);
	printf("Datetime : M=%d\n",dtime_data[4]);
	printf("Datetime : S=%d\n",dtime_data[5]);
	printf("Datetime : F=%d\n",dtime_data[6]);
*/

	switch(op) {
		case OP_ADD:
			// Fractions
			dtime_data[6]+=ival_data[6];
			if (dtime_data[6]>99999) {
				dtime_data[5]++;
				dtime_data[6]-=100000;
			}

			// Seconds
			dtime_data[5]+=ival_data[5];
			if (dtime_data[5]>60) { dtime_data[4]++; dtime_data[5]-=60; }

			// Minutes
			dtime_data[4]+=ival_data[4];
			if (dtime_data[4]>60) { dtime_data[3]++; dtime_data[4]-=60; }

			// Hours
			dtime_data[3]+=ival_data[3];
			if (dtime_data[3]>24) { dtime_data[2]++; dtime_data[3]-=24; }

			// Days
			dtime_data[2]+=ival_data[2];
			if (dtime_data[2]>30) { dtime_data[1]++; dtime_data[2]-=30; /** @todo Fix this **/ }

			// Months
			dtime_data[1]+=ival_data[1];
			if (dtime_data[1]>12) { dtime_data[0]++; dtime_data[1]-=12; }

			// Years
			dtime_data[0]+=ival_data[0];
			ok=1;
			break;

		case OP_SUB:
			// Fractions
			dtime_data[6]-=ival_data[6];
			if (dtime_data[6]<0) {
				dtime_data[5]--;
				dtime_data[6]+=100000;
				printf("Carry F\n");
			}

			// Seconds
			dtime_data[5]-=ival_data[5];
			if (dtime_data[5]<0) { dtime_data[4]--; dtime_data[5]+=60; printf("Carry S\n"); }

			// Minutes
			dtime_data[4]-=ival_data[4];
			if (dtime_data[4]<0) { dtime_data[3]--; dtime_data[4]+=60; printf("Carry M\n");}

			// Hours
			dtime_data[3]-=ival_data[3];
			if (dtime_data[3]<0) { dtime_data[2]--; dtime_data[3]+=24; printf("Carry H\n");}

			if (dt.stime<=3) {
			// Days
			dtime_data[2]-=ival_data[2];
			if (dtime_data[2]<=1) { dtime_data[1]--; dtime_data[2]+=30; /** @todo Fix this **/ printf("Carry D\n"); }
			}

			if (dt.stime<=2) {
				// Months
				dtime_data[1]-=ival_data[1];
				if (dtime_data[1]<=1) { dtime_data[0]--; dtime_data[1]+=12; printf("Carry M\n");}
			}

			if (dt.stime<=1) {
				// Years
				dtime_data[0]-=ival_data[0];
			}


			ok=1;
			break;
	}

	if (ok) {
		sprintf(buff,"%04d-%02d-%02d %02d:%02d:%02d.%05d",
				dtime_data[0],
				dtime_data[1],
				dtime_data[2],
				dtime_data[3],
				dtime_data[4],
				dtime_data[5],
				dtime_data[6]);

		start=0;
		if (dtime_data[0]>0&&!start) start=1;
		if (dtime_data[1]>0&&!start) start=2;
		if (dtime_data[2]>0&&!start) start=3;
		if (dtime_data[3]>0&&!start) start=4;
		if (dtime_data[4]>0&&!start) start=4;
		if (dtime_data[5]>0&&!start) start=4;
		if (dtime_data[6]>0&&!start) start=4; 


		//0123456789012345678901234
		//0000-MM-30 23:57:10.00000

		switch (start) {
			case 1: ptr=&buff[0];break;
			case 2: ptr=&buff[5];break;
			case 3: ptr=&buff[8];break;
			case 4: ptr=&buff[11];break;
			case 5: ptr=&buff[14];break;
			case 6: ptr=&buff[17];break;
			case 7: ptr=&buff[18];break;
		}
			
		dt.stime=start;
		//dt.ltime=11;

/*
		switch(dt.ltime) {
			case 1: buff[4]=0;break; //Y
			case 2: buff[7]=0;break; //M
			case 3: buff[10]=0;break; //D
			case 4: buff[13]=0;break; //H
			case 5: buff[16]=0;break; //M
			case 6: buff[19]=0;break; //D
		}
*/

		ctodt(ptr,&dt,dt.stime*16+dt.ltime);
	
		push_dtime(&dt);
		return;
	}



	push_int(0);
}


/**
 *
 *
 * @return
 */
void
int_int_ops(int op) 
{
long a;
long b;
long c;
long d;
	
	b=pop_long();
	a=pop_long();

    #ifdef DEBUG
		debug("int_int_ops : %d %d %d",a,b,op);
    #endif

	switch (op) {
		case OP_ADD: 			push_long(a+b); return;
		case OP_SUB: 			push_long(a-b); return;
		case OP_MULT: 			push_long(a*b); return;


		case OP_DIV:
		if (a%b==0) {
			push_long(a/b); return;
		} else {
			push_double((double)a/(double)b); return;
		}

		case OP_MOD: 			push_long(a%b); return;
		case OP_POWER:
			if (b==0) {push_long(1); return;}
			if (b==1) {push_long(a); return;}
			c=a;
			for (d=1;d<=b;d++) c*=b;
			push_long(c);
			return;

		case OP_LESS_THAN: 		push_int(a<b); return;
		case OP_GREATER_THAN: 		push_int(a>b); return;
		case OP_LESS_THAN_EQ: 		push_int(a<=b); return;
		case OP_GREATER_THAN_EQ: 	push_int(a>=b); return;
		case OP_EQUAL: 			push_int(a==b); return;
		case OP_NOT_EQUAL: 		push_int(a!=b); return;
	}

	exitwith("Unknown operation");
	push_int(0);
return ;
}



/**
 * Add all the default operations to the system
 *
 * @return
 */
void
dt_dt_ops(int op)
{
struct a4gl_dtime dt2;
struct a4gl_dtime dt1;
int dtime_data1[10];
int dtime_data2[10];
int d1;
int s1;
void *ptr1;
struct a4gl_dtime *pi;
struct a4gl_dtime *pd;
int ok=0;
char buff[256];
int start;
char *ptr;
double d_d1;
double d_d2;

if (op != (OP_SUB)) {
	push_int(0);
}
// d2 - d1
	get_top_of_stack (2, &d1, &s1, (void **) &pd);

	get_top_of_stack (1, &d1, &s1, (void **) &pi);


	if ((d1&DTYPE_MASK)!=DTYPE_DTIME) {
		printf("Confused... %d != %d\n",d1&DTYPE_MASK,DTYPE_DTIME);
	}


	dt1.stime=pi->stime;
	dt1.ltime=pi->ltime;

	dt2.stime=pd->stime;
	dt2.ltime=pd->ltime;

	pop_param(&dt1,DTYPE_DTIME,dt1.stime*16+dt2.ltime);
	pop_param(&dt2,DTYPE_DTIME,dt1.stime*16+dt2.ltime);


	decode_datetime (&dt1, &dtime_data1[0]);
	decode_datetime (&dt2, &dtime_data2[0]);
	dtime_data2[0]-=dtime_data1[0]; // Y
	dtime_data2[1]-=dtime_data1[1]; //
	dtime_data2[2]-=dtime_data1[2];
	dtime_data2[3]-=dtime_data1[3];
	dtime_data2[4]-=dtime_data1[4];
	dtime_data2[5]-=dtime_data1[5];

// Borrow some seconds for fractions
	while (dtime_data2[6]<0) { dtime_data2[6]+=100000; dtime_data2[5]--; }

// Borrow some minutes for seconds
	while (dtime_data2[5]<0) { dtime_data2[5]+=60; dtime_data2[4]--; }

// Borrow some hours for minutes
	while (dtime_data2[4]<0) { dtime_data2[4]+=60; dtime_data2[3]--; }

// Borrow some days for some hours..
	while (dtime_data2[3]<0) { dtime_data2[3]+=24; dtime_data2[2]--; }

// Borrow some months for some days. @ FIXME @todo fix days in months
	while (dtime_data2[2]<0) { dtime_data2[2]+=30; dtime_data2[1]--; }

// Borrow some years for some months.
	while (dtime_data2[1]<0) { dtime_data2[1]+=12; dtime_data2[0]--; }

	if (dtime_data2[0]||dtime_data2[1]) {
		// YEAR TO MONTH interval
		sprintf(buff,"%4d-%02d",dtime_data2[0],dtime_data2[1]);
	} else {
		sprintf(buff,"%d %02d:%02d:%02d.%05d",dtime_data2[2],dtime_data2[3],dtime_data2[4],dtime_data2[5],dtime_data2[6]);
	}
 
	push_char(buff);
}

/**
 *
 *
 * @return
 */
void
add_default_operations(void) 
{


/* Integer functions 
this covers all possibilities of
DTYPE_INT
DTYPE_SMINT
DTYPE_DATE
DTYPE_SERIAL
*/

	add_op_function(DTYPE_INT,	DTYPE_INT,	OP_MATH,int_int_ops);

	add_op_function(DTYPE_SMINT,	DTYPE_SMINT,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_INT,	DTYPE_SMINT,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_SMINT,	DTYPE_INT,	OP_MATH,int_int_ops);

	add_op_function(DTYPE_DATE,	DTYPE_DATE,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_INT,	DTYPE_DATE,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_SMINT,	DTYPE_DATE,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_DATE,	DTYPE_SMINT,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_DATE,	DTYPE_INT,	OP_MATH,int_int_ops);

	add_op_function(DTYPE_SERIAL,	DTYPE_SERIAL,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_SERIAL,	DTYPE_INT,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_SERIAL,	DTYPE_SMINT,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_SERIAL,	DTYPE_DATE,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_INT,	DTYPE_SERIAL,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_SMINT,	DTYPE_SERIAL,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_DATE,	DTYPE_SERIAL,	OP_MATH,int_int_ops);

	add_op_function(DTYPE_INTERVAL,	DTYPE_DTIME,	OP_MATH,dt_in_ops);
	add_op_function(DTYPE_DTIME,	DTYPE_INTERVAL,	OP_MATH,in_dt_ops);
	add_op_function(DTYPE_DTIME,	DTYPE_DTIME,	OP_MATH,dt_dt_ops);

	debug("Finished adding default operations");


}


/* ========================== EOF ========================== */
