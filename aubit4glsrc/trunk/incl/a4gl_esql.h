/*******************************************************************
* (c) 1997-2002 Aubit Computing Ltd.
*
* This header file should detect the current ESQL/C compiler as
* set the datatype conversion routines as required...
********************************************************************/

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


#define INFORMIX_ESQLC

#ifdef INFORMIX_ESQLC

// Conversion functions between informix types and A4GL datatypes

/*
#define SQLDTYPE_0(v,x) char v[x+1]
#define SQLDTYPE_1(v,x) short v
#define SQLDTYPE_2(v,x) int v
#define SQLDTYPE_3(v,x) double v
#define SQLDTYPE_4(v,x) float v
#define SQLDTYPE_5(v,x) DECIMAL v
#define SQLDTYPE_6(v,x) int v
#define SQLDTYPE_7(v,x) int v
#define SQLDTYPE_8(v,x) MONEY v
#define SQLDTYPE_9(v,x)  // Doesn't exist...
#define SQLDTYPE_10(v,x) DATETIME v
#define SQLDTYPE_11(v,x) INTERVAL v
#define SQLDTYPE_12(v,x) TEXT v
#define SQLDTYPE_13(v,x) VARCHAR v
#define SQLDTYPE_14(v,x) INTERVAL v
*/


void copy_decimal(struct decimal *infx,fgldecimal *a4gl,int size,char dir);

#define COPY_DATA_IN_0(a4gl,infx,size) strcpy(*(infx),*(a4gl))
#define COPY_DATA_IN_1(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_2(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_3(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_4(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_5(a4gl,infx,size) copy_decimal(infx,a4gl,size,'i')
#define COPY_DATA_IN_6(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_7(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_8(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_9(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_10(a4gl,infx,size) copy_datetime(infx,a4gl,size,'i')
#define COPY_DATA_IN_11(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_12(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_13(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_14(a4gl,infx,size) *(infx)=*(a4gl)

#define COPY_DATA_OUT_0(a4gl,infx,size) strcpy(*(a4gl),*(infx))
#define COPY_DATA_OUT_1(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_2(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_3(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_4(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_5(a4gl,infx,size) copy_decimal(infx,a4gl,size,'o')
#define COPY_DATA_OUT_6(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_7(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_8(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_9(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_10(a4gl,infx,size) copy_datetime(infx,a4gl,size,'o')
#define COPY_DATA_OUT_11(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_12(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_13(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_14(a4gl,infx,size) *(a4gl)=*(infx)

#endif


