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



// Conversion functions between informix types and A4GL datatypes
#define COPY_DATA_IN_0(a4gl,pgres,size) strcpy(*(pgres),*(a4gl))
#define COPY_DATA_IN_1(a4gl,pgres,size) *(pgres)=*(a4gl)
#define COPY_DATA_IN_2(a4gl,pgres,size) *(pgres)=*(a4gl)
#define COPY_DATA_IN_3(a4gl,pgres,size) *(pgres)=*(a4gl)
#define COPY_DATA_IN_4(a4gl,pgres,size) *(pgres)=*(a4gl)
#define COPY_DATA_IN_5(a4gl,pgres,size) exitwith("NIY - I5")

#define COPY_DATA_IN_6(a4gl,pgres,size) *(pgres)=*(a4gl)
#define COPY_DATA_IN_7(a4gl,pgres,size) *(pgres)=*(a4gl)
#define COPY_DATA_IN_8(a4gl,pgres,size) exitwith("NIY - I8")

#define COPY_DATA_IN_9(a4gl,pgres,size) *(pgres)=*(a4gl)
#define COPY_DATA_IN_10(a4gl,pgres,size) exitwith("NIY - I10")
#define COPY_DATA_IN_11(a4gl,pgres,size) exitwith("NIY - I11")
#define COPY_DATA_IN_12(a4gl,pgres,size) exitwith("NIY - I12")
#define COPY_DATA_IN_13(a4gl,pgres,size) strcpy(*(pgres),*(a4gl))
#define COPY_DATA_IN_14(a4gl,pgres,size) exitwith("NIY - I14")
#define COPY_DATA_OUT_0(a4gl,pgres,size) strcpy(*(a4gl),*(pgres))
#define COPY_DATA_OUT_1(a4gl,pgres,size) *(a4gl)=*(pgres)
#define COPY_DATA_OUT_2(a4gl,pgres,size) *(a4gl)=*(pgres)
#define COPY_DATA_OUT_3(a4gl,pgres,size) *(a4gl)=*(pgres)
#define COPY_DATA_OUT_4(a4gl,pgres,size) *(a4gl)=*(pgres)
#define COPY_DATA_OUT_5(a4gl,pgres,size) copy_decimal(pgres,a4gl,size,'o')
#define COPY_DATA_OUT_6(a4gl,pgres,size) *(a4gl)=*(pgres)
#define COPY_DATA_OUT_7(a4gl,pgres,size) *(a4gl)=*(pgres)
#define COPY_DATA_OUT_8(a4gl,pgres,size) copy_money(pgres,a4gl,size,'o')
#define COPY_DATA_OUT_9(a4gl,pgres,size) *(a4gl)=*(pgres)
#define COPY_DATA_OUT_10(a4gl,pgres,size) copy_datetime(pgres,a4gl,size,'o')
#define COPY_DATA_OUT_11(a4gl,pgres,size) copy_blob_byte(pgres,a4gl,size,'o')
#define COPY_DATA_OUT_12(a4gl,pgres,size) copy_blob_text(pgres,a4gl,size,'o')
#define COPY_DATA_OUT_13(a4gl,pgres,size) *strcpy(*(a4gl),*(pgres))
#define COPY_DATA_OUT_14(a4gl,pgres,size) copy_interval(pgres,a4gl,size,'o')


#define copy_sqlca
