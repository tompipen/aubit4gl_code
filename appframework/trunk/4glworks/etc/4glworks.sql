{
	4GLWORKS.sql  -  printer table definitions

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Oct 92
	Current release: Jan 02

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
}

create table mdl			{ Printer models }
(
    code_mdl	smallint not null
		primary key,		{ model code }
    desc_mdl	char(40) not null
		unique			{ model description }
);

create table mdl_rows			{ Model control strings }
(
    link_mdl	smallint not null
		references mdl,		{ link to model }
    str_name    char(8) not null,	{ string name  }
    str_attr	smallint,		{ string attrs }
    string	char(40),		{ the string itself! }
    unique (link_mdl, str_name, str_attr),
    check ((str_attr>0) or
	   ((str_name!="pitch") and (str_name!="line")))
);

create table ptr			{ Printers }
(
    code_ptr	smallint not null
		primary key,		{ printer code }
    desc_ptr	char(40) not null
		unique,			{ printer description }
    link_mdl	smallint not null
		references mdl,		{ link to model }
    dest	char(78) not null,	{ report pipe }
    reject	char(78),		{ scheduler test, etc }
    disabled	char(78),		{ printer enabled test }
    enable	char(78)		{ enable printer script }
);

create table frm			{ Forms }
(
    code_frm	smallint not null
		primary key,		{ form code }
    desc_frm	char(40) not null
		unique,			{ form description }
    link_mdl	smallint not null
		references mdl,		{ link to model }
    form_length	smallint not null
		check (form_length>0),	{ paper length ("/48) }
    form_width	smallint not null
		check (form_width>0),	{ paper width (points) }
    left_margin	smallint not null
		check (left_margin>=0),	{ left margin (points) }
    top_of_form	char(40),		{ cursor to top of form string }
{   form_header	text,			  Page header blob
    form_footer	text			  Page footer blob }
    form_header	char(14),		{ Page header file }
    form_footer	char(14)		{ Page footer file }
);

create table frm2ptr			{ MtM forms to printers }
(
    link_frm	smallint not null
		references frm,		{ link to form }
    link_ptr	smallint not null
		references ptr,		{ link to printer }
    init	char(40),		{ f2p specific init string }
    unique (link_frm, link_ptr)
);

revoke all on ptr from public;
revoke all on frm from public;
revoke all on frm2ptr from public;
revoke all on mdl from public;
revoke all on mdl_rows from public;
grant select on ptr to public;
grant select on frm to public;
grant select on frm2ptr to public;
grant select on mdl to public;
grant select on mdl_rows to public;
