
# include	"cfun4gl.h"
# include	<limits.h>
# include	<malloc.h>


static cfgl_MemInt MemSerial = 0;

/* store a double linked list of our allocations for debugging purposes */
/* also store a count of allocations so we can detect leaks */
static cfgl_MemPtr mem_head = 0;
static cfgl_MemPtr mem_tail = 0;
int mem_count = 0;


void cfgl_checkmem(char *action, cfgl_MemPtr mp, int ofs, int del)
{
    if(! mp || mp->M_MAGIC != CFGL_MAGIC)
	cfgl_fatal("%s(%ld): access attempted on an invalid or free block\n",
		    action, (long) mp);

    if(ofs < 0)
	cfgl_fatal("%s(%ld#%d[%d]: %d): negative offset\n",
		    action, (long) mp, mp->M_SERIAL, mp->M_SIZE, ofs);

    if(del < 0)
	cfgl_fatal("%s(%ld#%d[%d]: %d): negative size\n",
		    action, (long) mp, mp->M_SERIAL, mp->M_SIZE, del);

    if(ofs >= mp->M_SIZE)
	cfgl_fatal("%s(%ld#%d[%d]: %d): offset exceeds size of block\n",
		    action, (long) mp, mp->M_SERIAL, mp->M_SIZE, ofs);

    if(ofs + del > mp->M_SIZE)
	cfgl_fatal("%s(%ld#%d[%d]: %d, %d): access crosses end of block\n",
		    action, (long) mp, mp->M_SERIAL, mp->M_SIZE, ofs, del);

}   /* cfgl_checkmem */


function(c_memstats,0,0,1,3)
{
    int i;
    long int mem_size = 0;
    int mem_error = 0;
    cfgl_MemPtr mp = mem_head;

    for(i = 0; i < mem_count; ++i)
    {
	if(mp)
	{
	    mem_size += mp->M_SIZE;
	    mp = mp->M_NEXT;
	}
	else
	{
	    mem_error = 1;	/* number of blocks less than counter */
	    break;
	}
    }

    if(mp)
	mem_error = 2;    /* number of blocks exceeds counter */

    retint(mem_count);
    retlong(mem_size);
    retint(mem_error);

    return 3;

}   /* c_memstats */
/*JFACE*/ int c_memstats_0(int nargs) { return c_memstats(nargs); }


cfgl_MemPtr cfgl_getptr(void)
{
    long int l;

    poplong(&l);
    if(risnull(CLONGTYPE, (char *) &l))
	l = 0;
    return (cfgl_MemPtr) l;

}   /* cfgl_getptr */


static void cfgl_retptr(cfgl_MemPtr rp)
{
    if(rp)
	retlong((long) rp);
    else
	retquote("");

}   /* cfgl_retptr */


function(c_memid,1,1,1,1)
{
    cfgl_MemPtr mp = cfgl_getptr();

    if(!mp)
	retquote("");
    else if(mp->M_MAGIC == CFGL_MAGIC)
	retint(mp->M_SERIAL);
    else
	retint(0);
    return 1;

}   /* c_memid */
/*JFACE*/ int c_memid_1(int nargs) { return c_memid(nargs); }


static void cfgl_meminsert(cfgl_MemPtr mp)
{
    ++mem_count;

    /* insert into beginning of double linked list */
    mp->M_PREV = 0;
    mp->M_NEXT = mem_head;

    if(! mem_tail)
	mem_tail = mp;
    else
	mem_head->M_PREV = mp;

    mem_head = mp;
}   /* cfgl_meminsert */


static void cfgl_memdelete(cfgl_MemPtr mp)
{
    --mem_count;

    /* unlink the block from the double linked list */
    if(mp->M_PREV)
	mp->M_PREV->M_NEXT = mp->M_NEXT;
    else
	mem_head = mp->M_NEXT;

    if(mp->M_NEXT)
	mp->M_NEXT->M_PREV = mp->M_PREV;
    else
	mem_tail = mp->M_PREV;

    mp->M_NEXT = mp->M_PREV = NULL;

}   /* cfgl_memdelete */


