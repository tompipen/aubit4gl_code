create table web_application 
  (
    application char(18),
    connmode char(1),
    pxy_programname char(64),
    pxy_server char(32),
    pxy_port char(10),
    pxy_username char(18),
    pxy_password char(18),
    auth_cmdline char(256)
  );

create table web_user 
  (
    username char(18),
    password char(48)
  );

create table web_perms 
  (
    url_id char(18),
    application char(18),
    username char(18)
  );

create table web_serverurl 
  (
    url_id char(18),
    relativeurl char(64),
    authmode char(1),
    htaccessfile char(64),
    htpasswdfile char(64),
    xmlfile char(64)
  );
