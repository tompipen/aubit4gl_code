/*******************************************************************************
 *                                                                             *
 *   fgl_mqfunc contains the following functions                               *
 *                                                                             *
 *      fgl_mqstatus()                                                         *
 *      fgl_mqreason()                                                         *
 *      fgl_mqerrmsg()                                                         *
 *                                                                             *
 *      fgl_mqconnect()                                                        *
 *      fgl_mqdisconnect()                                                     *
 *      fgl_mqopen()                                                           *
 *      fgl_mqopen4write()                                                     *
 *      fgl_mqopen4read()                                                      *
 *      fgl_mqclose()                                                          *
 *      fgl_mqwrite()                                                          *
 *      fgl_mqread()                                                           *
 *      fgl_mqrecieve()                                                        *
 *                                                                             *
 *      fgl_mqwriteimmediate()                                                 *
 *                                                                             *
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* includes for MQI */
#include "/usr/mqm/inc/cmqc.h"
#include "mqcmh.h"
/* includes for Informix 4GL */
#include <fglsys.h>
#include <ifxtypes.h>

#define QMSIZE 50
#define QUSIZE 50
#define STSIZE 512

/* Global static variables */
static long mqReason;
static long mqStatus;
static char mqErrmsg[81];


/*******************************************************************************
 *                                                                             *
 * fgl_mqstatus:  Return last Completion Code                                  *
 * fgl_mqreason:  Return last Reason Code                                      *
 * fgl_mqerrmsg:  Return last Reason Name                                      *
 *                                                                             *
 * 4GL: CALL fgl_mqstatus() returning mq_status                                *
 * 4GL: LET mq_status = fgl_mqstatus(codenum)                                  *
 *                                                                             *
 *******************************************************************************/

int fgl_mqstatus(int nargs)
{
  ibm_lib4gl_returnInt4(mqStatus);
  return(1);
}

int fgl_mqreason(int nargs)
{
  ibm_lib4gl_returnInt4(mqReason);
  return(1);
}

int fgl_mqerrmsg(int nargs)
{
  if (nargs == 1)
    ibm_lib4gl_popInt4(&mqReason);
  if (mqReason > 0)
    MQReasonCodeMsg(mqReason, mqErrmsg);
  ibm_lib4gl_returnString(mqErrmsg);
  return(1);
}


/*******************************************************************************
 *                                                                             *
 * fgl_mqconnect:  Connect to queue manager                                    *
 *                                                                             *
 * 4GL: CALL fgl_mqconnect() returning connectHandle                           *
 * 4GL: CALL fgl_mqconnect('queueManager') returning connectHandle             *
 *                                                                             *
 *******************************************************************************/

int fgl_mqconnect(int nargs)
{
  char     QMName[MQ_Q_MGR_NAME_LENGTH];    /* queue manager name     */
  MQHCONN  Hcon;                            /* connection handle      */

  if (nargs > 0)
    ibm_lib4gl_popString(QMName,MQ_Q_MGR_NAME_LENGTH);
  else
    QMName[0] = '\0';             /* use default queue manager      */

  MQCONN(QMName,                  /* queue manager                  */
         &Hcon,                   /* connection handle              */
         &mqStatus,               /* completion code                */
         &mqReason);               /* reason code                    */

  /* report reason and stop if it failed     */
  if ((mqStatus != MQCC_OK) || (mqReason != MQRC_NONE))
  {
    ibm_lib4gl_returnInt4(0);
    return(1);
  }
  ibm_lib4gl_returnInt4(Hcon);
  return(1);
}

/*******************************************************************************
 *                                                                             *
 * fgl_mqdisconnect:  Disconnect from queue manager                            *
 *                                                                             *
 * 4GL: CALL fgl_mqdisconnect(connectHandle) returning status                  *
 *                                                                             *
 *******************************************************************************/

int fgl_mqdisconnect(int nargs)
{
  MQHCONN  Hcon;                            /* connection handle    */

  if (nargs == 1)
    ibm_lib4gl_popInt4(&Hcon);
  else
  {
    sprintf(mqErrmsg, "MQ-ERR: MQDISCONNECT missing connection handle");
    mqStatus = -1;
    mqReason = -1;
    return(0);
  }
  MQDISC(&Hcon,
         &mqStatus,
         &mqReason);
  ibm_lib4gl_returnInt4(mqStatus);
  return(1);
}

