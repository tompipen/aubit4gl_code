# Some generic db access functions we can use for asql and a4gl menu programs

function table_select(lv_prompt)
  define lv_prompt char(64)
  define lv_tabname char(255)
  define lv_cnt integer
  define lv_arr array[4000] of char(18)
  define lv_sch array[4000] of char(18)
  define lv_num_tables integer
  define lv_found integer

code
    lv_num_tables=A4GLSQL_fill_array(1000,
                                     (char *)lv_arr,18,
                                     (char *)lv_sch,18,"TABLES",0,0);
endcode


    for lv_cnt=1 to lv_num_tables
        call set_pick(lv_cnt, get_table_name(lv_sch[lv_cnt] , lv_arr[lv_cnt]))
    end for
    call set_pick_cnt(lv_cnt-1)

    while true
        call prompt_pick(lv_prompt,"") returning lv_tabname

        if lv_tabname is not null then
            let lv_found=0
            for lv_cnt=1 to lv_num_tables
                if upshift(lv_tabname) = upshift(get_table_name(lv_sch[lv_cnt] ,lv_arr[lv_cnt])) then
                    let lv_found=1
                    exit for
                end if
            end for
    
            if lv_found=0 then
                error "Table not found"
            else
                exit while
            end if
        else
            exit while
    end if
end while


# This used to return upshift(lv_tabname) 
# but that seems wrong to me...

return lv_tabname

end function


function select_db()
  define lv_arr array[100] of char(100);
  define lv_num_dbs integer
  define lv_cnt integer
  define lv_curr_db char(255)
  define lv_name char(255)
  define lv_newname char(255)
  define a integer
    let lv_curr_db=get_db();

code
    lv_num_dbs=A4GLSQL_fill_array(100,(char *)lv_arr,100,0,0,"DATABASES",0,0);
endcode

    for a=1 to lv_num_dbs
        call set_pick(a,lv_arr[a])
    end for

    call set_pick_cnt(lv_num_dbs)

    let lv_newname=prompt_pick("SELECT DATABASE >>","")
    if lv_newname is null then
        let lv_newname=lv_curr_db
    end if

    if lv_newname is not null and lv_newname not matches " " then
        whenever error continue

        close database
        database lv_newname
        whenever error stop

        if sqlca.sqlcode=0 then
            call set_curr_db(lv_newname)
            call display_banner()
            message "Database Opened"
        else
            if check_and_report_error() then
                return
            end if
        end if
    end if
end function


function get_table_name(lv_sch,lv_tab)
define lv_sch char(256)
define lv_tab char(256)
if lv_sch is null or length(lv_sch)=0  or lv_sch=lv_tab then
        return lv_tab clipped
else
        return (lv_sch clipped||"."||lv_tab clipped)
end if
end function




function set_current_db(lv_name)
define lv_name char(200)
return lv_name
end function



function check_db(dbname)
    define dbname char(255)
    return dbname
end function

