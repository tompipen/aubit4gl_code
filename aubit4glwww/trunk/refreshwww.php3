<script language="php">

$WWW="/home/groups/a/au/aubit4gl/htdocs";

#$execline = "export HOME=/home/users/a/af/afalout; export WWW=/home/groups/a/au/aubit4gl/htdocs; sh $WWW/refreshwww.sh -anon";
$execline = "sh $WWW/refreshwww.sh -anon";
#$execline = "ls";

		$retvar = array("first line");
		$string = exec($execline,$retvar, $return_status);

        #if ( $return_status) { # zero=false on success , != 127
	        echo "<BR> Last line=".$string."<BR>";
			echo "<BR>Error refreshing Aubit 4gl WWW site from CVS, status = $return_status<BR>";
			echo "----command output----:<br>";
			while (list($key, $val) = each($retvar)) {
			   echo "$key => $val<br>";
	        }
	        echo "----end array-----<br>";
			flush();
        #    die;
		#}


	echo "Aubit 4gl WWW site refresshed from CVS \n\n";

	echo "<center><a href='http://aubit4gl.sourceforge.net'>Click here to go to Aubit compiler web site home page</a> ";

</script>
