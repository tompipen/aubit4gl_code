
# include	"cfun4gl.h"
# if defined(__linux)
#  include	<sys/types.h>
#  include	<sys/ipc.h>
# endif
# include	<sys/msg.h>

static struct msqid_ds msg_stat;

function(c_msgget,2,3,1,1)
{
    long key;
    int mode;
    int flags = 0;
    char *cp, buf[5];
    cfgl_FMode fmode;
    int msgid;

       if(nargs != 2 && nargs != 3)
   USAGE:
          cfgl_fatal("usage: c_msgget(key integer, mode[, flags] char(*))"
                            " returning integer\n"
                            "flags may contain the chars C(reate) E(xcl)\n"
           );

    if(nargs == 3)
    {
	popstring(buf, sizeof(buf));
	for(cp = buf; *cp; ++cp)
	    switch(*cp)
	    {
	    case 'C': flags |= IPC_CREAT; break;
	    case 'E': flags |= IPC_EXCL;  break;
	    default:  goto USAGE;
	    }
    }

    popstring(fmode, sizeof(fmode));
    mode = cfgl_interpMode(fmode);

    poplong(&key);

    if(risnull(CLONGTYPE, (char *) &key))
	key = IPC_PRIVATE;

    flags |= mode;

    msgid = msgget(key, flags);
    if(msgid < 0)
	cfgl_errno = errno;

    retint(msgid);
    return 1;

}   /* c_msgget */
/*JFACE*/ int c_msgget_2(int nargs) { return c_msgget(nargs); }
/*JFACE*/ int c_msgget_3(int nargs) { return c_msgget(nargs); }


function(c_msgctl,2,6,4,-12)
{
    int msgid, cmd;
    char buf[11];
    cfgl_FMode fmode;
    int uid, gid, msg_qbytes;
    int status, nres;

    if(nargs != 2 && nargs != 6)
USAGE:
	cfgl_fatal("usage: c_msgctl(msgid, cmd char(*)"
		   " [, mode char(*), uid, gid, msg_qbytes integer])"
		   " returning integer or other stuff\n");

    if(nargs == 6)
    {
	popint(&msg_qbytes);
	popint(&gid);
	popint(&uid);
	popstring(fmode, sizeof(fmode));
    }

    popstring(buf, sizeof(buf));
         if(0 == strcmp(buf, "I" "PC_RMID")) cmd = IPC_RMID;
    else if(0 == strcmp(buf, "I" "PC_STAT")) cmd = IPC_STAT;
    else if(0 == strcmp(buf, "I" "PC_SET"))  cmd = IPC_SET;
    else cfgl_fatal("c_msgctl(%s): unknown command\n", buf);

    /* only IPC_SET is allowed 6 args */
    if((nargs == 6) != (cmd == IPC_SET))
	goto USAGE;

    popint(&msgid);

    switch(cmd)
    {
    case IPC_RMID:
	status = msgctl(msgid, cmd, &msg_stat);
	retint(status);
	nres = 1;
	break;

    case IPC_STAT:
    case IPC_SET:
	status = msgctl(msgid, IPC_STAT, &msg_stat);
	if(cmd == IPC_STAT)
	{
	    retint(status);
	    retint(msg_stat.msg_perm.uid);
	    retint(msg_stat.msg_perm.gid);
	    retint(msg_stat.msg_perm.cuid);
	    retint(msg_stat.msg_perm.cgid);
	    retint(msg_stat.msg_perm.mode);
#if defined(__linux)
	    retint(msg_stat.msg_perm.__key);
#else
	    retint(msg_stat.msg_perm.key);
#endif

            retint(msg_stat.msg_cbytes);    /* current # bytes on q */
            retint(msg_stat.msg_qnum);      /* # of messages on q */
            retint(msg_stat.msg_qbytes);    /* max # of bytes on q */
            retint(msg_stat.msg_lspid);     /* pid of last msgsnd */
            retint(msg_stat.msg_lrpid);     /* pid of last msgrcv */

            nres = 12;
	    break;
        }

	if(status == 0)
	{
	    if(*fmode)
		msg_stat.msg_perm.mode = cfgl_interpMode(fmode);

	    if(! risnull(CINTTYPE, (char *) &uid) && uid != -1)
		msg_stat.msg_perm.uid = uid;

	    if(! risnull(CINTTYPE, (char *) &gid) && gid != -1)
		msg_stat.msg_perm.gid = gid;

	    if(! risnull(CINTTYPE, (char *) &msg_qbytes) && msg_qbytes != -1)
		msg_stat.msg_qbytes = msg_qbytes;

	    status = msgctl(msgid, IPC_SET, &msg_stat);
	}

	retint(status);
	nres = 1;

        break;
    }

    if(status == -1)
        cfgl_errno = errno;

    return nres;

}   /* c_msgctl */
/*JFACE*/ int c_msgctl_2(int nargs) { return c_msgctl(nargs); }
/*JFACE*/ int c_msgctl_6(int nargs) { return c_msgctl(nargs); }


function(c_msgsnd,3,4,1,1)
{
    int msqid, msgsz, msgflg;
    cfgl_MemPtr msgbuf;
    char buf[21];
    int status, i;

    if(nargs != 3 && nargs != 4)
        cfgl_fatal("usage: c_msgsnd(msqid, msgbuf, msgsz integer"
		   "[, msgflg char(*)])"
		   " returning integer\n");

    msgflg = 0;
    if(nargs == 4)
    {
	popstring(buf, sizeof(buf));
	for(i = 0; buf[i]; ++i)
	    switch(buf[i])
	    {
	    case 'W': msgflg |= IPC_NOWAIT; break;
	    }
    }

    popint(&msgsz);
    msgbuf = cfgl_getptr();
    popint(&msqid);

    cfgl_checkmem("c_msgsnd", msgbuf, 0, msgsz + sizeof(long));

    status = msgsnd(msqid, (struct msgbuf *) msgbuf->m, msgsz, msgflg);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_msgsnd */
/*JFACE*/ int c_msgsnd_3(int nargs) { return c_msgsnd(nargs); }
/*JFACE*/ int c_msgsnd_4(int nargs) { return c_msgsnd(nargs); }


function(c_msgrcv,4,5,1,1)
{
    int msqid, msgsz, msgtyp, msgflg;
    cfgl_MemPtr msgbuf;
    char buf[21];
    int status, i;

    if(nargs != 4 && nargs != 5)
        cfgl_fatal("usage: c_msgrcv(msqid, msgbuf, msgsz, msgtyp integer"
		   "[, msgflg char(*)])"
		   " returning integer\n");

    msgflg = 0;
    if(nargs == 5)
    {
	popstring(buf, sizeof(buf));
	for(i = 0; buf[i]; ++i)
	    switch(buf[i])
	    {
	    case 'E': msgflg |= MSG_NOERROR; break;
	    case 'W': msgflg |= IPC_NOWAIT; break;
	    }
    }

    popint(&msgtyp);
    popint(&msgsz);
    msgbuf = cfgl_getptr();
    popint(&msqid);

    cfgl_checkmem("c_msgrcv", msgbuf, 0, msgsz + sizeof(long));

    status = msgrcv(msqid, (struct msgbuf *) msgbuf->m, msgsz, msgtyp, msgflg);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_msgrcv */
/*JFACE*/ int c_msgrcv_4(int nargs) { return c_msgrcv(nargs); }
/*JFACE*/ int c_msgrcv_5(int nargs) { return c_msgrcv(nargs); }
