CREATE OR REPLACE FUNCTION next_seq_id() RETURNS trigger AS $$

    my ($col,$seq)=@_;
    my($newval);
    $newval=$_TD->{new}{$col};
    if ($newval==0) {
        $rv=spi_exec_query('SELECT nextval(\''.$seq.'\') as nextval', 1);
        $_TD->{new}{$col}= $rv->{rows}[0]->{nextval};
        return "MODIFY";  # modify row and execute INSERT/UPDATE command
    } else {
        if ($newval>0) {

                $rv=spi_exec_query('SELECT setval(\''.$seq.'\','.($newval).') ', 1);
        }
    }
    return;
$$ LANGUAGE plperl;



CREATE OR REPLACE FUNCTION mdy(m integer, d integer, y integer) RETURNS date AS $$
BEGIN
                RETURN to_date(m||' '||d||' '||y, 'MM DD YYYY');
END;
$$ LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION dt_as_char (dt timestamp with time zone, starttime integer,endtime integer) RETURNS text AS $$
 DECLARE 
	rval text;
	used integer;

	v_iy integer;
	v_im integer;
	v_id integer;
	v_ih integer;
	v_imin integer;
	v_is integer;
	v_if float;

	v_ty text;
	v_tm text;
	v_td text;
	v_th text;
	v_tmin text;
	v_ts text;
	v_tf text;

 BEGIN
	v_iy=date_part('YEAR',dt);
	v_im=date_part('MONTH',dt);
	v_id=date_part('DAY',dt);
	v_ih=date_part('HOUR',dt);
	v_imin=date_part('MINUTE',dt);
	v_if=date_part('SECOND',dt);
	v_is=v_if::int;

-- Make sure we've got a 4 digit year
	v_ty=v_iy;
	while (length(v_ty)<4)  LOOP
		v_ty:='0'||v_ty;
	end loop;

-- Make sure we've got a 2 digit month
	v_tm=v_im;
	while (length(v_tm)<2)  LOOP
		v_tm:='0'||v_tm;
	end loop;

	v_td=v_id;
	while (length(v_td)<2)  LOOP
		v_td:='0'||v_td;
	end loop;
	v_th=v_ih;
	while (length(v_th)<2)  LOOP
		v_th:='0'||v_th;
	end loop;

	v_tmin=v_imin;
	while (length(v_tmin)<2)  LOOP
		v_tmin:='0'||v_tmin;
	end loop;

	v_ts=v_is;
	v_tf=v_if;
	while (length(v_ts)<2)  LOOP
		v_ts:='0'||v_ts;
		v_tf:='0'||v_tf; -- do it on the fractional part too...
	end loop;

 used:=0;

 IF 1>=starttime AND 1<=endtime THEN
	used:=1;
	rval=v_ty;
 END IF;

 IF 2>=starttime AND 2<=endtime THEN
	if used THEN
		rval:=rval||'-'||v_tm;
	else
		rval:=v_tm;
	end if;
	used:=1;
 END IF;

 IF 3>=starttime AND 3<=endtime THEN
	if used THEN
		rval:=rval||'-'||v_td;
	else
		rval:=v_td;
	end if;
	used:=1;
 END IF;

 IF 4>=starttime AND 4<=endtime THEN
	if used THEN
		rval:=rval||' '||v_th;
	else
		rval:=t_vh;
	end if;
	used:=1;
 END IF;

 IF 5>=starttime AND 5<=endtime THEN
	if used THEN
		rval:=rval||':'||v_tmin;
	else
		rval:=v_tmin;
	end if;
	used:=1;
 END IF;

 IF endtime=6 THEN
	if used THEN
		rval:=rval||':'||v_ts;
	else
		rval:=v_ts;
	end if;
	used:=1;
 END IF;

 IF endtime>6 THEN
	rval:=rval||':'||v_tf;
 END IF;

  

 RETURN rval;
 END;
 $$  

LANGUAGE plpgsql;

