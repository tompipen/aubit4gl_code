#include "c:/gnu/pdc27_ming_w32/curses.h"
#define BLANK           (' '|A_NORMAL)
#define ZEROS           ('\0'|A_NORMAL)
#define ISBLANK(ch)     (CharOf(ch) == ' ')
#define UChar(c)        ((unsigned char)(c))
#define ChCharOf(c)     ((c) & (chtype)A_CHARTEXT)
#define ChAttrOf(c)     ((c) & (chtype)A_ATTRIBUTES)

#define CharOf(c)       ChCharOf(c)
#define AttrOf(c)       ChAttrOf(c)
#define NCURSES_IMPEXP
#define  NCURSES_API 
#define GCC_UNUSED

#define START_TRACE() /* nothing */

#define T(a)
#define TR(n, a)
#define TPUTS_TRACE(s)

#define returnAttr(code)        return code
#define returnBits(code)        return code
#define returnBool(code)        return code
#define returnCPtr(code)        return code
#define returnCVoidPtr(code)    return code
#define returnChar(code)        return code
#define returnCode(code)        return code
#define returnPtr(code)         return code
#define returnSP(code)          return code
#define returnVoid              return
#define returnVoidPtr(code)     return code
#define returnWin(code)         return code