/*******************************************************************************
 *                                                                             *
 * fgl_mqopen4write:  Open an MQ queue for write                               *
 *                                                                             *
 * 4GL: CALL fgl_mqopen4write(connectHandle, queue_name)                       *
 *                               returning queueHandle                 *
 *                                                                             *
 *******************************************************************************/

int fgl_mqopen4write(int nargs)
{
  MQHCONN  Hcon;                            /* connection handle      */
  MQOD     queue = {MQOD_DEFAULT};          /* Object Descriptor      */
  MQHOBJ   Hqueue;                          /* object handle          */
  MQLONG   O_options;                       /* MQOPEN options         */


  if (nargs < 2)
  {
    sprintf(mqErrmsg, "MQ-ERR: MQOPEN missing connection handle or queue_name");
    mqStatus = -1;
    mqReason = -1;
    ibm_lib4gl_returnInt4(0);
    return(1);
  }
  else
  {
    ibm_lib4gl_popString(queue.ObjectName, MQ_Q_NAME_LENGTH);
    ibm_lib4gl_popInt4(&Hcon);
  }
  O_options = MQOO_OUTPUT            /* open queue for output     */
            | MQOO_FAIL_IF_QUIESCING /* but not if MQM stopping   */
            ;                        /* = 0x2010 = 8208 decimal   */

  MQOPEN(Hcon,                      /* connection handle            */
         &queue,                    /* object descriptor for queue  */
         O_options,                 /* open options                 */
         &Hqueue,                   /* object handle                */
         &mqStatus,                 /* MQOPEN completion code       */
         &mqReason);                  /* reason code                  */

  /* report reason, if any; stop if failed      */

  if ((mqStatus != MQCC_OK) || (mqReason != MQRC_NONE))
  {
    ibm_lib4gl_returnInt4(0);
    return(1);
  }
  ibm_lib4gl_returnInt4(Hqueue);
  return(1);
}

/*******************************************************************************
 *                                                                             *
 * fgl_mqopen4read:  Open an MQ queue for read                                 *
 *                                                                             *
 * 4GL: CALL fgl_mqopen4read(connectHandle, queue_name) returning queueHandle  *
 *                                                                             *
 *******************************************************************************/

int fgl_mqopen4read(int nargs)
{
  MQHCONN  Hcon;                            /* connection handle      */
  MQOD     queue = {MQOD_DEFAULT};          /* Object Descriptor      */
  MQHOBJ   Hqueue;                          /* object handle          */
  MQLONG   O_options;                       /* MQOPEN options         */


  if (nargs < 2)
  {
    sprintf(mqErrmsg, "MQ-ERR: MQOPEN missing connection handle or queue_name");
    mqStatus = -1;
    mqReason = -1;
    ibm_lib4gl_returnInt4(0);
    return(1);
  }
  else
  {
    ibm_lib4gl_popString(queue.ObjectName, MQ_Q_NAME_LENGTH);
    ibm_lib4gl_popInt4(&Hcon);
  }
  O_options = MQOO_INPUT_SHARED            /* open queue for output     */
            | MQOO_BROWSE
            | MQOO_FAIL_IF_QUIESCING       /* but not if MQM stopping   */
            ;                              /* = 0x2010 = 8208 decimal   */

  MQOPEN(Hcon,                             /* connection handle            */
         &queue,                           /* object descriptor for queue  */
         O_options,                        /* open options                 */
         &Hqueue,                          /* object handle                */
         &mqStatus,                        /* MQOPEN completion code       */
         &mqReason);                       /* reason code                  */

  /* report reason, if any; stop if failed      */

  if ((mqStatus != MQCC_OK) || (mqReason != MQRC_NONE))
  {
    ibm_lib4gl_returnInt4(0);
    return(1);
  }
  ibm_lib4gl_returnInt4(Hqueue);
  return(1);
}

/**********************************************************************************************
 *                                                                                            *
 * fgl_mqopen:  Open an MQ queue using open options                                           *
 *                                                                                            *
 * 4GL: CALL fgl_mqopen(connectHandle, queue_name, open_method) returning queueHandle         *
 *                                                                                            *
 **********************************************************************************************/