static cfgl_MemPtr cfgl_malloc(int size)
{
    cfgl_MemPtr mp = 0;

    if((mp = (cfgl_MemPtr) malloc(size + sizeof(struct cfgl_MemCtrl))))
    {
	memset((void *) mp->m, 0, size);

	/* allow the serial numbers to wrap, but stay positve */
	if(++MemSerial < 0)
	    MemSerial = 1;
	mp->M_SERIAL = MemSerial;
	mp->M_MAGIC = CFGL_MAGIC;
	mp->M_SIZE = size;

	cfgl_meminsert(mp);
    }

    return mp;

}   /* cfgl_malloc */


function(c_malloc,1,1,1,1)
{
    int size;
    cfgl_MemPtr mp = 0;

    popint(&size);
    if(size > 0)
	mp = cfgl_malloc(size);

    cfgl_retptr(mp);
    return 1;

}   /* c_malloc */
/*JFACE*/ int c_malloc_1(int nargs) { return c_malloc(nargs); }


function(c_calloc,2,2,1,1)
{
    int size;
    int nelem;
    cfgl_MemPtr mp = 0;

    popint(&size);
    popint(&nelem);

    if(size > 0 && nelem > 0)
	mp = cfgl_malloc(nelem * size);

    cfgl_retptr(mp);
    return 1;

}   /* c_calloc */
/*JFACE*/ int c_calloc_2(int nargs) { return c_calloc(nargs); }


function(c_realloc,2,2,1,1)
{
    cfgl_MemPtr mp, result;
    int size;

    popint(&size);
    mp = cfgl_getptr();
    cfgl_checkmem("c_realloc", mp, 0, 0);

    if(size > 0)
    {
	cfgl_memdelete(mp);

	if((result = (cfgl_MemPtr) realloc((void *) mp,
		                      size + sizeof(struct cfgl_MemCtrl))
	)){
	    mp = result;
	    mp->M_SIZE = size;
	}

	cfgl_meminsert(mp);
    }

    cfgl_retptr(mp);
    return 1;

}   /* c_realloc */
/*JFACE*/ int c_realloc_2(int nargs) { return c_realloc(nargs); }


function(c_free,1,1,1,0)
{
    cfgl_MemPtr mp = cfgl_getptr();
    cfgl_checkmem("c_free", mp, 0, 0);

    cfgl_memdelete(mp);

    mp->M_NEXT   = 0;
    mp->M_PREV   = 0;
    mp->M_MAGIC  = 0;
    mp->M_SIZE   = -1;
    mp->M_SERIAL = -1;

    free((void *) mp);
    return 0;

}   /* c_free */
/*JFACE*/ int c_free_1(int nargs) { return c_free(nargs); }


function(c_memset,4,4,1,0)
{
    cfgl_MemPtr mp;
    int ofs, c, size;

    popint(&size);
    popint(&c);
    popint(&ofs);

    mp = cfgl_getptr();
    cfgl_checkmem("c_memset", mp, ofs, size);
    memset((void *) &mp->m[ofs], c, size);

    return 0;

}   /* c_memset */
/*JFACE*/ int c_memset_4(int nargs) { return c_memset(nargs); }


/* c_memcpy(dest, dofs, source, sofs, size) */
function(c_memcpy,5,5,1,0)
{
    cfgl_MemPtr s1, s2;
    int ofs1, ofs2;
    int i, size;
    char *cp1, *cp2;

    popint(&size);
    popint(&ofs2);	s2 = cfgl_getptr();
    popint(&ofs1);	s1 = cfgl_getptr();

    cfgl_checkmem("c_memcpy", s1, ofs1, size);
    cfgl_checkmem("c_memcpy", s2, ofs2, size);

    if(s1->m < s2->m)
    {
	cp1 = &s1->m[ofs1];
	cp2 = &s2->m[ofs2];
	for(i = 0; i < size; ++i)
	    *cp1++ = *cp2++;
    }
    else
    {
	cp1 = &s1->m[ofs1 + size];
	cp2 = &s2->m[ofs2 + size];

	for(i = 0; i < size; ++i)
	    *--cp1 = *--cp2;
    }

    return 0;

}   /* c_memcpy */
/*JFACE*/ int c_memcpy_5(int nargs) { return c_memcpy(nargs); }


