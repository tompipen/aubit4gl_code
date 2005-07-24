#	ISTBG.4gl  -  dtb/stb_scroller related globals
#
#	The 4glWorks application framework
#	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Apr 96
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
globals

  define
#
#  current search, needed in case of a MB_declare messages
#  *note* that stb_ and dtb_scrollers were *not* written to be used in
#  multiple pane viewers. Should you modify them to be, then you have to
#  replicate it or drop it altogether
#
      search		char(2048),
#
#  link to record(s) - used by stb_ e dtb_scroller for messages MB_copyrec,
#  MB_changerec and MB_deleterec. Reloaded at every access to the DB, so no
#  need to replicate
#
      code_1		char(8),
      code_2		char(8)

end globals
