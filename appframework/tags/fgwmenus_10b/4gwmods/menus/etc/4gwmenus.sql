{
	4GWMENUS.sql  -  tables creation

	4gwMenus, an isql menus like 4glWorks module
	Copyright (C) 1998-2002 Marco Greco (marco@4glworks.com)

	Initial release: Oct 97
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

create table applications		{ master application table }
(
    code_app	smallint not null
		primary key,		{ application code }
    desc_app	char(40) not null
		unique,			{ application description }
    app_type	char(2) not null,	{ the application type }
    check (app_type in ("M", "Q", "P", "F", "E", "EB", "EW"))
);

create table application_rows		{ application detail: the actual code }
(
    link_app	smallint not null
		references applications,	{ link to applications }
    row_num	smallint not null,		{ row number }
    row_txt	char(78) not null,		{ the code }
    unique (link_app, row_num)
);

create table app2usr			{ applications to users mtm }
(
    link_app	smallint not null
		references applications,	{ link to application }
    link_usr	char(8) not null,		{ user name }
    unique (link_usr, link_app)
);

create table mnu			{ menu entries }
(
    code_mnu	smallint not null
		primary key,		{ menu code }
    desc_mnu	char(25) not null,	{ what will come out on screen }
    link_mnu	smallint
		references mnu,		{ link to father menu entry: null->horz }
    link_app	smallint
		references applications,{ link to application (only leafs) }
    unique (link_mnu, desc_mnu)
);

create table mnu_comment		{ horz menu comments }
(
    link_mnu	smallint not null	{ link to menu entry }
		references mnu,
    comment	char(80)		{ menu comment }
);

create view app as
  select applications.* from applications, app2usr
    where applications.code_app=app2usr.link_app
      and (app2usr.link_usr=user or app2usr.link_usr="public");

create view app_rows as
  select application_rows.* from application_rows, app2usr
    where application_rows.link_app=app2usr.link_app
      and (app2usr.link_usr=user or app2usr.link_usr="public");

create view mnu_changes(cnt, top) as
  select count(*), max(code_mnu) from mnu;

revoke all on applications from public;
revoke all on application_rows from public;
revoke all on app2usr from public;
revoke all on mnu from public;
revoke all on mnu_comment from public;
revoke all on app from public;
grant select on app to public;
revoke all on app_rows from public;
grant select on app_rows to public;
revoke all on mnu_changes from public;
grant select on mnu_changes to public;
