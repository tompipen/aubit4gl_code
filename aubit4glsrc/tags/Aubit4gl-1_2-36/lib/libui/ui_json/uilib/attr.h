#define attr_min(X,Y) (((X) < (Y)) ? (X) : (Y))


struct s_syncvalue {
        char *value;
	char *fieldname;
	int touched;
        int fieldtype;
};


struct s_syncvalues {
	int nvalues;
	struct s_syncvalue *vals;
};

struct s_row {
	int rownum;
	struct s_syncvalues sync;
};

struct s_rows {
	int nrows;
	struct s_row *row;
};

struct s_attr {
	char *id;
	char *envelopeId;
	char *yourId;
	char *data;
	char *type;
	struct s_syncvalues sync;
	struct s_rows rows;
	int arrline;
	int scrline;
	int arrcount;
	char *lastkey;
	int lastcursor;
	char *infield;
        char *fileid;
        int filelen;
        char *programname;
	int bufferTouched;
	int cnt;
	int maxcnt;
} ;


struct s_attr *json_parse (char *s) ;
void dump_attr(struct s_attr *a);
int my_yyinput(char *buf,int maxsize);
struct s_attr * getTriggeredAttribute (int  sock_read);
