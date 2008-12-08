CREATE TRUSTED LANGUAGE "plperl" HANDLER "plperl_call_handler";
CREATE TRUSTED LANGUAGE "plpgsql" HANDLER "plpgsql_call_handler" VALIDATOR "plpgsql_validator";


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







CREATE OR REPLACE FUNCTION char_to_dt_extended (dt text, starttime text, endtime text) RETURNS timestamp AS $$
BEGIN
        return to_timestamp(dt, A4GL_gettimestring(starttime, endtime));
END;
$$
LANGUAGE plpgsql;



CREATE OR REPLACE FUNCTION dt_extend (dt timestamp, starttime text, endtime text) RETURNS timestamp AS $$
DECLARE
        ls integer;
        le integer;
        ts timestamp;
        tc integer; -- count the number of matches
        lm_ls integer; -- last match
        lm_le integer; -- last match

BEGIN
        ls=dt_string_to_int(starttime);
        le=dt_string_to_int(endtime);


        -- lets see if it just 'works'...
        ts=dt;

        if ts is not null then
                return ts;
        end if;

        for ls in 1..6 LOOP
                for le in 1..6 LOOP

                        ts:=to_timestamp(dt, A4GL_gettimestring(ls,le));

                        if ts is not null then
                                tc:=tc+1;
                                lm_ls:=ls;
                                lm_le:=le;
                        end if;

                end loop;
        end loop;

        if le=6 then -- If we've got some seconds we might as well use them all
                le:=11;
        end if;

        if tc=1 then
                return to_timestamp(dt, A4GL_gettimestring(lm_ls,lm_le));
        else
                -- This will be null - because if it were not
                -- it would have already been returned!
                return to_timestamp(dt, A4GL_gettimestring(ls,le));
        end if;
END;
$$

LANGUAGE plpgsql;



CREATE OR REPLACE FUNCTION dt_extend (dt text, starttime text, endtime text) RETURNS timestamp AS $$
DECLARE
        ls integer;
        le integer;
        ts timestamp;
        tc integer; -- count the number of matches
        lm_ls integer; -- last match
        lm_le integer; -- last match

BEGIN
        ls=dt_string_to_int(starttime);
        le=dt_string_to_int(endtime);


        -- lets see if it just 'works'...
        ts=to_timestamp(dt, A4GL_gettimestring(ls,le));

        if ts is not null then
                return ts;
        end if;

        for ls in 1..6 LOOP
                for le in 1..6 LOOP

                        ts:=to_timestamp(dt, A4GL_gettimestring(ls,le));

                        if ts is not null then
                                tc:=tc+1;
                                lm_ls:=ls;
                                lm_le:=le;
                        end if;

                end loop;
        end loop;

        if le=6 then -- If we've got some seconds we might as well use them all
                le:=11;
        end if;

        if tc=1 then
                return to_timestamp(dt, A4GL_gettimestring(lm_ls,lm_le));
        else
                -- This will be null - because if it were not
                -- it would have already been returned!
                return to_timestamp(dt, A4GL_gettimestring(ls,le));
        end if;
END;
$$

LANGUAGE plpgsql;




CREATE OR REPLACE FUNCTION A4GL_gettimestring (p_starttime integer, p_endtime integer) RETURNS text AS $$
 BEGIN
	
	return A4GL_gettimestring(p_starttime::text, p_endtime::text);
 END;
 $$
LANGUAGE plpgsql;



