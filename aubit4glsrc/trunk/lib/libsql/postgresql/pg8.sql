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