int fgl_mqopen(int nargs)
{
  MQHCONN  Hcon;                            /* connection handle      */
  MQOD     queue = {MQOD_DEFAULT};          /* Object Descriptor      */
  MQHOBJ   Hqueue;                          /* object handle          */
  MQLONG   O_options;                       /* MQOPEN options         */


  if (nargs != 3)
  {
    sprintf(mqErrmsg, "MQ-ERR: MQOPEN missing connection handle, queue_name or open option");
    mqStatus = -1;
    mqReason = -1;
    ibm_lib4gl_returnInt4(0);
    return(1);
  }
  else
  {
    ibm_lib4gl_popInt4(&O_options);
    ibm_lib4gl_popString(queue.ObjectName, MQ_Q_NAME_LENGTH);
    ibm_lib4gl_popInt4(&Hcon);
  }

  MQOPEN(Hcon,                      /* connection handle            */
         &queue,                    /* object descriptor for queue  */
         O_options,                 /* open options                 */
         &Hqueue,                   /* object handle                */
         &mqStatus,                 /* MQOPEN completion code       */
         &mqReason);                  /* reason code                  */

  /* report reason, if any; stop if failed      */

  if ((mqStatus != MQCC_OK) || (mqReason != MQRC_NONE))
  {
    ibm_lib4gl_returnInt4(0);
    return(1);
  }
  ibm_lib4gl_returnInt4(Hqueue);
  return(1);
}

/*******************************************************************************
 *                                                                             *
 * fgl_mqclose:  Close an open MQ queue                                        *
 *                                                                             *
 * 4GL: CALL fgl_mqclose(connectHandle, queueHandle) RETURNING status          *
 *                                                                             *
 *******************************************************************************/

int fgl_mqclose(int nargs)
{
  MQHCONN  Hcon;                            /* connection handle      */
  MQHOBJ   Hqueue;                          /* object handle          */
  MQLONG   C_options;                       /* MQCLOSE options        */


  if (nargs != 2)
  {
    sprintf(mqErrmsg, "MQ-ERR: MQCLOSE missing connection handle or queue_name");
    mqStatus = -1;
    mqReason = -1;
    return(0);
  }
  else
  {
    ibm_lib4gl_popInt4(&Hqueue);
    ibm_lib4gl_popInt4(&Hcon);
  }

  C_options = MQCO_NONE;                    /* no close options        */

  MQCLOSE(Hcon,                             /* connection handle       */
          &Hqueue,                          /* object handle           */
          C_options,
          &mqStatus,                        /* completion code         */
          &mqReason);                       /* reason code             */

  ibm_lib4gl_returnInt4(mqStatus);
  return(1);
}

/*******************************************************************************
 *                                                                             *
 * fgl_mqwrite: Write message to an open MQ queue                              *
 *                                                                             *
 * 4GL: CALL fgl_mqwrite(connectHandle, queueHandle, message, msgsize) RETURNING status       *
 *                                                                             *
 *******************************************************************************/

int fgl_mqwrite(int nargs)
{
  MQHCONN  Hcon;                            /* connection handle             */
  MQHOBJ   Hqueue;                          /* object handle                 */
  char     *buffer;                         /* message buffer                */
  MQLONG   messlen;                         /* message length                */
  MQMD     md = {MQMD_DEFAULT};             /* Message Descriptor            */
  MQPMO    pmo = {MQPMO_DEFAULT};           /* put message options           */

  if (nargs != 4)
  {
    sprintf(mqErrmsg, "MQ-ERR: MQWRITE missing connection handle, queue_handle, message or msg_size");
    mqStatus = -1;
    mqReason = -1;
    return(0);
  }
  else
  {
    ibm_lib4gl_popInt4(&messlen);
    if (messlen > 0)
    {
      messlen++;
      buffer = (char *)malloc(messlen);
      if (buffer == NULL)
      {
        sprintf(mqErrmsg, "MQ-ERR: MQWRITE could not allocate %d bytes memory\n", messlen);
        mqStatus = -1;
        mqReason = -2;
        return(0);
      }
    }
    ibm_lib4gl_popString(buffer,messlen);
    ibm_lib4gl_popInt4(&Hqueue);
    ibm_lib4gl_popInt4(&Hcon);

    memcpy(md.Format,           /* character string format            */
         MQFMT_STRING, (size_t)MQ_FORMAT_LENGTH);

    /******************************************************************/
    /* Use these options when connecting to Queue Managers that also  */
    /* support them, see the Application Programming Reference for    */
    /* details.                                                       */
    /* These options cause the MsgId and CorrelId to be replaced, so  */
    /* that there is no need to reset them before each MQPUT          */
    /******************************************************************/
    /* pmo.Options |= MQPMO_NEW_MSG_ID;                               */
    /* pmo.Options |= MQPMO_NEW_CORREL_ID;                            */
  
    /**************************************************************/
    /* The following two statements are not required if the       */
    /* MQPMO_NEW_MSG_ID and MQPMO_NEW _CORREL_ID options are used */
    /**************************************************************/
    memcpy(md.MsgId,           /* reset MsgId to get a new one    */
              MQMI_NONE, sizeof(md.MsgId) );

    memcpy(md.CorrelId,        /* reset CorrelId to get a new one */
              MQCI_NONE, sizeof(md.CorrelId) );

    MQPUT(Hcon,                /* connection handle               */
          Hqueue,              /* object handle                   */
          &md,                 /* message descriptor              */
          &pmo,                /* default options (datagram)      */
          messlen,             /* message length incl. null term. */
          buffer,              /* message buffer                  */
          &mqStatus,           /* completion code                 */
          &mqReason);            /* reason code                     */

    free(buffer);

    return(0);
  }
}


