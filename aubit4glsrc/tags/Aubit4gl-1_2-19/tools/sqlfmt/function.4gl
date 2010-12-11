-- @(#)$Id: function.4gl,v 1.1 2002-11-28 06:40:47 afalout Exp $
-- @(#)Code to demonstrate I4GLXREF program

DATABASE Example

FUNCTION compute(c2, c3)

    DEFINE
        c2      LIKE Table1.Column02,
        c3      LIKE Table1.Column03

    RETURN (c2 + c3)

END FUNCTION {compute}
