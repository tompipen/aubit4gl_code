
code
#include "memcache.h"
endcode


################################################################################
function mc_new()
define lv_mc integer
code
lv_mc=mc_new();
endcode
return lv_mc
end function


################################################################################
function mc_server_add(lv_mc,lv_host,lv_port)
define lv_mc integer
define lv_host char(20)
define lv_port char(20)
define lv_rcode integer
code
A4GL_trim(lv_host);
A4GL_trim(lv_port);
lv_rcode=mc_server_add(lv_mc,lv_host,lv_port);
endcode
display "lv_rcode=",lv_rcode
return lv_rcode
end function




################################################################################
function mc_server_add4(lv_mc,lv_host)
define lv_mc integer
define lv_host char(40)
define lv_rcode integer
code
A4GL_trim(lv_host);
lv_rcode=mc_server_add4(lv_mc,lv_host);
endcode
return lv_rcode
end function


################################################################################
function mc_add(lv_mc, lv_key, lv_val, lv_bytes) 
define lv_mc integer
define lv_key char(255)
define lv_val integer
define lv_bytes integer
code
A4GL_trim(lv_key);
printf("KEY=%s lv_val=%p bytes=%d\n",lv_key,lv_val,lv_bytes);
mc_add(lv_mc,lv_key,strlen(lv_key),lv_val,lv_bytes,0,0);
endcode
end function

################################################################################
function mc_add_str(lv_mc, lv_key, lv_val) 
define lv_mc integer
define lv_key char(255)
define lv_val char(255)
code
A4GL_trim(lv_key);
A4GL_trim(lv_val);
  mc_add(lv_mc,  lv_key, strlen(lv_key), lv_val,strlen(lv_val),0,0);
  //mc_add(lv_mc,lv_key  , strlen(lv_key) , "test",strlen("test"),0,0);
endcode
end function



################################################################################
function mc_replace(lv_mc, lv_key,  lv_val, lv_bytes)
define lv_key char(255)
define lv_mc integer
define lv_ok integer
define lv_val,lv_bytes integer
code
A4GL_trim(lv_key);
if (mc_replace(lv_mc,lv_key,strlen(lv_key),lv_val,lv_bytes,0,0)) {
	lv_ok=1;
} else {
	lv_ok=0;
}
endcode
return lv_ok
end function


################################################################################
function mc_replace_str(lv_mc, lv_key,  lv_val)
define lv_key char(255)
define lv_mc integer
define lv_ok integer
define lv_val char(255)
code
A4GL_trim(lv_key);
A4GL_trim(lv_val);

if (mc_replace(lv_mc,lv_key,strlen(lv_key),lv_val,strlen(lv_val)+1,0,0)) {
	lv_ok=1;
} else {
	lv_ok=0;
}

endcode
return lv_ok
end function



################################################################################
function mc_req_new() 
define lv_req integer
code
lv_req=mc_req_new();
endcode
return lv_req
end function



################################################################################
function mc_req_add(lv_req, lv_key)
define lv_req integer
define lv_key char(255)
define lv_res integer
code
	A4GL_trim(lv_key);
 	lv_res=mc_req_add(lv_req, lv_key, strlen(lv_key));
endcode
return lv_res
end function


################################################################################
function mc_get(lv_mc, lv_req)
define lv_mc integer
define lv_req integer
code
	mc_get(lv_mc,lv_req);
endcode
end function



function mc_aget_str(lv_mc,lv_key)
define lv_mc integer
define lv_key char(255)
define lv_ptr integer
define lv_val char(255)
code
A4GL_trim(lv_key);
lv_ptr=mc_aget(lv_mc,lv_key,strlen(lv_key));
if (lv_ptr) strcpy(lv_val,lv_ptr);
endcode
return lv_val
end function



function mc_aget_rec(lv_mc,lv_key,lv_optr,lv_size)
define lv_mc integer
define lv_key char(255)
define lv_ptr integer
define lv_optr,lv_size integer

code
A4GL_trim(lv_key);
lv_ptr=mc_aget(lv_mc,lv_key,strlen(lv_key));
if (lv_ptr) {
	memcpy(lv_optr,lv_ptr,lv_size);
}
free(lv_ptr);
endcode
end function


