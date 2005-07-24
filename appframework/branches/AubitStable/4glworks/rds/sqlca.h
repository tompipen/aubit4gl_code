/*
	SQLCA.h  -  sqlca standin for 4gl rds only systems

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Oct 99
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
*/

#ifndef _SQLCA
#define _SQLCA
struct sqlca_s
{
    long sqlcode;
}

extern struct sqlca_s sqlca;
#endif
