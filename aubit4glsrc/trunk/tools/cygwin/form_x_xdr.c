#include <rpc/rpc.h>
#include "form_x.h"


bool_t
xdr_struct_metrics (xdrs, objp)
     XDR *xdrs;
     struct_metrics *objp;
{
  if (!xdr_int (xdrs, &objp->x))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->y))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->w))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->scr))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->delim_code))
    {
      return (FALSE);
    }
  if (!xdr_string (xdrs, &objp->label, ~0))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->pos_code))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->dlm1))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->dlm2))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->field))
    {
      return (FALSE);
    }
  return (TRUE);
}




bool_t
xdr_struct_form_field (xdrs, objp)
     XDR *xdrs;
     struct_form_field *objp;
{
  if (!xdr_string (xdrs, &objp->tag, ~0))
    {
      return (FALSE);
    }
  if (!xdr_array
      (xdrs, (char **) &objp->metric.metric_val,
       (u_int *) & objp->metric.metric_len, ~0, sizeof (int), xdr_int))
    {
      return (FALSE);
    }
  return (TRUE);
}




bool_t
xdr_FIELD_ATTRIBUTES_BOOL (xdrs, objp)
     XDR *xdrs;
     FIELD_ATTRIBUTES_BOOL *objp;
{
  if (!xdr_enum (xdrs, (enum_t *) objp))
    {
      return (FALSE);
    }
  return (TRUE);
}




bool_t
xdr_FA_COLOUR (xdrs, objp)
     XDR *xdrs;
     FA_COLOUR *objp;
{
  if (!xdr_enum (xdrs, (enum_t *) objp))
    {
      return (FALSE);
    }
  return (TRUE);
}




bool_t
xdr_FA_ATTRIBUTES_STRING (xdrs, objp)
     XDR *xdrs;
     FA_ATTRIBUTES_STRING *objp;
{
  if (!xdr_enum (xdrs, (enum_t *) objp))
    {
      return (FALSE);
    }
  return (TRUE);
}




bool_t
xdr_struct_field_attr_string (xdrs, objp)
     XDR *xdrs;
     struct_field_attr_string *objp;
{
  if (!xdr_FA_ATTRIBUTES_STRING (xdrs, &objp->type))
    {
      return (FALSE);
    }
  if (!xdr_string (xdrs, &objp->value, ~0))
    {
      return (FALSE);
    }
  return (TRUE);
}




bool_t
xdr_struct_scr_field (xdrs, objp)
     XDR *xdrs;
     struct_scr_field *objp;
{
  if (!xdr_int (xdrs, &objp->field_no))
    {
      return (FALSE);
    }
  if (!xdr_string (xdrs, &objp->colname, ~0))
    {
      return (FALSE);
    }
  if (!xdr_string (xdrs, &objp->tabname, ~0))
    {
      return (FALSE);
    }
  if (!xdr_vector (xdrs, (char *) objp->subscripts, 3, sizeof (int), xdr_int))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->datatype))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->dynamic))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->do_reverse))
    {
      return (FALSE);
    }
  if (!xdr_array
      (xdrs, (char **) &objp->str_attribs.str_attribs_val,
       (u_int *) & objp->str_attribs.str_attribs_len, ~0,
       sizeof (struct_field_attr_string), xdr_struct_field_attr_string))
    {
      return (FALSE);
    }
  if (!xdr_array
      (xdrs, (char **) &objp->bool_attribs.bool_attribs_val,
       (u_int *) & objp->bool_attribs.bool_attribs_len, ~0,
       sizeof (FIELD_ATTRIBUTES_BOOL), xdr_FIELD_ATTRIBUTES_BOOL))
    {
      return (FALSE);
    }
  if (!xdr_FA_COLOUR (xdrs, &objp->colour))
    {
      return (FALSE);
    }
  return (TRUE);
}




bool_t
xdr_struct_tables (xdrs, objp)
     XDR *xdrs;
     struct_tables *objp;
{
  if (!xdr_string (xdrs, &objp->tabname, ~0))
    {
      return (FALSE);
    }
  if (!xdr_string (xdrs, &objp->alias, ~0))
    {
      return (FALSE);
    }
  return (TRUE);
}




bool_t
xdr_screen_name (xdrs, objp)
     XDR *xdrs;
     screen_name *objp;
{
  if (!xdr_string (xdrs, &objp->name, ~0))
    {
      return (FALSE);
    }
  return (TRUE);
}




bool_t
xdr_struct_screen_record (xdrs, objp)
     XDR *xdrs;
     struct_screen_record *objp;
{
  if (!xdr_string (xdrs, &objp->name, ~0))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->dim))
    {
      return (FALSE);
    }
  if (!xdr_array
      (xdrs, (char **) &objp->attribs.attribs_val,
       (u_int *) & objp->attribs.attribs_len, ~0, sizeof (int), xdr_int))
    {
      return (FALSE);
    }
  return (TRUE);
}




bool_t
xdr_struct_labels (xdrs, objp)
     XDR *xdrs;
     struct_labels *objp;
{
  if (!xdr_string (xdrs, &objp->label_content, ~0))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->x))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->y))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->w))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->scr))
    {
      return (FALSE);
    }
  return (TRUE);
}




bool_t
xdr_struct_form (xdrs, objp)
     XDR *xdrs;
     struct_form *objp;
{
  if (!xdr_string (xdrs, &objp->magic1, ~0))
    {
      return (FALSE);
    }
  if (!xdr_string (xdrs, &objp->dbname, ~0))
    {
      return (FALSE);
    }
  if (!xdr_string (xdrs, &objp->delim, ~0))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->maxcol))
    {
      return (FALSE);
    }
  if (!xdr_int (xdrs, &objp->maxline))
    {
      return (FALSE);
    }
  if (!xdr_array
      (xdrs, (char **) &objp->snames.snames_val,
       (u_int *) & objp->snames.snames_len, ~0, sizeof (screen_name),
       xdr_screen_name))
    {
      return (FALSE);
    }
  if (!xdr_array
      (xdrs, (char **) &objp->attributes.attributes_val,
       (u_int *) & objp->attributes.attributes_len, ~0,
       sizeof (struct_scr_field), xdr_struct_scr_field))
    {
      return (FALSE);
    }
  if (!xdr_array
      (xdrs, (char **) &objp->metrics.metrics_val,
       (u_int *) & objp->metrics.metrics_len, ~0, sizeof (struct_metrics),
       xdr_struct_metrics))
    {
      return (FALSE);
    }
  if (!xdr_array
      (xdrs, (char **) &objp->fields.fields_val,
       (u_int *) & objp->fields.fields_len, ~0, sizeof (struct_form_field),
       xdr_struct_form_field))
    {
      return (FALSE);
    }
  if (!xdr_array
      (xdrs, (char **) &objp->records.records_val,
       (u_int *) & objp->records.records_len, ~0,
       sizeof (struct_screen_record), xdr_struct_screen_record))
    {
      return (FALSE);
    }
  if (!xdr_array
      (xdrs, (char **) &objp->tables.tables_val,
       (u_int *) & objp->tables.tables_len, ~0, sizeof (struct_tables),
       xdr_struct_tables))
    {
      return (FALSE);
    }
  if (!xdr_string (xdrs, &objp->magic2, ~0))
    {
      return (FALSE);
    }
  return (TRUE);
}