function(c_sizeof,1,1,1,1)
{
    char buf[11];

    popstring(buf, sizeof(buf));

    /* no, I'm not going to support mixed case on this ;*/
         if(! strcmp(buf, "short"))
	retint(sizeof(short));
    else if(! strcmp(buf, "int"))
	retint(sizeof(int));
    else if(! strcmp(buf, "long"))
	retint(sizeof(long));
    else
	retquote("");
    return 1;

}   /* c_sizeof */
/*JFACE*/ int c_sizeof_1(int nargs) { return c_sizeof(nargs); }


function(c_peekch,2,2,1,1)
{
    cfgl_MemPtr mp;
    int ofs;
    char buf[2];

    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_peekch", mp, ofs, 1);

    buf[0] = mp->m[ofs];
    buf[1] = 0;

    retquote(buf);
    return 1;

}   /* c_peekch */
/*JFACE*/ int c_peekch_2(int nargs) { return c_peekch(nargs); }


function(c_peek8,2,2,1,1)
{
    cfgl_MemPtr mp;
    int ofs;
    unsigned char c;

    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_peek8", mp, ofs, 1);

    c = (unsigned char) mp->m[ofs];
    retshort(c);
    return 1;

}   /* c_peek8 */
/*JFACE*/ int c_peek8_2(int nargs) { return c_peek8(nargs); }


function(c_peek16,2,2,1,1)
	/* WARNING: this is VERY sensitive */
	/* TODO: MUST adjust this to cope with different platforms */
{
    cfgl_MemPtr mp;
    int ofs;
    short s;

    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_peek16", mp, ofs, sizeof(short));

    memcpy((void *) &s, (void *) &mp->m[ofs], sizeof(short));
    retshort(s);
    return 1;

}   /* c_peek16 */
/*JFACE*/ int c_peek16_2(int nargs) { return c_peek16(nargs); }


function(c_peek32,2,2,1,1)
	/* WARNING: this is VERY sensitive */
	/* TODO: MUST adjust this to cope with different platforms */
{
    cfgl_MemPtr mp;
    int ofs;
    int i;

    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_peek32", mp, ofs, sizeof(int));

    memcpy((void *) &i, (void *) &mp->m[ofs], sizeof(int));
    retint(i);
    return 1;

}   /* c_peek32 */
/*JFACE*/ int c_peek32_2(int nargs) { return c_peek32(nargs); }


function(c_peekshort,2,2,1,1)
{
    cfgl_MemPtr mp;
    int ofs;
    short s;

    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_peekshort", mp, ofs, sizeof(short));

    memcpy((void *) &s, (void *) &mp->m[ofs], sizeof(short));
    retshort(s);
    return 1;

}   /* c_peekshort */
/*JFACE*/ int c_peekshort_2(int nargs) { return c_peekshort(nargs); }


function(c_peekint,2,2,1,1)
{
    cfgl_MemPtr mp;
    int ofs;
    int i;

    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_peekint", mp, ofs, sizeof(int));

    memcpy((void *) &i, (void *) &mp->m[ofs], sizeof(int));
    retint(i);
    return 1;

}   /* c_peekint */
/*JFACE*/ int c_peekint_2(int nargs) { return c_peekint(nargs); }


function(c_peeklong,2,2,1,1)
{
    cfgl_MemPtr mp;
    int ofs;
    long l;

    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_peeklong", mp, ofs, sizeof(long));

    memcpy((void *) &l, (void *) &mp->m[ofs], sizeof(long));
    retlong(l);
    return 1;

}   /* c_peeklong */
/*JFACE*/ int c_peeklong_2(int nargs) { return c_peeklong(nargs); }


function(c_peekstr,3,3,1,1)
{
    cfgl_MemPtr mp;
    int ofs, size;
    cfgl_String buf;
    buf[0] = 0;

    popint(&size);
    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_peekstr", mp, ofs, size);

    if(size > CFGL_STRING) size = CFGL_STRING;
    memcpy((void *) buf, (void *) &mp->m[ofs], size);
    buf[size] = 0;

    retquote(buf);
    return 1;

}   /* c_peekstr */
/*JFACE*/ int c_peekstr_3(int nargs) { return c_peekstr(nargs); }


function(c_pokech,3,3,1,0)
{
    cfgl_MemPtr mp;
    int ofs;
    char buf[2];

    popquote(buf, sizeof(buf));
    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_pokech", mp, ofs, 1);

    mp->m[ofs] = buf[0];
    return 0;

}   /* c_pokech */
/*JFACE*/ int c_pokech_3(int nargs) { return c_pokech(nargs); }


