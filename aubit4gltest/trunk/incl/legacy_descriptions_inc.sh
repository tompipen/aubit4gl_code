##############################################################################
#							Describe tests:
##############################################################################
#It is nececery to clasify tests here, so we can avoid tests that would not
#complete successfuly under particular combinations of tests and environments
#-----------------------------------------------------------------------
#PLEASE NOTE THAT YOU ARE NO LONGER EXPECTED TO DESCRIBE TESTS HERE, BUT
#INSTEAD TO THIS IN THE MAKEFILE OF THE TEST ITSELF
#-----------------------------------------------------------------------
#This legacy descriptions will be removed from here, as test makefiles are 
#replaced with the one in template/ and tests described in taht makefile

#Tests that require a database to compile/run:
DB_TESTS="1 14 36 51 63 68 72 73 76 80 100 101 91 94 95 98 99 206 207 212"

#Tests that use ESQL compiler output, instead of C output
#TODO:This constraint should be obsolete once we replace the makefiles with the
#template one- all code must be compilable with all language outputs anyway
EC_TESTS="36 68"

#Tests that will fail if not running on screen (curses):
NOSILENT_TESTS="11"

#Tests that open windows
#TODO- this is currently just added to TUI_TESTS - separate it
WINDOW_TESTS="205 217"

#Tests that use curses and/or screeen dump and may fail when TERM!=xterm
#Anything that uses a screen dump may have specific attributes set which may
#fail if TERM!=xterm
#This core dumps on MinGW and messes up the terminal completely:
#On Cygwin they don't core dump, but this tests fail:
#15:missing ---- line
#37:Form driver complaint
#74:platform specific characters
TUI_TESTS="10 11 15 22 23 24 26 27 30 31 33 34 37 38 40 41 42 53 54 56 57 59 \
	69 70 74 77 79 86 78 $WINDOW_TESTS"

#Tests that use .per form files:
FORM_TESTS="10 11 15 22 23 24 26 27 29 30 31 33 34 37 38 78 40 41 42 92 77 \
	78 53 54 56 57 58 59 63 69 70 74 79 80 86 202 209 239"

#Tests that use REPORT
REPORT_TESTS="11 21 25 100 93 14 32 39 48 51 64 71 72 75 82"

#Tests that use graphic characters in forms that may be platform dependent
GRAPHIC_TESTS="6 74"

#Tests that wait for user's input in CONSOLE mode, because automated testing
#was not implemented there, so we must skip them untill this is implemented
CONSOLE_PROMPT_TESTS="3"

#tests that use aclfgl_dump_screen, A4GL_clr_window or aclfgl_fgl_drawbox, so
#they won't work in CONSOLE mode
#core dumps in CONSOLE mode: 14 36
DUMP_SCREEN_TESTS="10 102 103 104 105 11 15 220 223 229 230 231 236 247 \
	252 254 263 29 4 6 67 74 8 276 277 278"

#66-10 minutes to COMPILE (also with -esqli AND -eci)
LONG_TESTS="66"

#All other tests not belonging to any of the above groups should be listed here:
UNKNOWN_TESTS=" \
    "

#Tests that are certified to run (-eci) If they fail (with -eci), something was 
#probably broken in current code, or that particular combination of confuguration 
#options/compiler or run-time settings is not capable of performing all functions it should
CERT_TESTS="1 3 4 6 8 9 10 11 12 13 14 15 21 22 23 24 25 26 27 28 29 30 31 32 33 34 \
		35 36 37 38 39 40 41 42 47 48 49 50 51 52 53 54 56 57 59 60 61 62 63 64 66 67 \
		68 69 70 71 72 73 74 75 76 77 78 79 80 82 84 86 90 96 97 99 202 204 205 \
		92 93 94 98 101 203 210 206 207 208 209 212 217 218 239"

#List of tests that where superceeded or obsoleted for various reasons,
#and should be silently skipped
OBSOLETE_TESTS="58 65 250"

#List of all described tests, for use with -described switch, to prevent running not
#described (new) tests that might fail under particular combination of Aubit
#settings and platforms:
ALL_DESCRIBED_TESTS="$DB_TESTS $EC_TESTS $NOSILENT_TESTS $TUI_TESTS $FORM_TESTS \
		$REPORT_TESTS $GRAPHIC_TESTS $CONSOLE_PROMPT_TESTS $DUMP_SCREEN_TESTS \
		$LONG_TESTS	$UNKNOWN_TESTS $CERT_TESTS $OBSOLETE_TESTS"

#Tests with makefile modified so that they can compile/run P-code
PCODE_ENABLED="3 101 210"

#tests that fail when running as cron job
NO_CRON_TESTS="6 8"
