#  INSTALL.sh  -  4gwed quick compilation script
#
#	4gwEd, a dbaccess like 4glWorks based application
#	Copyright (C) 1999-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Oct 97
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

	This shell script will compile the application.
	It assumes that your enviromental variables are correctly set.
	Hit y to proceed, n to skip

EOF-entry
trap "" 2
read ans
trap 2
case $ans in
    y|Y)
	4glworks/cbuild 4gwapps/4gwed
	;;
    *)
	echo "Installation skipped"
	;;
esac
