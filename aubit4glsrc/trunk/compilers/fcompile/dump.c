#include "form_x.h"

char *desc_str[]={
	"INCLUDE",
	"PICTURE",
	"FORMAT",
	"DEFAULT",
	"PROGRAM",
	"WIDGET",
	"CONFIG",
	"COMMENTS",
	0
};

char *desc_bool[]={
	"AUTONEXT",
	"REVERSE",
	"INVISIBLE",
	"NOENTRY",
	"VERIFY",
	"WORDWRAP",
	"COMPRESS",
	"UPSHIFT",
	"DOWNSHIFT",
	"REQUIRED",
	0
};


/**
 * Dumps a complete form description
 * It calls all the specific dumps(attributes, metrics, field description
 * and tables)
 *
 * @param f A pointer to the form description structure
 */
static dump_form_desc(struct_form *f) {
int a;
	printf("DB         : '%s'\n",f->dbname);
	printf("Delimiters : '%s'\n",f->delim);
	printf("maxcol     : %d\n",f->maxcol);
	printf("maxline    : %d\n",f->maxline);
	
printf("Screens :%d\n",f->snames.snames_len);
	for (a=0;a<f->snames.snames_len;a++) {
		printf("%s\n",f->snames.snames_val[a].name);
	}

	dump_attributes(f);
	dump_metrics(f);
	dump_fields_desc(f);
	dump_records(f);
	dump_tables(f);
}

/**
 * Make a text dump of the form attributes
 *
 * @param f A pointer to a form description record
 */
static dump_attributes(struct_form *f) {
	int a;
	int b;
	printf("\nAttributes %d\n",f->attributes.attributes_len);
	for (a=0;a<f->attributes.attributes_len;a++) {
		printf("Attribute %d\n",a);
		printf("   field_no : %d\n",f->attributes.attributes_val[a].field_no);
		printf("   colname : '%s'\n",f->attributes.attributes_val[a].colname);
		printf("   tabname : '%s'\n",f->attributes.attributes_val[a].tabname);
		printf("   subscript[0] : %d\n",f->attributes.attributes_val[a].subscripts[0]);
		printf("   subscript[1] : %d\n",f->attributes.attributes_val[a].subscripts[1]);
		printf("   subscript[2] : %d\n",f->attributes.attributes_val[a].subscripts[2]);
		printf("   datatype : %d\n",f->attributes.attributes_val[a].datatype);
		printf("   dynamic  : %d\n",f->attributes.attributes_val[a].dynamic);
		for (b=0;b<f->attributes.attributes_val[a].str_attribs.str_attribs_len;b++) {
			printf("          STRING (%d) %s='%s'\n",
f->attributes.attributes_val[a].str_attribs.str_attribs_val[b].type,
desc_str[f->attributes.attributes_val[a].str_attribs.str_attribs_val[b].type],
f->attributes.attributes_val[a].str_attribs.str_attribs_val[b].value);
	}
		for (b=0;b<f->attributes.attributes_val[a].bool_attribs.bool_attribs_len;b++) {
			printf("          BOOLEAN %d %s\n",
f->attributes.attributes_val[a].bool_attribs.bool_attribs_val[b],
desc_bool[f->attributes.attributes_val[a].bool_attribs.bool_attribs_val[b]]
);
	}
		printf("   colour : %d\n",f->attributes.attributes_val[a].colour);
}
}

/**
 * Make a text dump of all text elements from the screen image
 *
 * @param f A pointer to a form description record
 */
static dump_metrics(struct_form *f) {
int a;
	printf("\nMetrics %d\n",f->metrics.metrics_len);
	for (a=0;a<f->metrics.metrics_len;a++) {
	printf("a=%d x=%d y=%d w=%d scr=%d del=%d label='%s'\n",a,
	f->metrics.metrics_val[a].x,
	f->metrics.metrics_val[a].y,
	f->metrics.metrics_val[a].w,
	f->metrics.metrics_val[a].scr,
	f->metrics.metrics_val[a].delim_code,
	f->metrics.metrics_val[a].label);
}
}

/**
 * Text dumps screen record field information
 *
 * @param f A pointer to a form description record
 */
static dump_fields_desc(struct_form *f) {
int a,b;
printf("\nFields %d\n",f->fields.fields_len);
	for (a=0;a<f->fields.fields_len;a++) {
		printf(" %d Tag '%s'\n",a,f->fields.fields_val[a].tag);
		for (b=0;b<f->fields.fields_val[a].metric.metric_len;b++) {
			printf("   %d\n",f->fields.fields_val[a].metric.metric_val[b]);
		}
	}
}

/**
 * Make a text dump of the screen record information
 *
 * @param f A pointer to a form description record
 */
static dump_records(struct_form *f) {
int a,b;
printf("\nRecords %d\n",f->records.records_len);
	for (a=0;a<f->records.records_len;a++) {

		printf("%d '%s' %d\n",a,f->records.records_val[a].name,
				f->records.records_val[a].dim);
		for (b=0;b<f->records.records_val[a].attribs.attribs_len;b++) {
			printf("    %d\n", f->records.records_val[a].attribs.attribs_val[b]);
		}
	}
}

/**
 * Dumps a text representation of tables loaded from the parser
 *
 * @param f A pointer to a form description record
 */
static dump_tables(struct_form *f) {
int a;
	printf("\nTables %d\n",f->tables.tables_len);
	for (a=0;a<f->tables.tables_len;a++) {
		printf("%d '%s' '%s'\n",a,f->tables.tables_val[a].tabname,f->tables.tables_val[a].alias);
	}
}



