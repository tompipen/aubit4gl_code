{
	CMNUL.sql  -  menu explosion stored procedures

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

{ explodes a particular menu branch level - null is the horz menu layer }

create procedure mnu_explode(link_mnu smallint, layer smallint)
  returning smallint, smallint, char(25), smallint;
    define code_mnu, link_app	smallint;
    define desc_mnu		char(25);
    define new_layer		smallint;

    foreach select mnu.code_mnu, mnu.link_app, mnu.desc_mnu
	      into code_mnu, link_app, desc_mnu
	      from mnu
	      where (mnu.link_mnu is null and link_mnu is null)
		 or (mnu.link_mnu=link_mnu)
	      order by link_app
	if (link_app is not null)
	then
	    if (link_app in (select app2usr.link_app from app2usr
				where app2usr.link_usr=user
				   or app2usr.link_usr="public"))
	    then
		return code_mnu, link_app, desc_mnu, layer with resume;
	    end if;
	else
	    foreach execute procedure mnu_explode(code_mnu, layer+1)
	      into code_mnu, link_app, desc_mnu, new_layer
		return code_mnu, link_app, desc_mnu, new_layer with resume;
	    end foreach;
	end if;
    end foreach;
    raise exception 100;
end procedure;

{ expands a particular menu branch level - null is the horz menu layer }

create procedure mnu_expand(link_mnu smallint)
  returning smallint, smallint, char(25), char(80);
    define code_mnu, link_app	smallint;
    define desc_mnu		char(25);
    define comment		char(80);

    foreach select mnu.code_mnu, mnu.link_app, mnu.desc_mnu
	      into code_mnu, link_app, desc_mnu
	      from mnu
	      where (mnu.link_mnu is null and link_mnu is null)
		 or (mnu.link_mnu=link_mnu)
	      order by link_app
	let comment="";
	select mnu_comment.comment into comment from mnu_comment
	  where mnu_comment.link_mnu=code_mnu;
	if (link_app is not null)
	then
	    if (link_app in (select app2usr.link_app from app2usr
				where app2usr.link_usr=user
				   or app2usr.link_usr="public"))
	    then
		return code_mnu, link_app, desc_mnu, comment with resume;
	    end if;
	elif (mnu_test(code_mnu)!=0)
	then
	    return code_mnu, link_app, desc_mnu, comment with resume;
	end if;
    end foreach;
    raise exception 100;
end procedure;

{ test for executable menu entries on all brach childs }

create procedure mnu_test(link_mnu smallint)
  returning smallint;
    define code_mnu, link_app	smallint;

    foreach select mnu.code_mnu, mnu.link_app
	      into code_mnu, link_app
	      from mnu
	      where (mnu.link_mnu=link_mnu)
	if (link_app is not null)
	then
	    if (link_app in (select app2usr.link_app from app2usr
				where app2usr.link_usr=user
				   or app2usr.link_usr="public"))
	    then
		return 1;
	    end if;
	elif (mnu_test(code_mnu)!=0)
	then
	    return 1;
	end if;
    end foreach;
    return 0;
end procedure;

{ Included just in case

grant execute on mnu_explode to public;
grant execute on mnu_expand to public;
grant execute on mnu_test to public }