/*******************************************************************************
 *                                                                             *
 * fgl_mqread: Read message from an open MQ queue                              *
 *                                                                             *
 * 4GL: CALL fgl_mqread(connectHandle, queueHandle, maxLength, first)          *
 *                                                  RETURNING status, message  *
 *                                                                             *
 *******************************************************************************/

int fgl_mqread(int nargs)
{
  MQHCONN  Hcon;                            /* connection handle             */
  MQHOBJ   Hqueue;                          /* object handle                 */
  char     *buffer;                         /* message buffer                */
  MQLONG   maxlen = {4096};                 /* message max length (def 4 kb) */
  MQLONG   dataLength;                      /* length of message             */
  MQMD     md = {MQMD_DEFAULT};             /* Message Descriptor            */
  MQGMO    gmo = {MQGMO_DEFAULT};           /* get message options           */
  long     first = {0};                     /* browse first or next          */

  if (nargs < 2)
  {
    sprintf(mqErrmsg, "MQ-ERR: MQREAD missing connection handle or queue_handle");
    mqStatus = -1;
    mqReason = -1;
    ibm_lib4gl_returnInt4(-1);
    return(1);
  }
  else
  {
    if (nargs == 4) {
      ibm_lib4gl_popInt4(&first);
    }
    if (nargs >= 3) {
      ibm_lib4gl_popInt4(&maxlen);
      if (maxlen == 0) maxlen = 4096;
    }
    buffer = (char *)malloc(maxlen + 1);
    if (buffer == NULL)
    {
      sprintf(mqErrmsg, "MQ-ERR: MQREAD could not allocate %d bytes memory", maxlen);
      mqStatus = -1;
      mqReason = -1;
      ibm_lib4gl_returnString(NULL);
      return(1);
    }
    ibm_lib4gl_popInt4(&Hqueue);
    ibm_lib4gl_popInt4(&Hcon);

    if (first)
      gmo.Options = MQGMO_NO_WAIT + MQGMO_BROWSE_FIRST + MQGMO_ACCEPT_TRUNCATED_MSG;
    else
      gmo.Options = MQGMO_NO_WAIT + MQGMO_BROWSE_NEXT + MQGMO_ACCEPT_TRUNCATED_MSG;
    
    MQGET (Hcon, Hqueue, &md, &gmo, maxlen, buffer, &dataLength, &mqStatus, &mqReason);
    if (mqStatus == MQCC_FAILED)
    {
      if (mqReason == MQRC_NO_MSG_AVAILABLE)
      {
        sprintf(mqErrmsg, "MQ-WARNING: MQREAD no message available");
        mqStatus = 100;
        ibm_lib4gl_returnString(NULL);
      }
      else
      {
        sprintf(mqErrmsg, "MQ-ERR: MQREAD failed with reason code %d", mqReason);
        ibm_lib4gl_returnString(NULL);
      }
    }
    else
    {
      buffer[dataLength] = '\0';
      ibm_lib4gl_returnString(buffer);
    }

    free(buffer);
    return(1);
  }
}

