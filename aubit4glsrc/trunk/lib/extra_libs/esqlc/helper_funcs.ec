#include "a4gl_incl_4glhdr.h"
#include "a4gl_libaubit4gl.h"


void copy_decimal(dec_t *infx,fgldecimal *a4gl,int size,char dir) {
debug("Aubit size : %d %d\n",size & 15, size>>4);
if (dir=='i') {
	char *ptr;
	push_dec(a4gl,0);
	ptr=char_pop();
	printf("Ptr=%s",ptr);
}

}



// A4GL datetimes scales range from 0->107
// some of these are not valid - but an array is a quick way to
// look up the corresponding Informix Dtype qualifiers...
int arr_dtime[]={
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  1024, 1538, 2052, 2566, 3080, 3594, 3851, 4108, 4365, 4622, 4879,
  0, 0, 0, 0, 0, 0,
  546, 1060, 1574, 2088, 2602, 2859, 3116, 3373, 3630, 3887,
  0, 0, 0, 0, 0, 0, 0,
  580, 1094, 1608, 2122, 2379, 2636, 2893, 3150, 3407,
  0, 0, 0, 0, 0, 0, 0, 0,
  614, 1128, 1642, 1899, 2156, 2413, 2670, 2927,
  0, 0, 0, 0, 0, 0, 0, 0, 0,
  648, 1162, 1419, 1676, 1933, 2190, 2447,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  682, 939, 1196, 1453, 1710, 1967
  };


void copy_datetime(dtime_t *infx, struct a4gl_dtime *a4gl,int size,int mode) {

	if (mode=='i') {
		char *ptr;
		char buff[255];
		push_dtime(a4gl);
		ptr=char_pop();
		if (size<0||size>107) {
			debug("DATETIME OUT OF RANGE");
			printf("ERROR - SEE DEBUG.OUT");
		}
		infx->dt_qual=arr_dtime[size];
		dtcvasc(ptr,infx);
/*
		printf("Copy datetime in - aubit=%s\n",ptr);
		dttoasc(infx,buff);
		printf("                Informix=%s\n",buff);
*/
		free(ptr);
	}

	if (mode=='o') {
		char buff[255];
		char *ptr;
		int a;
		dttoasc(infx,buff);
		push_char(buff);
		pop_param(a4gl,DTYPE_DTIME,size);

/*
		push_dtime(a4gl);
		ptr=char_pop();
		printf("Copy datetime out - aubit=%s\n",ptr);
		printf("                Informix=%s\n",buff);
		free(ptr);
*/
	}



}
