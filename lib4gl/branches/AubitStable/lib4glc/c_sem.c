
# include	"cfun4gl.h"
# include	<sys/sem.h>

# define	MAX_CTL		100
# define	MAX_SOP		100

static int count;
static unsigned int integers[MAX_CTL];
static unsigned short int shorts[MAX_CTL];

static struct sembuf sops[MAX_SOP];
static struct semid_ds sem_stat;


function(c_semget,3,4,1,1)
{
    long key;
    int nsems;
    int mode;
    int flags = 0;
    char *cp, buf[5];
    cfgl_FMode fmode;
    int semid;

    if(nargs != 3 && nargs != 4)
USAGE:
	cfgl_fatal("usage: c_semget(key, nsems integer, mode[, flags char(*)])"
			 " returning integer\n"
			 "flags may contain the chars C(reate) E(xcl)\n"
	);

    if(nargs == 4)
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

    popint(&nsems);
    poplong(&key);

    if(risnull(CLONGTYPE, (char *) &key))
	key = IPC_PRIVATE;

    flags |= mode;

    semid = semget(key, nsems, flags);
    if(semid < 0)
	cfgl_errno = errno;

    retint(semid);
    return 1;

}   /* c_semget */
/*JFACE*/ int c_semget_3(int nargs) { return c_semget(nargs); }
/*JFACE*/ int c_semget_4(int nargs) { return c_semget(nargs); }