int fgl_mqrecieve(int nargs)
{
  MQHCONN  Hcon;                            /* connection handle             */
  MQHOBJ   Hqueue;                          /* object handle                 */
  char     *buffer;                         /* message buffer                */
  MQLONG   maxlen = {4096};                 /* message max length (def 4 kb) */
  MQLONG   dataLength;                      /* length of message             */
  MQMD     md = {MQMD_DEFAULT};             /* Message Descriptor            */
  MQGMO    gmo = {MQGMO_DEFAULT};           /* get message options           */

  if (nargs < 2)
  {
    fprintf(stderr, "MQ-ERR: MQREAD missing connection handle or queue_handle");
    mqStatus = -1;
    mqReason = -1;
    ibm_lib4gl_returnInt4(-1);
    return(1);
  }
  else
  {
    if (nargs >= 3) {
      ibm_lib4gl_popInt4(&maxlen);
      if (maxlen == 0) maxlen = 4096;
    }
    buffer = (char *)malloc(maxlen + 1);
    if (buffer == NULL)
    {
      sprintf(mqErrmsg, "MQ-ERR: MQREAD could not allocate %d bytes memory", maxlen);
      mqStatus = -1;
      mqReason = -1;
      ibm_lib4gl_returnString(NULL);
      return(1);
    }
    ibm_lib4gl_popInt4(&Hqueue);
    ibm_lib4gl_popInt4(&Hcon);

    gmo.Options = MQGMO_NO_WAIT + MQGMO_ACCEPT_TRUNCATED_MSG;
    
    MQGET (Hcon, Hqueue, &md, &gmo, maxlen, buffer, &dataLength, &mqStatus, &mqReason);
    if (mqStatus == MQCC_FAILED)
    {
      if (mqReason == MQRC_NO_MSG_AVAILABLE)
      {
        fprintf(stderr, "MQ-WARNING: MQREAD no message available");
        mqStatus = 100;
        ibm_lib4gl_returnString(NULL);
      }
      else
      {
        sprintf(mqErrmsg, "MQ-ERR: MQREAD failed with reason code %d", mqReason);
        ibm_lib4gl_returnString(NULL);
      }
    }
    else
    {
      ibm_lib4gl_returnString(buffer);
    }

    free(buffer);
    return(1);
  }
}

/*******************************************************************************
 *                                                                             *
 * fgl_mqwriteonce: Write message to an open MQ queue                          *
 *                                                                             *
 * 4GL: CALL fgl_mqwriteonce(connectHandle, queueHandle, message) RETURNING status *
 *                                                                             *
 *******************************************************************************/


