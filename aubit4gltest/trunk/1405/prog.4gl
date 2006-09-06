database test1

function setup()
  whenever error continue
  begin work
  drop table test
  commit work
  whenever error stop

  begin work

  create temp table test
  (
     p1 int unique
  )

  insert into test values (1)

  commit work

end function






main
  define SqlStr char(100)
  define cnt smallint

  call setup()
  let SqlStr = "insert into test values (1)"
  let cnt = 0
  WHENEVER ERROR CONTINUE

  PREPARE instr FROM SqlStr
  LABEL rep:
  EXECUTE instr
  IF status<0 THEN
    Display "status=",status
    let cnt = cnt + 1
    if cnt <= 10 then
      GOTO rep
    end if
  else
	if cnt>1 then
		display "Should have hit a non-unique error"
		exit program 1
	end if
  END IF
  WHENEVER ERROR STOP
  if cnt<=10 then
	exit program 1
end if
end main