CREATE OR REPLACE FUNCTION A4GL_gettimestring (p_starttime text, p_endtime text) RETURNS text AS $$
 DECLARE
        str text;
        starttime text; endtime text;
 BEGIN
        str:='';
        starttime:=p_starttime;
        endtime:=p_endtime;

        if starttime='1' then starttime:='YEAR'; end if;
        if starttime='2' then starttime:='MONTH'; end if;
        if starttime='3' then starttime:='DAY'; end if;
        if starttime='4' then starttime:='HOUR'; end if;
        if starttime='5' then starttime:='MINUTE'; end if;
        if starttime='6' then starttime:='SECOND'; end if;
        if starttime='7' then starttime:='FRACTION(1)'; end if;
        if starttime='8' then starttime:='FRACTION(2)'; end if;
        if starttime='9' then starttime:='FRACTION(3)'; end if;
        if starttime='10' then starttime:='FRACTION(4)'; end if;
        if starttime='11' then starttime:='FRACTION(5)'; end if;

        if endtime='1' then endtime:='YEAR'; end if;
        if endtime='2' then endtime:='MONTH'; end if;
        if endtime='3' then endtime:='DAY'; end if;
        if endtime='4' then endtime:='HOUR'; end if;
        if endtime='5' then endtime:='MINUTE'; end if;
        if endtime='6' then endtime:='SECOND'; end if;
        if endtime='7' then endtime:='FRACTION(1)'; end if;
        if endtime='8' then endtime:='FRACTION(2)'; end if;
        if endtime='9' then endtime:='FRACTION(3)'; end if;
        if endtime='10' then endtime:='FRACTION(4)'; end if;
        if endtime='11' then endtime:='FRACTION(5)'; end if;



        if starttime='YEAR' and endtime='YEAR' then
                str:='YYYY';
        end if;
        if starttime='YEAR' and endtime='MONTH' then
                str:='YYYY-MM';
        end if;
        if starttime='YEAR' and endtime='DAY' then
                str:='YYYY-MM-DD';
        end if;
        if starttime='YEAR' and endtime='HOUR' then
                str:='YYYY-MM-DD HH24';
        end if;
        if starttime='YEAR' and endtime='MINUTE' then
                str:='YYYY-MM-DD HH24:MI';
        end if;
        if starttime='YEAR' and endtime='SECOND' then
                str:='YYYY-MM-DD HH24:MI:SS';
        end if;
        if starttime='YEAR' and ( endtime='FRACTION' OR endtime='FRACTION(1)' OR endtime='FRACTION(2)' OR endtime='FRACTION(3)' OR endtime='FRACTION(4)' OR endtime='FRACTION(5)' ) then
                str:='YYYY-MM-DD HH24:MI:SS.MS';
        end if;

        if starttime='MONTH' and endtime='MONTH' then
                str:='MM';
        end if;
        if starttime='MONTH' and endtime='DAY' then
                str:='MM-DD';
        end if;
        if starttime='MONTH' and endtime='HOUR' then
                str:='MM-DD HH24';
        end if;
        if starttime='MONTH' and endtime='MINUTE' then
                str:='MM-DD HH24:MI';
        end if;
        if starttime='MONTH' and endtime='SECOND' then
                str:='MM-DD HH24:MI:SS';
        end if;
        if starttime='MONTH' and ( endtime='FRACTION' OR endtime='FRACTION(1)' OR endtime='FRACTION(2)' OR endtime='FRACTION(3)' OR endtime='FRACTION(4)' OR endtime='FRACTION(5)' ) then
                str:='MM-DD HH24:MI:SS.MS';
        end if;

        if starttime='DAY' and endtime='DAY' then
                str:='DD';
        end if;
        if starttime='DAY' and endtime='HOUR' then
                str:='DD HH24';
        end if;
        if starttime='DAY' and endtime='MINUTE' then
                str:='DD HH24:MI';
        end if;
        if starttime='DAY' and endtime='SECOND' then
                str:='DD HH24:MI:SS';
        end if;
        if starttime='DAY' and ( endtime='FRACTION' OR endtime='FRACTION(1)' OR endtime='FRACTION(2)' OR endtime='FRACTION(3)' OR endtime='FRACTION(4)' OR endtime='FRACTION(5)' ) then
                str:='DD HH24:MI:SS.MS';
        end if;

        if starttime='HOUR' and endtime='HOUR' then
                str:='HH24';
        end if;
        if starttime='HOUR' and endtime='MINUTE' then
                str:='HH24:MI';
        end if;
        if starttime='HOUR' and endtime='SECOND' then
                str:='HH24:MI:SS';
        end if;
        if starttime='HOUR' and ( endtime='FRACTION' OR endtime='FRACTION(1)' OR endtime='FRACTION(2)' OR endtime='FRACTION(3)' OR endtime='FRACTION(4)' OR endtime='FRACTION(5)' ) then
                str:='HH24:MI:SS.MS';
        end if;

        if starttime='MINUTE' and endtime='MINUTE' then
                str:='MI';
        end if;
        if starttime='MINUTE' and endtime='SECOND' then
                str:='MI:SS';
        end if;
        if starttime='MINUTE' and ( endtime='FRACTION' OR endtime='FRACTION(1)' OR endtime='FRACTION(2)' OR endtime='FRACTION(3)' OR endtime='FRACTION(4)' OR endtime='FRACTION(5)' ) then
                str:='MI:SS.MS';
        end if;

        if starttime='SECOND' and endtime='SECOND' then
                str:='SS';
        end if;
        if starttime='SECOND' and ( endtime='FRACTION' OR endtime='FRACTION(1)' OR endtime='FRACTION(2)' OR endtime='FRACTION(3)' OR endtime='FRACTION(4)' OR endtime='FRACTION(5)' ) then
                str:='SS.MS';
        end if;

return str;
 END;
 $$

LANGUAGE plpgsql;



CREATE OR REPLACE FUNCTION iv_extend (iv text, starttime text, i integer, endtime text) RETURNS text AS $$
 BEGIN
        return iv;
 END;
 $$

LANGUAGE plpgsql;



CREATE OR REPLACE FUNCTION char_to_iv_extended (iv text, starttime text, endtime text) RETURNS text AS $$
 BEGIN
        return iv;
 END;
 $$

LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION dt_string_to_int (starttime text) RETURNS integer AS $$
BEGIN
        if starttime='YEAR'     THEN return 1; end if;
        if starttime='MONTH'    THEN return 2; end if;
        if starttime='DAY'      THEN return 3; end if;
        if starttime='HOUR'     THEN return 4; end if;
        if starttime='MINUTE'   THEN return 5; end if;
        if starttime='SECOND'   THEN return 6; end if;

        if starttime='FRACTION(1)'      THEN return 7; end if;
        if starttime='FRACTION'         THEN return 8; end if;
        if starttime='FRACTION(2)'      THEN return 8; end if;
        if starttime='FRACTION(3)'      THEN return 9; end if;
        if starttime='FRACTION(4)'      THEN return 10; end if;
        if starttime='FRACTION(5)'      THEN return 11; end if;
 END;
 $$
LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION matches_to_regexp (str text,esc text) RETURNS text AS $$
declare
        lv_cnt integer;
        lv_rval text;
        lv_c char;
 BEGIN
        lv_cnt:=0;
        lv_rval:='^';

-- We should probably be looking at the esc too - but we'll leave that for now...
        for lv_cnt in 1..length(str) loop
                lv_c:=substr(str,lv_cnt,1);
                if lv_c='?' then
                        lv_rval:=lv_rval||'.';
                else
                        if lv_c='*' then
                                lv_rval:=lv_rval||'.*';
                        else
                                if lv_c='.' then
                                        lv_rval:=lv_rval||'.';
                                else
                                        lv_rval:=lv_rval||lv_c;
                                end if;
                        end if;
                end if;

        end loop;

        return lv_rval;

 END;
 $$
LANGUAGE plpgsql;



create view syscolumns as 
select attrelid as tabid,
       attname as colname,
       attnum as colno,
       atttypid as coltype,
       attlen as collength
from pg_attribute;

create view systables as 
select oid as tabid,
       0 as nrows,
      'T'::char(1) as tabtype,
      relnatts as ncols,
      relname as tabname
from pg_class where relhasoids='t' ;

create view sysindexes as 
select oid as tabid,
       0 as nrows,
      'I'::char(1) as idxtype,
      relnatts as ncols,
      relname as idxname
from pg_class where relhasoids!='t' ;

create view sysusers as
select usename as username,
       'D'::char(1) as usertype,
       9::smallint as priority,
       passwd as password
from pg_user;



CREATE FUNCTION pg_catalog.text(integer) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(int4out($1));';
CREATE CAST (integer AS text) WITH FUNCTION pg_catalog.text(integer) AS IMPLICIT;
CREATE FUNCTION pg_catalog.text(smallint) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(int2out($1));';
CREATE CAST (smallint AS text) WITH FUNCTION pg_catalog.text(smallint) AS IMPLICIT;
CREATE FUNCTION pg_catalog.text(oid) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(oidout($1));';
CREATE CAST (oid AS text) WITH FUNCTION pg_catalog.text(oid) AS IMPLICIT;
CREATE FUNCTION pg_catalog.text(date) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(date_out($1));';
CREATE CAST (date AS text) WITH FUNCTION pg_catalog.text(date) AS IMPLICIT;
CREATE FUNCTION pg_catalog.text(double precision) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(float8out($1));';
CREATE CAST (double precision AS text) WITH FUNCTION pg_catalog.text(double precision) AS IMPLICIT;
CREATE FUNCTION pg_catalog.text(real) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(float4out($1));';
CREATE CAST (real AS text) WITH FUNCTION pg_catalog.text(real) AS IMPLICIT;
CREATE FUNCTION pg_catalog.text(time WITH time zone) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(timetz_out($1));';
CREATE CAST (time WITH time zone AS text) WITH FUNCTION pg_catalog.text(time WITH time zone) AS IMPLICIT;
CREATE FUNCTION pg_catalog.text(time without time zone) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(time_out($1));';
CREATE CAST (time without time zone AS text) WITH FUNCTION pg_catalog.text(time without time zone) AS IMPLICIT;
CREATE FUNCTION pg_catalog.text(timestamp WITH time zone) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(timestamptz_out($1));';
CREATE CAST (timestamp WITH time zone AS text) WITH FUNCTION pg_catalog.text(timestamp WITH time zone) AS IMPLICIT;
CREATE FUNCTION pg_catalog.text(interval) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(interval_out($1));';
CREATE CAST (interval AS text) WITH FUNCTION pg_catalog.text(interval) AS IMPLICIT;
CREATE FUNCTION pg_catalog.text(bigint) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(int8out($1));';
CREATE CAST (bigint AS text) WITH FUNCTION pg_catalog.text(bigint) AS IMPLICIT;
CREATE FUNCTION pg_catalog.text(numeric) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(numeric_out($1));';
CREATE CAST (numeric AS text) WITH FUNCTION pg_catalog.text(numeric) AS IMPLICIT;
CREATE FUNCTION pg_catalog.text(timestamp without time zone) RETURNS text STRICT IMMUTABLE LANGUAGE SQL AS 'SELECT textin(timestamp_out($1));';
CREATE CAST (timestamp without time zone AS text) WITH FUNCTION pg_catalog.text(timestamp without time zone) AS IMPLICIT;
 

