
/* RULE 1: keep this table in sorted order. A binary search is used.
 * RULE 2: the constants have been originally extracted from SCO
 * which seems to have a glut of constants. My advice if a certain
 * constant is not available on *your* platform: strike it out!
 * Let me know; I'll look it up in SCO and probably agree with you.
 *
 * In practice, please put a suitable #if ! defined(*yourplatform*)
 * around the dodgy constant as the first stage of it's retirement.
 * Discuss it with the interested group for confirmation and then
 * we'll shoot it down.
 */

    { "AF_INET",		AF_INET		},
    { "AF_UNIX",		AF_UNIX		},
    { "FD_SETSIZE",		FD_SETSIZE	},
    { "MSG_DONTROUTE",		MSG_DONTROUTE	},
    { "MSG_OOB",		MSG_OOB		},
    { "MSG_PEEK",		MSG_PEEK	},
    { "SOCK_DGRAM",		SOCK_DGRAM	},
    { "SOCK_RAW",		SOCK_RAW	},
    { "SOCK_RDM",		SOCK_RDM	},
    { "SOCK_SEQPACKET",		SOCK_SEQPACKET	},
    { "SOCK_STREAM",		SOCK_STREAM	},
    { "SOL_SOCKET",		SOL_SOCKET	},
    { "SOMAXCONN",		SOMAXCONN	},
    { "SO_BROADCAST",		SO_BROADCAST	},
    { "SO_DEBUG",		SO_DEBUG	},
    { "SO_DONTROUTE",		SO_DONTROUTE	},
    { "SO_ERROR",		SO_ERROR	},
    { "SO_KEEPALIVE",		SO_KEEPALIVE	},
    { "SO_LINGER",		SO_LINGER	},
    { "SO_OOBINLINE",		SO_OOBINLINE	},
    { "SO_RCVBUF",		SO_RCVBUF	},
    { "SO_RCVLOWAT",		SO_RCVLOWAT	},
    { "SO_RCVTIMEO",		SO_RCVTIMEO	},
    { "SO_REUSEADDR",		SO_REUSEADDR	},
    { "SO_SNDBUF",		SO_SNDBUF	},
    { "SO_SNDLOWAT",		SO_SNDLOWAT	},
    { "SO_SNDTIMEO",		SO_SNDTIMEO	},
    { "SO_TYPE",		SO_TYPE		},