int fgl_mqwriteonce(int nargs)
{
  /*   Declare MQI structures needed                                */
  MQOD     od = {MQOD_DEFAULT};    /* Object Descriptor             */
  MQMD     md = {MQMD_DEFAULT};    /* Message Descriptor            */
  MQPMO   pmo = {MQPMO_DEFAULT};   /* put message options           */

  MQHCONN  Hcon;                   /* connection handle             */
  MQHOBJ   Hobj;                   /* object handle                 */
  MQLONG   O_options;              /* MQOPEN options                */
  MQLONG   C_options;              /* MQCLOSE options               */
  MQLONG   CompCode;               /* completion code               */
  MQLONG   OpenCode;               /* MQOPEN completion code        */
  MQLONG   Reason;                 /* reason code                   */
  MQLONG   CReason;                /* reason code for MQCONN        */
  MQLONG   messlen;                /* message length                */
  char     buffer[STSIZE];         /* message buffer                */
  char     QMName[MQ_Q_MGR_NAME_LENGTH];    /* queue manager name     */

  if (nargs < 2 || nargs > 3)
  {
    fprintf(stderr, "fgl_mqput: wrong number of parms (%d)\n", nargs );
    ibm_lib4gl_returnInt4(-1);
    return(1);
  }
  if (nargs == 3)
    ibm_lib4gl_popString(QMName,MQ_Q_MGR_NAME_LENGTH);
  ibm_lib4gl_popString(buffer,STSIZE);
  ibm_lib4gl_popString(od.ObjectName,QUSIZE);

  /******************************************************************/
  /*                                                                */
  /*   Connect to queue manager                                     */
  /*                                                                */
  /******************************************************************/

  QMName[0] = 0;                  /* use default queue manager      */
  MQCONN(QMName,                  /* queue manager                  */
         &Hcon,                   /* connection handle              */
         &CompCode,               /* completion code                */
         &CReason);               /* reason code                    */

  /* report reason and stop if it failed     */
  if (CompCode == MQCC_FAILED)
  {
    fprintf(stderr, "MQCONN ended with reason code %d\n", CReason);
    ibm_lib4gl_returnInt4(-2);
    return(1);
  }


  /******************************************************************/
  /*                                                                */
  /*   Open the target message queue for output                     */
  /*                                                                */
  /******************************************************************/

  O_options = MQOO_OUTPUT            /* open queue for output     */
            | MQOO_FAIL_IF_QUIESCING /* but not if MQM stopping   */
            ;                        /* = 0x2010 = 8208 decimal   */

  MQOPEN(Hcon,                      /* connection handle            */
         &od,                       /* object descriptor for queue  */
         O_options,                 /* open options                 */
         &Hobj,                     /* object handle                */
         &OpenCode,                 /* MQOPEN completion code       */
         &Reason);                  /* reason code                  */

  /* report reason, if any; stop if failed      */
  if (Reason != MQRC_NONE)
  {
    fprintf(stderr, "MQOPEN ended with reason code %d\n", Reason);
  }

  if (OpenCode == MQCC_FAILED)
  {
    fprintf(stderr, "unable to open queue for output\n");
    ibm_lib4gl_returnInt4(-3);
    return(1);
  }

  /******************************************************************/
  /*                                                                */
  /*   Write the message to the queue                               */
  /*                                                                */
  /******************************************************************/

  memcpy(md.Format,           /* character string format            */
         MQFMT_STRING, (size_t)MQ_FORMAT_LENGTH);

  /******************************************************************/
  /* Use these options when connecting to Queue Managers that also  */
  /* support them, see the Application Programming Reference for    */
  /* details.                                                       */
  /* These options cause the MsgId and CorrelId to be replaced, so  */
  /* that there is no need to reset them before each MQPUT          */
  /******************************************************************/
  /* pmo.Options |= MQPMO_NEW_MSG_ID;                               */
  /* pmo.Options |= MQPMO_NEW_CORREL_ID;                            */

  messlen = (MQLONG)strlen(buffer);       /* length without null        */

  if (messlen > 0)
  {
       /**************************************************************/
       /* The following two statements are not required if the       */
       /* MQPMO_NEW_MSG_ID and MQPMO_NEW _CORREL_ID options are used */
       /**************************************************************/
    memcpy(md.MsgId,           /* reset MsgId to get a new one    */
              MQMI_NONE, sizeof(md.MsgId) );

    memcpy(md.CorrelId,        /* reset CorrelId to get a new one */
              MQCI_NONE, sizeof(md.CorrelId) );

    MQPUT(Hcon,                /* connection handle               */
          Hobj,                /* object handle                   */
          &md,                 /* message descriptor              */
          &pmo,                /* default options (datagram)      */
          messlen,             /* message length                  */
          buffer,              /* message buffer                  */
          &CompCode,           /* completion code                 */
          &Reason);            /* reason code                     */

    /* report reason, if any */
    if (Reason != MQRC_NONE)
    {
      fprintf(stderr, "MQPUT ended with reason code %d\n", Reason);
    ibm_lib4gl_returnInt4(-3);
    return(1);
    }
  }

  /******************************************************************/
  /*                                                                */
  /*   Close the target queue (if it was opened)                    */
  /*                                                                */
  /******************************************************************/

  if (OpenCode != MQCC_FAILED)
  {
    C_options = MQCO_NONE;        /* no close options             */

    MQCLOSE(Hcon,                   /* connection handle            */
            &Hobj,                  /* object handle                */
            C_options,
            &CompCode,              /* completion code              */
            &Reason);               /* reason code                  */

    /* report reason, if any     */
    if (Reason != MQRC_NONE)
    {
      fprintf(stderr, "MQCLOSE ended with reason code %d\n", Reason);
      ibm_lib4gl_returnInt4(-4);
      return(1);
    }
  }

  /******************************************************************/
  /*                                                                */
  /*   Disconnect from MQM if not already connected                 */
  /*                                                                */
  /******************************************************************/
  if (CReason != MQRC_ALREADY_CONNECTED)
  {
    MQDISC(&Hcon,                   /* connection handle            */
           &CompCode,               /* completion code              */
           &Reason);                /* reason code                  */

    /* report reason, if any     */
    if (Reason != MQRC_NONE)
    {
      fprintf(stderr, "MQDISC ended with reason code %d\n", Reason);
      ibm_lib4gl_returnInt4(-5);
      return(1);
    }
  }

  /******************************************************************/
  /*                                                                */
  /* Return success status                                          */
  /*                                                                */
  /******************************************************************/
  ibm_lib4gl_returnInt4(0);
  return(1);
}