################################################################################
function mc_set(lv_mc, lv_key, lv_val, lv_bytes)
define lv_key char(255)
define lv_val,lv_bytes integer
define lv_mc integer
code
A4GL_trim(lv_key);
mc_set(lv_mc,lv_key,strlen(lv_key),lv_val,lv_bytes,0,0);
endcode
end function

################################################################################
function mc_set_str(lv_mc, lv_key, lv_val)
define lv_key char(255)
define lv_val char(255)
define lv_mc integer
code
A4GL_trim(lv_key);
A4GL_trim(lv_val);
mc_set(lv_mc,lv_key,strlen(lv_key),lv_val,strlen(lv_val)+1,0,0);
endcode
end function


################################################################################
function mc_res_free_on_delete(lv_res, lv_yesno) 
define lv_yesno integer
define lv_res integer
code
mc_res_free_on_delete(lv_res,lv_yesno);
endcode

end function

################################################################################
function mc_res_free(lv_req, lv_res)
define lv_req integer
define lv_res integer
code
mc_res_free(lv_req,lv_res);
endcode

end function



################################################################################
function mc_stats(lv_mc)
define lv_mc integer
define lv_rec record
  pid integer,
  version char (30),
  curr_items integer,
  total_items integer,
  bytes integer,
  curr_connections integer,
  total_connections integer,
  connection_structures integer,
  cmd_get integer,
  cmd_refresh integer,
  cmd_set integer,
  get_hits integer,
  get_misses integer,
  refresh_hits integer,
  refresh_misses integer,
  bytes_read integer,
  bytes_written integer,
  limit_maxbytes integer

end record
code
{
struct memcache_server_stats *s;
s=mc_stats(lv_mc);
if (s) {
	int d;
	d=s->pid;
	lv_rec.pid=s->pid;
  	strcpy(lv_rec.version ,s->version);
  	lv_rec.curr_items =s->curr_items ;
  	lv_rec.total_items =s->total_items ;
  	lv_rec.bytes =s->bytes ;
  	lv_rec.curr_connections =s->curr_connections ;
  	lv_rec.total_connections =s->total_connections ;
  	lv_rec.connection_structures =s->connection_structures ;
  	lv_rec.cmd_get =s->cmd_get ;
  	lv_rec.cmd_refresh =s->cmd_refresh ;
  	lv_rec.cmd_set =s->cmd_set ;
  	lv_rec.get_hits =s->get_hits ;
  	lv_rec.get_misses =s->get_misses ;
  	lv_rec.refresh_hits =s->refresh_hits ;
  	lv_rec.refresh_misses =s->refresh_misses ;
  	lv_rec.bytes_read =s->bytes_read ;
  	lv_rec.bytes_written =s->bytes_written ;
  	lv_rec.limit_maxbytes =s->limit_maxbytes ;
	mc_server_stats_free(s);
}
}
endcode
return lv_rec.*

end function

################################################################################
function mc_delete(lv_mc, lv_key)
define lv_mc integer
define lv_key char(255)
code
A4GL_trim(lv_key);
mc_delete(lv_mc,lv_key,strlen(lv_key),0);
endcode
end function

################################################################################
function mc_incr(lv_mc, lv_key,  lv_ival)
define lv_key char(255)
define lv_mc integer
define lv_ival integer
code
A4GL_trim(lv_key);
mc_incr(lv_mc,lv_key,strlen(lv_key),lv_ival);
endcode
end function


################################################################################
function mc_decr(lv_mc, lv_key, lv_ival)
define lv_key char(255)
define lv_mc integer
define lv_ival integer
code
A4GL_trim(lv_key);
mc_decr(lv_mc,lv_key,strlen(lv_key),lv_ival);
endcode
end function

################################################################################
function mc_free(lv_mc)
define lv_mc integer
code
mc_free(lv_mc);
endcode
end function

function test1(lv_mc) 
define lv_mc integer
code
  mc_add(lv_mc, "foo", strlen("foo"), "test", strlen("test"), 0, 0);
endcode
end function
