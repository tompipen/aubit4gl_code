#  INSTALL.sh  -  Menusdemo quick compilation & database creation script
#
#	4gwMenus, an isql menus like 4glWorks module
#	Copyright (C) 1998-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Feb 97
#	Current release: Jan 02
#
#	This library is free software; you can redistribute it and/or
#	modify it under the terms of the GNU Lesser General Public
#	License as published by the Free Software Foundation; either
#	version 2.1 of the License, or (at your option) any later version.
#
#	This library is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#	Lesser General Public License for more details.
#
#	You should have received a copy of the GNU Lesser General Public
#	License along with this library; if not, write to the Free Software
#	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
cat <<'EOF-entry'

	This shell script will create the required menus tables in the
	4glworks sample database and compile the 4gwMenus sample
	application.
	It assumes that your enviromental variables are correctly set,
	and that the fgwdemo database exists already.
	Hit y to proceed, n to skip

EOF-entry
trap "" 2
read ans
trap 2
case $ans in
    y|Y)
	dbaccess fgwdemo < 4gwmods/menus/etc/4gwmenus.sql
	dbaccess fgwdemo < 4gwmods/menus/etc/cmnul.sql
	dbaccess fgwdemo < 4gwapps/menusdemo/etc/menusdemo.sql
	4glworks/cbuild 4gwapps/menusdemo
	;;
    *)
	echo "Installation skipped"
	;;
esac
