
###############################################################################
#
# List handling functions...
#
###############################################################################

function list_init(lv_tabno)
define lv_tabno integer
whenever error continue
create temp table a4gltaperform ( tid smallint,pos integer, id integer) with no log
create unique index a4gltaperform_i on a4gltaperform(tid,pos)
whenever error stop
delete from a4gltaperform where tid=lv_tabno
end function


###############################################################################
function list_add(lv_tabno,lv_position,lv_id)
define lv_tabno,lv_position,lv_id integer
insert into a4gltaperform values(lv_tabno,lv_cnt,lv_id)
END FUNCTION



###############################################################################
function list_get(lv_tabno,lv_position)
define lv_tabno,lv_position,lv_id integer
SELECT id INTO lv_id FROM a4gltaperform WHERE pos=lv_position AND tid=lv_tabno
if sqlca.sqlcode!=0 then
	ERROR "Some error getting unique ID"
	RETURN -1
end if
return lv_id
end function


###############################################################################
function list_remove(lv_tabno,lv_position)
define lv_tabno,lv_position integer
	delete from a4gltaperform where tid=lv_tabno and pos=lv_position 
	update a4gltaperform set pos=pos-1 where tid=lv_tabno and pos>lv_position

end function

###############################################################################