function(c_semctl,3,23,1,-20)
{
    int semid, sem_num, cmd;
    char buf[21];
    cfgl_FMode fmode;
    int status, i;
    int nres;
    char *complaint = 0;

    if(nargs < 3)
    {
USAGE:
	if(complaint)
	{
	    fprintf(stderr, "c_semctl: ");
	    fprintf(stderr, complaint, buf);
	}

	cfgl_fatal("usage: c_semctl(semid, sem_num integer, cmd char(*) [,arg...integer])"
			 " returning integer\n");
    }

    i = count = nargs - 3;
    while(--i >= 0)
    {
	popint((int *) &integers[i]);
	shorts[i] = integers[i];
    }
    nargs = 3;

    popstring(buf, sizeof(buf));
	 if(0 == strcmp(buf, "G" "ETVAL"))   cmd = GETVAL;
    else if(0 == strcmp(buf, "S" "ETVAL"))   cmd = SETVAL;
    else if(0 == strcmp(buf, "G" "ETPID"))   cmd = GETPID;
    else if(0 == strcmp(buf, "G" "ETNCNT"))  cmd = GETNCNT;
    else if(0 == strcmp(buf, "G" "ETZCNT"))  cmd = GETZCNT;
    else if(0 == strcmp(buf, "G" "ETALL"))   cmd = GETALL;
    else if(0 == strcmp(buf, "S" "ETALL"))   cmd = SETALL;
    else if(0 == strcmp(buf, "I" "PC_STAT")) cmd = IPC_STAT;
    else if(0 == strcmp(buf, "I" "PC_SET"))  cmd = IPC_SET;
    else if(0 == strcmp(buf, "I" "PC_RMID")) cmd = IPC_RMID;
    else cfgl_fatal("c_semctl(%s): unknown command\n", buf);

    if(cmd == IPC_SET)
	popstring(fmode, sizeof(fmode));
    else
	popint(&sem_num);
    popint(&semid);

    switch(cmd)
    {
    case SETVAL:
	if(count != 1 || cfgl_badargs && count < 1)
	{
	    complaint = "%s command requires 1 argument\n";
	    goto USAGE;
	}

	status = semctl(semid, sem_num, cmd, *integers);
	retint(status);
	nres = 1;
	break;

    case IPC_RMID:
	sem_num = 0;
	/* FALL THROUGH */

    case GETVAL:
    case GETPID:
    case GETNCNT:
    case GETZCNT:
	if(count && ! cfgl_badargs)
	{
	    complaint = "%s command requires no arguments\n";
	    goto USAGE;
	}

	status = semctl(semid, sem_num, cmd);
	retint(status);
	nres = 1;
	break;

    case SETALL:
	if(count == 0)
	{
	    complaint = "%s command requires one argument per semaphore\n";
	    goto USAGE;
	}

	status = semctl(semid, 0, cmd, shorts);
	retint(status);
	nres = 1;
	break;

    case GETALL:
	if(count != 1 || cfgl_badargs && count < 1)
	{
	    complaint = "%s command requires one argument numbering the returns\n";
	    goto USAGE;
	}

	status = semctl(semid, 0, cmd, shorts);
	retint(status);
	nres = *integers;
	for(i = 0; i < *integers; ++i)
	    retint((int) shorts[i]);
	break;

    case IPC_STAT:
	if(count && ! cfgl_badargs)
	{
	    complaint = "%s command requires no arguments\n";
	    goto USAGE;
	}

	status = semctl(semid, 0, cmd, &sem_stat);
	retint(status);
	retint(sem_stat.sem_nsems);
	retint(sem_stat.sem_perm.uid);
	retint(sem_stat.sem_perm.gid);
	retint(sem_stat.sem_perm.cuid);
	retint(sem_stat.sem_perm.cgid);
	retint(sem_stat.sem_perm.mode);
#if defined(__linux)
	retint(sem_stat.sem_perm.__key);
#else
	retint(sem_stat.sem_perm.key);
#endif
	nres = 8;
	break;

    case IPC_SET:
	if(count != 2 || cfgl_badargs && count < 2)
	{
	    complaint =
		"%s command requires 2 arguments\n"
		"and the sem_num argument is replaced with mode char(*)\n"
		"(sorry about the ugly interface...)\n";
	    goto USAGE;
	}

	/* get the current values */
	status = semctl(semid, 0, IPC_STAT, &sem_stat);
	if(status == 0)
	{
	    i = integers[0];
	    if(! risnull(CINTTYPE, (char *) &i) && i != -1)
		sem_stat.sem_perm.uid = i;

	    i = integers[1];
	    if(! risnull(CINTTYPE, (char *) &i) && i != -1)
		sem_stat.sem_perm.gid = i;

	    if(*fmode)
		sem_stat.sem_perm.mode = cfgl_interpMode(fmode);

	    status = semctl(semid, 0, IPC_SET, &sem_stat);
	}

	retint(status);
	nres = 1;
	break;
    }

    if(status == -1)
	cfgl_errno = errno;

    return nres;

}   /* c_semctl */
/*JFACE*/ int c_semctl_3(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_4(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_5(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_6(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_7(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_8(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_9(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_10(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_11(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_12(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_13(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_14(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_15(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_16(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_17(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_18(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_19(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_20(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_21(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_22(int nargs) { return c_semctl(nargs); }
/*JFACE*/ int c_semctl_23(int nargs) { return c_semctl(nargs); }


function(c_semop,4,61,3,1)
{
    int semid, nsops;
    int i, status;
    char buf[3];
    char *cp;

    if(nargs < 4 || nargs % 3 != 1)
        cfgl_fatal("usage: c_semop(semid integer,"
			 " {sem_num, sem_op integer, sem_flg char(*)} ...)"
			 " returning integer\n");

    nsops = nargs / 3;
    for(i = nsops - 1; i >= 0; --i)
    {
	popstring(buf, sizeof(buf));
	sops[i].sem_flg = 0;
	for(cp = buf; *cp; ++cp)
	    switch(*cp)
	    {
	    case 'U': sops[i].sem_flg |= SEM_UNDO;   break;
	    case 'W': sops[i].sem_flg |= IPC_NOWAIT; break;
	    }

	popshort(&sops[i].sem_op);
	popshort((short *) &sops[i].sem_num);
    }

    popint(&semid);

    status = semop(semid, sops, nsops);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_semop */
/*JFACE*/ int c_semop_4(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_7(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_10(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_13(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_16(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_19(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_22(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_25(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_28(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_31(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_34(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_37(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_40(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_43(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_46(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_49(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_52(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_55(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_58(int nargs) { return c_semop(nargs); }
/*JFACE*/ int c_semop_61(int nargs) { return c_semop(nargs); }