function(c_poke8,3,3,1,0)
{
    cfgl_MemPtr mp;
    int ofs;
    short s;

    popshort(&s);
    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_poke8", mp, ofs, 1);

    mp->m[ofs] = (char) s;
    return 0;

}   /* c_poke8 */
/*JFACE*/ int c_poke8_3(int nargs) { return c_poke8(nargs); }


function(c_poke16,3,3,1,0)
{
    cfgl_MemPtr mp;
    int ofs;
    short s;

    popshort(&s);
    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_poke16", mp, ofs, sizeof(short));

    memcpy((void *) &mp->m[ofs], (void *) &s, sizeof(short));
    return 0;

}   /* c_poke16 */
/*JFACE*/ int c_poke16_3(int nargs) { return c_poke16(nargs); }


function(c_poke32,3,3,1,0)
{
    cfgl_MemPtr mp;
    int ofs;
    int i;

    popint(&i);
    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_poke32", mp, ofs, sizeof(int));

    memcpy((void *) &mp->m[ofs], (void *) &i, sizeof(int));
    return 0;

}   /* c_poke32 */
/*JFACE*/ int c_poke32_3(int nargs) { return c_poke32(nargs); }


function(c_pokeshort,3,3,1,1)
{
    cfgl_MemPtr mp;
    int ofs;
    short s;

    popshort(&s);
    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_pokeshort", mp, ofs, sizeof(short));

    memcpy((void *) &mp->m[ofs], (void *) &s, sizeof(short));
    retint(sizeof(short));
    return 1;

}   /* c_pokeshort */
/*JFACE*/ int c_pokeshort_3(int nargs) { return c_pokeshort(nargs); }


function(c_pokeint,3,3,1,1)
{
    cfgl_MemPtr mp;
    int ofs;
    int i;

    popint(&i);
    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_pokeint", mp, ofs, sizeof(int));

    memcpy((void *) &mp->m[ofs], (void *) &i, sizeof(int));
    retint(sizeof(int));
    return 1;

}   /* c_pokeint */
/*JFACE*/ int c_pokeint_3(int nargs) { return c_pokeint(nargs); }


function(c_pokelong,3,3,1,1)
{
    cfgl_MemPtr mp;
    int ofs;
    long l;

    poplong(&l);
    popint(&ofs);
    mp = cfgl_getptr();
    cfgl_checkmem("c_pokelong", mp, ofs, sizeof(long));

    memcpy((void *) &mp->m[ofs], (void *) &l, sizeof(long));
    retint(sizeof(long));
    return 1;

}   /* c_pokelong */
/*JFACE*/ int c_pokelong_3(int nargs) { return c_pokelong(nargs); }


function(c_pokestr,3,4,1,0)
{
    cfgl_MemPtr mp;
    int ofs;
    cfgl_String buf;
    int size;

    if(nargs != 3 && nargs != 4)
	cfgl_fatal("usage: c_pokestr(ptr, ofs integer,"
			 " str char(*) [, n integer])\n");

    if(nargs == 4)
	popint(&size);

    popquote(buf, sizeof(buf));
    if(nargs == 3)
	size = cfgl_trim(buf);

    popint(&ofs);

    mp = cfgl_getptr();
    cfgl_checkmem("c_pokestr", mp, ofs, size);

    if(size > CFGL_STRING) size = CFGL_STRING;
    memcpy((void *) &mp->m[ofs], (void *) buf, size);

    return 0;

}   /* c_pokestr */
/*JFACE*/ int c_pokestr_3(int nargs) { return c_pokestr(nargs); }
/*JFACE*/ int c_pokestr_4(int nargs) { return c_pokestr(nargs); }


function(c_mallinfo,0,0,1,10)
{
    struct mallinfo mi;

    mi = mallinfo();
    retint(mi.arena);
    retint(mi.ordblks);
    retint(mi.smblks);
    retint(mi.hblks);
    retint(mi.hblkhd);
    retint(mi.usmblks);
    retint(mi.fsmblks);
    retint(mi.uordblks);
    retint(mi.fordblks);
    retint(mi.keepcost);
    return 10;

}   /* c_mallinfo */
/*JFACE*/ int c_mallinfo_0(int nargs) { return c_mallinfo(nargs); }
