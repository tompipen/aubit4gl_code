

#include "a4gl_libaubit4gl.h"


/* ==================== from a4gl_database.h ============== */

	/* #include "a4gl_incl_4gldef.h" */

	/**
	 * An SQL statement identification structure.
	 */
	struct s_sid {
		struct BINDING *ibind; /**< The input bind array */
		struct BINDING *obind; /**< The output bind array */
		int ni;                /**< Number of elements in the input bind array*/
		int no;               /**< Number of elements in the output bind array*/
		char *inputDescriptorName; /**< Name of input descriptor */
		char *outputDescriptorName; /**< Name of output descriptor */
		char *select;         /**< The SQL statement content */

	/* it looks like Andrej (me) messed up this while working on CygWin port
	not sure why I changed this to int, but it's causing lot of warnings
	on Linux in sql.c:
		int hstmt;
    */
		void *hstmt;
		char *statementName; /**< The name of the SQL statement */
	};

	/**
	 * The cursor identification structure.
	 */
	struct s_cid {
	  struct s_sid *statement;  /**< The statement used to declare the cursor */
	  int mode;	            /**< The cursor mode */
	  void *hstmt;
	};


