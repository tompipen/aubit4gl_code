#ifndef A4GL_FIELD_HANDLING
#define A4GL_FIELD_HANDLING


struct fh_field_entry {
        char *field_name;
        char *field_sub;
};

struct fh_field_list {
        struct fh_field_entry *fields;
        int nfields;
};

typedef struct fh_field_list t_field_list;

struct fh_field_entry *new_field_entry(char *f,char *n,int needs_quoting) ;
void free_field(struct fh_field_entry *field) ;
struct fh_field_list *new_field_list(void) ;
struct fh_field_list *append_field_to_list(struct fh_field_list *field_list, struct fh_field_entry *field) ;
struct fh_field_list *append_field_name_to_list (struct fh_field_list *field_list,char *n,char *s,int quoteit) ;
char *field_name_as_char(struct fh_field_entry *f) ;
char *field_name_list_as_char(struct fh_field_list *f) ;
char *field_name_list_as_or_char(struct fh_field_list *f) ;
#endif
