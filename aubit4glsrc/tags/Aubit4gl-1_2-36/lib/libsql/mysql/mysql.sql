drop function matches_to_regexp;

DELIMITER $$
CREATE FUNCTION matches_to_regexp (str varchar(1000),esc varchar(1000)) RETURNS varchar(1000)  NO SQL deterministic
BEGIN
declare lv_cnt integer;
        declare lv_rval varchar(1000);
        declare lv_c char;
        declare lv_contains_dot_start integer;
        set lv_cnt=0;
        set lv_rval='^';
        set lv_contains_dot_start=0;

-- We should probably be looking at the esc too - but we'll leave that for now...

	set lv_cnt=0;


	doloop: LOOP

		set lv_cnt=lv_cnt+1;
		if lv_cnt > length(str) then 
			leave doloop;
		end if;

                set lv_c=substring(str,lv_cnt,1);

                if lv_c='?' then
                        set lv_rval=concat(lv_rval,'.');
                        set lv_contains_dot_start=1;
                else
                        if lv_c='*' then
                                set lv_rval=concat(lv_rval,'.*');
                                set lv_contains_dot_start=1;
                        else
                                if lv_c='.' then
                                        set lv_rval=concat(lv_rval,'.');
                                else
                                        set lv_rval=concat(lv_rval,lv_c);
                                end if;
                        end if;
                end if;
        end loop doloop;

        if lv_contains_dot_start=1 then
                set lv_rval=concat(lv_rval,'[ ]*$');
        end if;

        return lv_rval;

 END $$


select matches_to_regexp('*@aubit.com*','') ;

