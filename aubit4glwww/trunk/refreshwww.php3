<script language="php">

$WWW="/home/groups/a/au/aubit4gl/htdocs";

$execline = "sh $WWW/refreshwww.sh -anon -upd";
#$execline = "ls";

		$retvar = array("first line");
		$string = exec($execline,$retvar, $return_status);

        if ( $return_status) { # zero=false on success , != 127
			echo "<BR>Error refreshing Aubit 4gl WWW site from CVS, status = $return_status<BR>";
        } else {
			echo "<BR>Success, status = $return_status<BR>";
			echo "Aubit 4gl WWW site refresshed from CVS <BR>\n\n";
		}
			echo "<BR> Last line=".$string."<BR>";


			echo "----command output----:<br>";
			while (list($key, $val) = each($retvar)) {
			   echo "$key => $val<br>";
	        }
	        echo "----end array-----<br><BR>";
			flush();

	echo "<BR><center><a href='http://aubit4gl.sourceforge.net'>Click here to go to Aubit compiler web site home page</a> ";

</script>
