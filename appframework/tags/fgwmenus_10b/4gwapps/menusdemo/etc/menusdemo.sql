{
	MENUSDEMO.sql  -  sample menus entries

	4gwMenus, an isql menus like 4glWorks module
	Copyright (C) 1998-2002 Marco Greco (marco@4glworks.com)

	Initial release: Apr 98
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
load from '4gwapps/menusdemo/etc/applications.unl' insert into applications;
load from '4gwapps/menusdemo/etc/application_rows.unl' insert into application_rows;
load from '4gwapps/menusdemo/etc/app2usr.unl' insert into app2usr;
load from '4gwapps/menusdemo/etc/mnu.unl' insert into mnu;
load from '4gwapps/menusdemo/etc/mnu_comment.unl' insert into mnu_comment
