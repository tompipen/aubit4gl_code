{
From: johnl@informix.com (Jonathan Leffler)
Date: 12 Mar 1994 16:43:04 -0500

>From: djm@zeus.eymsl.co.nz (David Manley)
>Subject: Re: Recursive Stored Procedures
>Date: 3 Mar 94 22:41:33 GMT
>X-Informix-List-Id: <news.5737>
>
>Jack Parker (jparker@hpbs3645.boi.hp.com) wrote:
>: I was putting together a recursive stored procedure - things were going just
>: fine - then I popped a second window and used it again - while the
>: first one was still running.  The engine crashed and I had to go through a
>: tbinit/restore to get it back.  Anyone else ever see this?
>: (Online5.0, isql/4gl 4.10).
>
>In my (past) experience, Informix has had problems with recursive routines
>when the routine requires I/O. For example I wrote a routine which
>opened a window and, depending on the user key presses, could be
>required to open a second instance of the same window. After closing the
>second instance, the program would crash because the first window instance
>seemed to think it had been closed.
>
>I don't think your problem is a reflection of the fact that you are
>using a stored procedure. My gut feeling is that is is something to do with
>Informix's internals (I know this is true for C versions because INPUT
>statements got (still get?) turned into "static" data structures which
>just doesn't work properly for recursive routines).
>
>My solution was grubby - when it went to open the window a second time
>it opened a different window with the same layout but used a different
>variable in a separate OPEN statement. I had to duplicate code though,
>which I wasn't too impressed about.
>
>Any comments Jonathan L?

A bit late, but when invited to speak I tend to do so...  At length!

Actually, the whole area of nested and recursive input in both compiled and
interpreted I4GL was something which received a lot of attention in 4.12,
and this is as good an opportunity as any to publicise what we have done,
and what we have not done.

The $INFORMIXDIR/release/TOOLREL_4.1 file contains a lot of valuable
information and should be scrutinised by anyone installing this version.
No prizes for spotting the typo on page 1 -- someone else already got it.
Pages 17-25 cover nested/recursive input.

In short, you can use nested and recursive input with considerably more
confidence and considerably less danger of core dumping in 4.12 than you
could in any previous version.  You can now reuse the same form fields for
the nested input statements, and when you return to the outer level of
input, the values will be restored.  If you wanted the inner statement
to transfer values to the outer, then you will need an intermediate
DISPLAY statement after the inner statement.  (Note that input statement
encompasses INPUT, INPUT ARRAY, DISPLAY ARRAY, CONSTRUCT and PROMPT.)
Further, you can open a form in the inner input and close it again without
any risk; you can leave it open and the code will work without core
dumping, but your display will be shot to pieces.  You are strongly
encouraged to use a window for any nested input operations, but you can now
do nested operations reasonably securely without using multiple windows.

One of the necessary changes was precisely to convert static ICB structures
into local (non-static) variables; easy in C, not so easy in p-code.

There is one area where we did not have time to fix the problems, and that
is if the code does an early exit from a nested input without saying EXIT
INPUT.

For an example, see the code below, which comes from the release notes.
Under no circumstances is any claim made for the validity of the code
except as a torture test.  Indeed, most of the code cannot be reached.  It
does, however, allow both you and me to see where the problems might be --
provided you have compiled I4GL.  Note that you have no chance whatsoever
of compiling this under a 4.11 or earlier compiler (unless you manage to
locate a 1.10.00 version, maybe!)

All the GOTOs will leave statements incorrectly terminated (or, more
precisely, unterminated).  This will remain true for any future version of
the product too, regardless of the other fixes which will be applied.  This
should be taken to mean that WHENEVER ERROR GOTO is not an appropriate
method of handling errors inside the scope of an input statement, menu or
FOREACH loop.

Any RETURN from a function will at most close the immediately enclosing
statement; it will not close any outer input statements.

Any exit from an the innermost active input statement will terminate that
statement correctly, so EXIT INPUT can be used inside an INPUT or INPUT
ARRAY with no harm done.

However, exiting any statement other than the innermost active input
statement is likely to lead to confusion somewhere along the line.  For
example, the cursor on the FOREACH loop may not be closed, so you may
receive an error when re-entering the function and re-using the cursor.
Also, you may be unable to close windows or forms as they may still be
marked as in active use because the input statements were not properly
terminated.

It is intended to address these deficiencies (apart from problems caused by
GOTO) in a later version of the products, which may or may not be version
4.13/6.01.  The same defects will be present in version 6.00, which is best
thought of as "4.12 Tools for 6.00 Servers".

Yours,
Jonathan Leffler (johnl@informix.com) #include <disclaimer.h>
}


