#!/usr/local/bin/perl 
#
# This is the 'USING' string module
# it must be copied somewhere in the perl include path
#
# (c) 2002 Aubit Computing Ltd
#
# NOTE : This code is not covered by the GPL and is not part of the core
#        Aubit4gl system or maintained by the Aubit4GL team.
#
#        If you wish to use this code the following condition applies :
#
#             You must NOT use this code in any commercial application
#             without prior consent of Aubit Computing Ltd
#
# For full details of the licensing terms - please contact Aubit Computing Ltd
#
package using;

#-- Sub using - number, format
sub using
{
  my ($num, $fmt) = @_;
#                  NA

   $action{'*'}="**##**##";
   $action{'$'}='$$##$$##';

   $action{'('}=" (## (##"; 

   $action{')'}=" ) ) ) )";
   $action{','}="!!,,!!,,";


   $action{'<'}="<<##<<##";

   $action{'-'}=" -## -##";
   $action{'+'}="+-##+-##";

   $action{'&'}="00##00##";
   $action{'#'}="  ##  ##";


   $reset{'+'}='#';
   $reset{'-'}='#';
   $reset{'('}=' ';
   $reset{'$'}='#';


   $action{' '}="        ";

  if ($num < 0) { $isneg = 1; $num = 0.0 - $num; }

# Split the format into the integer and decimal parts
  @arr_fmt = split /\./ , $fmt; 
  if (!defined($arr_fmt[1])) { $arr_fmt[1]="";}



# Sort out any rounding problems...
# Eg 99.9 when displayed as #### should be ' 100' not '  99'
#
  $sig=0;
  $add = 0.5;
  for ($cnt1 = 0; $cnt1 < length ($arr_fmt[1]); $cnt1++) {
		$ch=substr($arr_fmt[1],$cnt1,1);
		if ($ch eq '#' || $ch eq '$' || $ch eq '&' || $ch eq '-' || $ch eq '+' ) {
			$add = $add / 10.0;
			$sig++;

			if ($ch ne '#') {
				substr($arr_fmt[1],$cnt1,1)="#";
			}
			next;
		}

		if ($ch eq ')') {
			if ($isneg) {
				substr($arr_fmt[1],$cnt1,1)=')';
			} else {
				substr($arr_fmt[1],$cnt1,1)=' ';
			}
		}
  }
  $num += $add;


# Split it into to halves
  @arr_num = split /\./ , $num; 
 
 if (!defined($arr_num[1])) { $arr_num[1]="";}
  $int_part=sprintf("%d",$num);

  if ($sig) {
  	$total_digits=2+$sig;
  	$dofmt="%${total_digits}.${sig}f";
	$n=$num-$int_part-$add;
	if ($n<0) {
		$n=0;
	}

 	$dig_part=sprintf($dofmt,$n);
	$dig_part=substr($dig_part,2,length($dig_part)-2);

  }



  #//if ($num>=$maxval) {
	#//$result="*" x length($fmt);
	#//return $result;
  #//}



  $cval=1;

#print "Preformat = $arr_fmt[0]\n";

$format=$arr_fmt[0];

  $currency=0;
  for ($a=length($arr_fmt[0])-1;$a>=0;$a--) {
	$ch=substr($format,$a,1);
	if ($ch eq '$') {
		$currency=1;
	} 

	if ($ch ne '$' && $currency) {
		$ch='$';
		$currency=0;
	}
	
	while (defined($action{$ch})) {
		
		#print "Doing $ch\n";
		$ch=substr($format,$a,1);



		$ta=($num>($cval*10));
		$tb=($num>$cval);
		$tc=$isneg;

		if (!($ta)) {$ta=0;}
		if (!($tb)) {$tb=0;}
		if (!($tc)) {$tc=0;}
		#print "ta=$ta tb=$tb tc=$tc num=$num cval=$cval\n";

		$v=$ta*4+$tb*2+$tc*1;

		if ($v<0) {
			#print "Got v<0 for $ta,$tb,$tc\n";
			exit;
		}

		#print "v=$v action=".$action{$ch}."\n";
	
		$ch=substr($action{$ch},$v,1);


		#print "Gives char as $ch\n";




		if ($ch eq '!') {
				#print "Setting to ".substr($arr_fmt[0],$a-1,1)."\n";
				substr($format,$a,1)=substr($arr_fmt[0],$a-1,1);
				$ch=substr($format,$a,1);
				next;
		} 

			$lch=substr($format,$a,1);

			#print "check lch ne ch '$lch' '$ch'\n";
			if ($lch ne $ch) {
					#print "lch ne ch $lch $ch ($format)\n";
					substr($format,$a,1)=$ch;
					#print "Format =$format a=$a\n";
				
					if ($ch eq '#' || $ch eq '<' ) {
						#print "Try again\n";
						next;
					}	
			}
			last;
		
	}

	if (defined($reset{$ch})) { $action{$ch}=$action{$reset{$ch}}; }

	if ($ch eq '#') { # // || $ch eq '(' ) {
			#print "Increment cval\n";
			$cval*=10;
	}
        #print "$a -> $arr_fmt[0]\n";
  }

#print "Format=".$format."\n";


$arr_fmt[0]=$format;

$s="";
for ($a=0;$a<length($arr_fmt[0]);$a++) {
	$ch=substr($arr_fmt[0],$a,1);
	if ($ch eq '<') {next;}
	$s.=substr($arr_fmt[0],$a,1);
}
$result_i="";


	$arr_fmt[0]=$s;

        $b=0;
	for ($a=0;$a<length($arr_fmt[0]);$a++) {
		
		$ch=substr($arr_fmt[0],$a,1);
		if ($ch eq'#') {
			substr($result_i,$a,1)=substr($int_part,$b++,1);
		} else {
			substr($result_i,$a,1)=$ch;
		}
	}


        $b=0;
        my $result_d = " " x length($arr_fmt[1]);
	for ($a=0;$a<length($arr_fmt[1]);$a++) {
		$ch=substr($arr_fmt[1],$a,1);

		if ($ch eq '#') {
			substr($result_d,$a,1)=substr($dig_part,$b++,1);
		} else {
			substr($result_d,$a,1)=$ch;
		}
	}

  if ($sig) {
		$result=$result_i.".".$result_d;
  } else {
		$result=$result_i;
  }

return $result;
}

1;
