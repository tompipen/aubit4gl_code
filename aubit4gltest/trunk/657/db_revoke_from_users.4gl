
DATABASE test1

MAIN

{ to make this test executable, make sure this users exist first }

  REVOKE CONNECT FROM informix
  GRANT CONNECT TO informix

  REVOKE CONNECT FROM informix, root
  GRANT CONNECT TO informix, root

  REVOKE RESOURCE FROM informix
  GRANT RESOURCE TO informix

  REVOKE RESOURCE FROM informix, root
  GRANT RESOURCE TO informix, root

  REVOKE DBA FROM informix
  GRANT DBA TO informix

  REVOKE DBA FROM informix, root
  GRANT DBA TO informix, root
END MAIN
