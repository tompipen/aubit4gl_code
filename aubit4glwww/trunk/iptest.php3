<HTML>
<HEAD>

<TITLE>IP address test</TITLE>
</HEAD>
<BODY BGCOLOR="#000000" text="#FFFFFF">

<?php
// <script language="php">

    $ip = $REMOTE_ADDR;
	$serverip1 = gethostbyname ("www.falout.com");
	$serverip2 = gethostbyname ("falout.com");
 $serverip3 = gethostbyname ("falout.homeip.net");
 $serverip4 = gethostbyname ("armada.dynip.com");
 $serverip5 = gethostbyname ("armada.falout.com");
 $serverip6 = gethostbyname ("aptiva.falout.com");

if ( "$ip" != "$serverip2" ||  "$ip" != "$serverip1") {


	echo "You are not connected from falout.com domain. <BR>\n";
	echo "<BR>\n";

	if ( "$ip" != "$serverip1" ) {
	    echo "ERROR www.falout.com<BR>\n";

	} else {

	    echo "OK www.falout.com<BR>\n";
	}

echo "<BR>";

	if ( "$ip" != "$serverip2" ) {
	    echo "ERROR falout.com<BR>\n";

	} else {

	    echo "OK falout.com<BR>\n";
	}

	echo "<BR>\n";
	echo "Your IP=".$ip."<BR>\n";
	echo "www.falout.com IP = ".$serverip1."<BR>";
	echo "falout.com IP = ".$serverip2."<BR>\n";


} else {

	echo "OK - ".$ip."<BR>";
}


echo " <BR> falout.homeip.net = ".$serverip3."<BR>";
echo " <BR> armada.dynip.com = ".$serverip4."<BR>";
echo " <BR> armada.falout.com = ".$serverip5."<BR>";
echo " <BR> aptiva.falout.com = ".$serverip6."<BR>";
?>

</BODY>
</HTML>