-- @(#)Torture test for I4GL compilers
-- @(#)Also a torture test for people reading the C code
-- @(#)Also a torture test for C code reformatting programs
database test1
MAIN

    CALL f()

END MAIN

FUNCTION f()

  DEFINE s CHAR(300)
  DEFINE y INTEGER
  DEFINE i INTEGER
  DEFINE t INTEGER
  DEFINE a ARRAY[10] OF INTEGER

  DECLARE c CURSOR FOR
    SELECT Tabid FROM Systables

  OPEN WINDOW w AT 1, 1 WITH FORM "xxx"
  LET y = 0

  FOREACH c INTO t
    FOR i = 1 TO 10
       WHILE y < 1000
        MENU "ABCDEF"
        BEFORE MENU
          HIDE OPTION "B"
        COMMAND "A" "Absolutely"
          SHOW OPTION "B"
          IF a[1] THEN EXIT     MENU END IF
          IF a[1] THEN CONTINUE MENU END IF
          NEXT OPTION "E"
        COMMAND "B" "Beautiful"
          MESSAGE "Thank you"
        COMMAND "C" "Colourful"
          MESSAGE "Thank you"
        COMMAND "D" "Delicious"
          MESSAGE "Thank you"
        COMMAND "E" "Exit"
          EXIT MENU
        COMMAND "F"
          MENU "XYZ"
          COMMAND "X"
            EXIT MENU
          COMMAND "Y"
            INPUT BY NAME y WITHOUT DEFAULTS
            AFTER FIELD y
              IF a[1] THEN EXIT     FOR       END IF
              IF a[1] THEN CONTINUE FOR       END IF
              IF a[1] THEN EXIT     FOREACH   END IF
              IF a[1] THEN CONTINUE FOREACH   END IF
              IF a[1] THEN EXIT     WHILE     END IF
              IF a[1] THEN CONTINUE WHILE     END IF
              IF a[1] THEN RETURN             END IF
              IF a[1] THEN EXIT     MENU      END IF
              IF a[1] THEN CONTINUE MENU      END IF
              IF a[1] THEN EXIT     INPUT     END IF
              IF a[1] THEN CONTINUE INPUT     END IF
              IF a[1] THEN GOTO End_Label     END IF
              IF a[1] THEN GOTO Mid_Label     END IF
              CONSTRUCT BY NAME s ON y
              AFTER FIELD y
                IF a[1] THEN EXIT     FOR       END IF
                IF a[1] THEN CONTINUE FOR       END IF
                IF a[1] THEN EXIT     FOREACH   END IF
                IF a[1] THEN CONTINUE FOREACH   END IF
                IF a[1] THEN EXIT     WHILE     END IF
                IF a[1] THEN CONTINUE WHILE     END IF
                IF a[1] THEN RETURN             END IF
                IF a[1] THEN EXIT     MENU      END IF
                IF a[1] THEN CONTINUE MENU      END IF
  -- EXIT INPUT is not allowed by the compiler (error 4488)
  --            IF a[1] THEN EXIT     INPUT     END IF
  -- CONTINUE INPUT is not allowed by the compiler (error 4488)
  --            IF a[1] THEN CONTINUE INPUT     END IF
                IF a[1] THEN EXIT     CONSTRUCT END IF
                IF a[1] THEN CONTINUE CONSTRUCT END IF
                IF a[1] THEN GOTO End_Label     END IF
                IF a[1] THEN GOTO Mid_Label     END IF
                 CALL SET_COUNT(3)
                DISPLAY ARRAY a TO a.*
                ON KEY (F3)
                  IF a[1] THEN EXIT     FOR       END IF
                  IF a[1] THEN CONTINUE FOR       END IF
                  IF a[1] THEN EXIT     FOREACH   END IF
                  IF a[1] THEN CONTINUE FOREACH   END IF
                  IF a[1] THEN EXIT     WHILE     END IF
                  IF a[1] THEN CONTINUE WHILE     END IF
                  IF a[1] THEN RETURN             END IF
                  IF a[1] THEN EXIT     MENU      END IF
                  IF a[1] THEN CONTINUE MENU      END IF
                  IF a[1] THEN EXIT     DISPLAY   END IF
-- CONTINUE DISPLAY is not allowed by the compiler
--                IF a[1] THEN CONTINUE DISPLAY   END IF
-- EXIT INPUT is not allowed by the compiler (error 4488)
--                IF a[1] THEN EXIT     INPUT     END IF
-- CONTINUE INPUT is not allowed by the compiler (error 4488)
--                IF a[1] THEN CONTINUE INPUT     END IF
-- EXIT CONSTRUCT is not allowed by the compiler (error 4488)
--                IF a[1] THEN EXIT     CONSTRUCT END IF
-- CONTINUE CONSTRUCT is not allowed by the compiler (error 4488)
--                IF a[1] THEN CONTINUE CONSTRUCT END IF
                  IF a[1] THEN GOTO End_Label     END IF
                  IF a[1] THEN GOTO Mid_Label     END IF
                  INPUT ARRAY a FROM a.*
                  AFTER FIELD y
                    IF a[1] THEN EXIT     FOR       END IF
                    IF a[1] THEN CONTINUE FOR       END IF
                    IF a[1] THEN EXIT     FOREACH   END IF
                    IF a[1] THEN CONTINUE FOREACH   END IF
                    IF a[1] THEN EXIT     WHILE     END IF
                    IF a[1] THEN CONTINUE WHILE     END IF
                    IF a[1] THEN RETURN             END IF
                    IF a[1] THEN EXIT     MENU      END IF
                    IF a[1] THEN CONTINUE MENU      END IF
                    IF a[1] THEN EXIT     INPUT     END IF
                    IF a[1] THEN CONTINUE INPUT     END IF
-- EXIT DISPLAY *is* allowed by the compiler (despite error 4488)
                    IF a[1] THEN EXIT     DISPLAY   END IF
-- CONTINUE DISPLAY is not allowed by the compiler
--                  IF a[1] THEN CONTINUE DISPLAY   END IF
-- EXIT CONSTRUCT is not allowed by the compiler (error 4488)
--                  IF a[1] THEN EXIT     CONSTRUCT END IF
-- CONTINUE CONSTRUCT is not allowed by the compiler (error 4488)
--                  IF a[1] THEN CONTINUE CONSTRUCT END IF
                    IF a[1] THEN GOTO End_Label     END IF
                    IF a[1] THEN GOTO Mid_Label     END IF
LABEL Mid_label:
                    MESSAGE "You got here?  How?"
            NEXT FIELD y
                  END INPUT
                END DISPLAY
              END CONSTRUCT
            END INPUT
          COMMAND "Z"
             MESSAGE "Sucker!"
            CONTINUE MENU
          END MENU
        END MENU
      END WHILE
    END FOR
  END FOREACH
  LET y = 0

LABEL End_label:
  CLOSE WINDOW w

END FUNCTION

