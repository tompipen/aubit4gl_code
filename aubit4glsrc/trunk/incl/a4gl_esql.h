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
#define SQLDTYPE_0(x) char[x+1]
#define SQLDTYPE_1(x) short
#define SQLDTYPE_2(x) int
#define SQLDTYPE_3(x) double
#define SQLDTYPE_4(x) float
#define SQLDTYPE_5(x) DECIMAL
#define SQLDTYPE_6(x) int
#define SQLDTYPE_7(x) int
#define SQLDTYPE_8(x) MONEY
#define SQLDTYPE_9(x)  // Doesn't exist...
#define SQLDTYPE_10(x) DATETIME
#define SQLDTYPE_11(x) INTERVAL
#define SQLDTYPE_12(x) TEXT
#define SQLDTYPE_13(x) VARCHAR
#define SQLDTYPE_14(x) INTERVAL



#define COPY_DATA_IN_0(infx,a4gl,size) strcpy(*(infx),*(a4gl))
#define COPY_DATA_IN_1(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_2(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_3(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_4(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_5(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_6(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_7(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_8(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_9(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_10(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_11(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_12(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_13(infx,a4gl,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_14(infx,a4gl,size) *(infx)=*(a4gl)

#define COPY_DATA_OUT_0(infx,a4gl,size) strcpy(*(a4gl),*(infx))
#define COPY_DATA_OUT_1(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_2(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_3(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_4(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_5(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_6(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_7(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_8(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_9(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_10(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_11(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_12(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_13(infx,a4gl,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_14(infx,a4gl,size) *(a4gl)=*(infx)

#endif


