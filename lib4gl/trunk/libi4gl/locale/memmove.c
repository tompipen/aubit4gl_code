/*
@(#)File:            $RCSfile: memmove.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         Simulate MEMMOVE(3)
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1991
*/

/*TABSTOP=4*/

#ifndef lint
static char     sccs[] = "@(#)$Id: memmove.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

void	*memmove(s1, s2, n)
void	*s1;
void	*s2;
int		 n;
{
	char	*t;
	char	*t1 = (char *)s1;
	char	*t2 = (char *)s2;
	void	*s = s1;

	if (t1 < t2)
	{	/* Copy forwards */
		t = t1 + n;
		while (t1 < t)
			*t1++ = *t2++;
	}
	else
	{	/* Copy backwards */
		t = t2;
		t1 += n;
		t2 += n;
		while (t2 > t)
			*--t1 = *--t2;
	}
	return(s);
}

#ifdef TEST
main()
{
	char	buffer[80];
	int		ok = 0;

	strcpy(&buffer[0], "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	printf("buffer = %s\n", buffer);
	printf("memmove(&buffer[0], &buffer[9], 10);\n");
	memmove(&buffer[0], &buffer[9], 10);
	printf("buffer = %s\n", buffer);
	if (strcmp(buffer, "JKLMNOPQRSKLMNOPQRSTUVWXYZ") != 0)
		ok++, printf("** FAILED **\n");
	printf("memmove(&buffer[5], &buffer[0], 10);\n");
	memmove(&buffer[5], &buffer[0], 10);
	printf("buffer = %s\n", buffer);
	if (strcmp(buffer, "JKLMNJKLMNOPQRSPQRSTUVWXYZ") != 0)
		ok++, printf("** FAILED **\n");

	if (ok == 0)
		printf("OK\n");
	return(0);
}
#endif	/* TEST */
