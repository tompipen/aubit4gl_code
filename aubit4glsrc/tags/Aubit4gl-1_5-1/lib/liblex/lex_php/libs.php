<?

class sqlDriver {
	var $set_conn_id = 0;
	var $set_dbname = "test1";
	var $set_uname = "aubit4gl";
	var $set_passwd="";
	var $set_serial = 0;

	function sqlDriver($s) {
		$this->set_dbname=$s;
		$this->set_env();
	}
	
	function set_env(){
    		if ($this->set_conn_id == 0){
        		putenv("INFORMIXDIR=/home/informix/v7.30");
        		putenv("INFORMIXSERVER=mike_2");
        		putenv("DBDATE=DMY4");
			if ($this->set_uname=="NoUserName")  { die("No username set..\n"); }
			if ($this->set_passwd=="Nopassword") { die("No password set..\n"); }
			if ($this->set_passwd!="NoPassword") {
        			$this->set_conn_id = ifx_connect($this->set_dbname, $this->set_uname, $this->set_passwd);
			} else {
				if ($this->set_uname!="NoUserName") {
        				$this->set_conn_id = ifx_connect($this->set_dbname, $this->set_uname);
				} else {
        				$this->set_conn_id = ifx_connect($this->set_dbname);
				}
			}
        		if ($this->set_conn_id) {
		
        		$rid = ifx_prepare("set lock mode to wait", $this->set_conn_id);
        		ifx_do ($rid);
		
        		$rid = ifx_prepare("set isolation to dirty read", $this->set_conn_id);
        		ifx_do ($rid);
        		}
		
        		if ($this->set_conn_id == 0) return 0;
    		}
    		return 1;
	}


	function transaction($s) {

	}

	function prepare($s) {
		if (!$this->set_env()) {
			return 0;
		}

		$rid = ifx_prepare($s, $this->set_conn_id);
		return $rid;
	}

	function fetchAll($s) {
		global $sqlcode;
		$sqlcode=0;
		if (!$this->set_env()) {
			$sqlcode=-1005;
			return 0;
		}

		$rid = ifx_prepare($s, $this->set_conn_id);

		if ($rid) {
			if (!ifx_do($rid)) {
				$sqlcode=-1006;
				return 0;
			}
			// if we get to here - we're actually looking pretty good!
    			$row = ifx_fetch_row($rid) ;
    			$rowcnt = 0;
    			while (is_array($row)){
        			$arr[$rowcnt] = $row = array_values ($row);
        			$rowcnt++;
        			$row = ifx_fetch_row($rid);
    			}
			ifx_free_result($rid);
			return $arr;
		} else {
			$sqlcode=-1007;
			return 0;
		}
	
	}
}






class FGLEmulPrepare {
	var $qry;
	var $prepared;
	var $params;
	var $params_c;
	var $rid;
	

	function PrepareFromDynamic($s) {
		$this->prepared=0;
		$this->qry=$s;
		unset($this->params);
	}

	function Parameter($n,$v) {
		$this->SetParam($n,$v,"P");
	}

	function SetParam($n,$v,$cat) {
		if ($cat=="P") {
			if (!isset($this->params)) {
				$this->params=array();
			}
			$this->params[$n]=$v;
		}
		if ($cat=="D") {
			if (!isset($params_c)) {
				$params_c=array();
			}
			$this->params_c[$n]=$v;
		}
	}

	function ExecuteSqlWithResults($n) {
		global $db;
		$p=array();

		if (is_array($this->params)) {
			$p=$this->params;
		} else {
			if (is_array($this->params_c)) {
				$p=$this->params_c;
			}
		}

		if (count($p)!=$n) {
			global $sqlcode;
			$sqlcode=-254;
			return 100;
		}


		$qry=$this->GetQuery();
		$arr=$db->fetchAll($qry);

		if (is_array($arr)) {
			return $arr[0];
		}
		
		return 100;
		
	}

	function GetQuery() {
		if (is_array($this->params)) {
			$buff=array();
			$str="";
			$b=0;
			for ($a=0;$a<strlen($this->qry);$a++) {
				if (substr($this->qry,$a,1)=="?") {
					$str.="'".$this->params[$b++]."'";
				} else {
					$str.=substr($this->qry,$a,1);
				}
			}
			return $str;

		}
		return $this->qry;
	}
}



class FGLCursor {
	var $arr;
	var $stmt;

	function FGLCursor() {
	}

	function CursorDeclare($u,$p) {
		if ($u) {
			die("Not implemented");
		}
		unset($this->arr);
		$this->stmt=$p;
		$this->pos=0;
	}


	function OpenCursor() {
		global $db;
		global $sqlcode;
		$this->pos=0;
		$qry=$this->stmt->GetQuery();
		$this->arr=$db->fetchAll($qry);
	}

	function ResetCursor() {
		$this->pos=0;
	}

	function MoveFirst() {
		$this->pos=0;
		if (is_array($this->arr) ) {
			if (count($this->arr)) {
				return 1;
			}
		}
		return 0;
	}

	function MoveLast() {
		if (is_array($this->arr)) {
			$this->pos=count($this->arr)-1;
			return 1;
		}
		return 0;
	}

	function MoveNext() {
		if (is_array($this->arr)) {
			$last=count($this->arr)-1;
			if ($this->pos<=$last) {
				$this->pos=$this->pos=$this->pos+1;
				return 1;
			}
		}
		return 0;
	}

	function GetCurrent() {

		if (is_array($this->arr)) {
			$last=count($this->arr)-1;
			if ($this->pos<=$last) {
				$sqlcode=0;
				return $this->arr[$this->pos];
			}
			$sqlcode=100;
			return 100;
		}
		$sqlcode=-1;
		return -1004;
	}

	function CloseCursor() {
		if (is_array($this->arr)) {
			unset($this->arr);
		}
	}

}

function substring($str,$start,$end) {
	return substr($str,$start,$end-$start+1);
}


function DBConnect($s) {
	global $db;
	$db=new sqlDriver($s);
}
?>
