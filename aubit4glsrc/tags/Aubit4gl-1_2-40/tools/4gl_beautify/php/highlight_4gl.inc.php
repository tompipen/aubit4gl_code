<?

/*

> I'm looking for a 4GL code formatters - beautifiers - indenters.

Hmm.  Its not exactly what you're looking for, but in case you're
interested I have a web beautifier written in PHP (attached).  It could
easily do more in the way of formatting, if you're wanting a clean display
rather than file changing.  You will need to change the values in
$global_scope to match your site.  Its a quick-n-dirty one, but it works...
and it doesn't need either an elaborate parser or a list of valid library
functions to encode correctly.  Keyword lists are probably subpar, grabbed
from somewhere, but even so its worth a look.

-Richard


*/


// Current issues:
//
//  codes the field of 'record[key].field' as a function

function format_4gl($fp = "")
{
	set_time_limit(300);

	$lastColor = "";

	// Assumes that you've already specified a color in the last FONT tag.
	// This is not a general purpose function.

	function setColor($color)
	{
		global $lastColor;

		if ($lastColor == $color)
			return;

		echo "</FONT><FONT COLOR=$color>";
		$lastColor = $color;
	}

	// These need to be replaced by numerical definitions ASAP

	$keyword_color  = "\"#000000\"";       // black
	$number_color   = "\"#006600\"";       // green
	$quote_color    = "\"#006600\"";       // green
	$comment_color  = "\"#AAAAAA\"";       // gray
	$variable_color = "\"darkblue\"";      // blue
	$token_color    = "\"#000000\"";       // black
	$database_color = "\"darkred\"";       // red
	$cursor_color   = "\"darkpink\"";      // pink
	$prepared_color = "\"darkpink\"";      // pink
	$function_color = "\"purple\"";        // purple
	$screen_color   = "\"darkorange\"";    // orange
	$error_color    = "\"red\"";           // red
	$goto_color     = "\"aqua\"";          // aqua

	if ($fp == "")
		return;

	if (!$fp)
		return;

	$in_block_comment = false;

	$seen_real_line = false;

	// Populate arrays for keyword matching

	$sqlstart = array(
		"alter" => true,
		"create" => true,
		"declare" => true,
		"database" => true,
		"declare" => true,
		"delete" => true,
		"grant" => true,
		"like" => true,
		"on" => true,
		"prepare" => true,
		"select" => true,
		"update" => true
	);

	$sqlwords = array(
		"integer" => true,
		"interval" => true,
		"date" => true,
		"datetime" => true,
		"char" => true,
		"character" => true,
		"count" => true,
		"text" => true,
		"varchar" => true,
		"absolute" => true,
		"and" => true,
		"as" => true,
		"avg" => true,
		"by" => true,
		"between" => true,
		"count" => true,
		"cursor" => true,
		"for" => true,
		"from" => true,
		"group" => true,
		"having" => true,
		"insert" => true,
		"into" => true,
		"null" => true,
		"or" => true,
		"order" => true,
		"outer" => true,
		"set" => true,
		"union" => true,
		"using" => true,
		"where" => true
	);

	// These are all keywords except those only found in SQL statements

	$keywords = array(
		"abort" => true,
		"absolute" => true,
		"accept" => true,
		"access" => true,
		"add" => true,
		"after" => true,
		"all" => true,
		"allowing" => true,
		"and" => true,
		"ansi" => true,
		"any" => true,
		"array" => true,
		"as" => true,
		"asc" => true,
		"ascending" => true,
		"ascii" => true,
		"at" => true,
		"attribute" => true,
		"attributes" => true,
		"audit" => true,
		"auto" => true,
		"autonext" => true,
		"average" => true,
		"avg" => true,
		"backround" => true,
		"before" => true,
		"begin" => true,
		"beginning" => true,
		"bell" => true,
		"black" => true,
		"blanks" => true,
		"blink" => true,
		"blob" => true,
		"blue" => true,
		"bold" => true,
		"border" => true,
		"bottom" => true,
		"break" => true,
		"buffered" => true,
		"by" => true,
		"byte" => true,
		"call" => true,
		"case" => true,
		"check" => true,
		"clear" => true,
		"clipped" => true,
		"close" => true,
		"cluster" => true,
		"cobol" => true,
		"col" => true,
		"color" => true,
		"colors" => true,
		"column" => true,
		"columns" => true,
		"command" => true,
		"comment" => true,
		"comments" => true,
		"commit" => true,
		"committed" => true,
		"composites" => true,
		"compress" => true,
		"connect" => true,
		"constant" => true,
		"constrained" => true,
		"constraint" => true,
		"construct" => true,
		"continue" => true,
		"control" => true,
		"convert" => true,
		"current" => true,
		"cursor" => true,
		"cyan" => true,
		"database" => true,
		"date_type" => true,
		"day" => true,
		"dba" => true,
		"debug" => true,
		"dec" => true,
		"dec_t" => true,
		"decimal" => true,
		"decimal_type" => true,
		"declare" => true,
		"default" => true,
		"defaults" => true,
		"defer" => true,
		"define" => true,
		"delimiter" => true,
		"delimiters" => true,
		"desc" => true,
		"descending" => true,
		"describe" => true,
		"descriptor" => true,
		"dim" => true,
		"dirty" => true,
		"display" => true,
		"displayonly" => true,
		"distinct" => true,
		"do" => true,
		"dominant" => true,
		"double" => true,
		"down" => true,
		"downshift" => true,
		"drop" => true,
		"dtime" => true,
		"dtime_t" => true,
		"editadd" => true,
		"editupdate" => true,
		"else" => true,
		"end" => true,
		"end-exec" => true,
		"endif" => true,
		"ending" => true,
		"enum" => true,
		"error" => true,
		"escape" => true,
		"every" => true,
		"exclusive" => true,
		"exec" => true,
		"execute" => true,
		"exists" => true,
		"exit" => true,
		"exitnow" => true,
		"exits" => true,
		"explain" => true,
		"extend" => true,
		"extent" => true,
		"extern" => true,
		"external" => true,
		"false" => true,
		"fetch" => true,
		"fgl" => true,
		"field" => true,
		"file" => true,
		"finish" => true,
		"first" => true,
		"fixchar" => true,
		"float" => true,
		"flush" => true,
		"for" => true,
		"foreach" => true,
		"form" => true,
		"format" => true,
		"formonly" => true,
		"fortran" => true,
		"found" => true,
		"fraction" => true,
		"free" => true,
		"from" => true,
		"function" => true,
		"f1" => true,
		"f2" => true,
		"f3" => true,
		"f4" => true,
		"f5" => true,
		"f6" => true,
		"f7" => true,
		"f8" => true,
		"f9" => true,
		"f10" => true,
		"f11" => true,
		"f12" => true,
		"f13" => true,
		"f14" => true,
		"f15" => true,
		"f16" => true,
		"f17" => true,
		"f18" => true,
		"f19" => true,
		"f20" => true,
		"f21" => true,
		"f22" => true,
		"f23" => true,
		"f24" => true,
		"f25" => true,
		"f26" => true,
		"f27" => true,
		"f28" => true,
		"f29" => true,
		"f30" => true,
		"f31" => true,
		"f32" => true,
		"f33" => true,
		"f34" => true,
		"f35" => true,
		"f36" => true,
		"f37" => true,
		"f38" => true,
		"f39" => true,
		"f40" => true,
		"globals" => true,
		"go" => true,
		"goto" => true,
		"grant" => true,
		"green" => true,
		"group" => true,
		"header" => true,
		"headings" => true,
		"help" => true,
		"hide" => true,
		"hold" => true,
		"hour" => true,
		"identified" => true,
		"if" => true,
		"ifdef" => true,
		"ifndef" => true,
		"immediate" => true,
		"in" => true,
		"include" => true,
		"index" => true,
		"indicator" => true,
		"infield" => true,
		"info" => true,
		"initialize" => true,
		"input" => true,
		"instructions" => true,
		"int" => true,
		"int_flag" => true,
		"interrupt" => true,
		"intersect" => true,
		"intrvl_t" => true,
		"inverse" => true,
		"invisible" => true,
		"is" => true,
		"isam" => true,
		"isolation" => true,
		"join" => true,
		"joining" => true,
		"key" => true,
		"label" => true,
		"language" => true,
		"last" => true,
		"left" => true,
		"len" => true,
		"length" => true,
		"let" => true,
		"like" => true,
		"line" => true,
		"lineno" => true,
		"lines" => true,
		"load" => true,
		"loc_t" => true,
		"locate" => true,
		"locator" => true,
		"lock" => true,
		"log" => true,
		"long" => true,
		"long_float" => true,
		"long_integer" => true,
		"lookup" => true,
		"loop" => true,
		"magenta" => true,
		"main" => true,
		"margin" => true,
		"master" => true,
		"matches" => true,
		"max" => true,
		"mdy" => true,
		"memory" => true,
		"menu" => true,
		"message" => true,
		"min" => true,
		"minus" => true,
		"minute" => true,
		"mod" => true,
		"mode" => true,
		"modify" => true,
		"module" => true,
		"money" => true,
		"month" => true,
		"name" => true,
		"natural" => true,
		"need" => true,
		"new" => true,
		"next" => true,
		"nextfield" => true,
		"no" => true,
		"nocr" => true,
		"noentry" => true,
		"normal" => true,
		"not" => true,
		"notfound" => true,
		"noupdate" => true,
		"now" => true,
		"null" => true,
		"numeric" => true,
		"of" => true,
		"off" => true,
		"on" => true,
		"open" => true,
		"option" => true,
		"options" => true,
		"or" => true,
		"order" => true,
		"otherwise" => true,
		"out" => true,
		"outer" => true,
		"output" => true,
		"package" => true,
		"page" => true,
		"pageno" => true,
		"param" => true,
		"pascal" => true,
		"pause" => true,
		"percent" => true,
		"perform" => true,
		"picture" => true,
		"pipe" => true,
		"pli" => true,
		"positive" => true,
		"precision" => true,
		"prepare" => true,
		"previous" => true,
		"print" => true,
		"printer" => true,
		"prior" => true,
		"privilege" => true,
		"privileges" => true,
		"procedure" => true,
		"program" => true,
		"prompt" => true,
		"public" => true,
		"put" => true,
		"query" => true,
		"queryclear" => true,
		"quit" => true,
		"raise" => true,
		"range" => true,
		"read" => true,
		"readonly" => true,
		"real" => true,
		"record" => true,
		"recover" => true,
		"red" => true,
		"register" => true,
		"relative" => true,
		"remove" => true,
		"rename" => true,
		"repair" => true,
		"repeatable" => true,
		"report" => true,
		"required" => true,
		"resource" => true,
		"return" => true,
		"returning" => true,
		"reverse" => true,
		"revoke" => true,
		"rforward" => true,
		"right" => true,
		"rollback" => true,
		"rollforward" => true,
		"row" => true,
		"rowid" => true,
		"rows" => true,
		"run" => true,
		"savepoint" => true,
		"schema" => true,
		"screen" => true,
		"scroll" => true,
		"second" => true,
		"section" => true,
		"serial" => true,
		"serial_type" => true,
		"set" => true,
		"share" => true,
		"shift" => true,
		"short" => true,
		"short_float" => true,
		"short_integer" => true,
		"show" => true,
		"sitename" => true,
		"size" => true,
		"sizeof" => true,
		"skip" => true,
		"sleep" => true,
		"smallfloat" => true,
		"smallint" => true,
		"smfloat" => true,
		"smint" => true,
		"some" => true,
		"space" => true,
		"spaces" => true,
		"sql" => true,
		"sqlca" => true,
		"sqlca.sqlcode" => true,
		"sqlca.sqlerrd" => true,
		"sqlchar_type" => true,
		"sqlcode" => true,
		"sqlda" => true,
		"sqldecimal_type" => true,
		"sqlerr" => true,
		"sqlerror" => true,
		"sqlfloat_type" => true,
		"sqlint_type" => true,
		"sqlmoney_type" => true,
		"sqlsmfloat_type" => true,
		"sqlsmint_type" => true,
		"sqlwarning" => true,
		"stability" => true,
		"start" => true,
		"startlog" => true,
		"static" => true,
		"statistics" => true,
		"status" => true,
		"stdv" => true,
		"step" => true,
		"stop" => true,
		"string" => true,
		"struct" => true,
		"substract" => true,
		"subtype" => true,
		"sum" => true,
		"switch" => true,
		"synonym" => true,
		"systables" => true,
		"table" => true,
		"tables" => true,
		"temp" => true,
		"text" => true,
		"then" => true,
		"through" => true,
		"thru" => true,
		"time" => true,
		"tiny_integer" => true,
		"to" => true,
		"today" => true,
		"top" => true,
		"total" => true,
		"trailer" => true,
		"trailing" => true,
		"true" => true,
		"type" => true,
		"typedef" => true,
		"unconstrained" => true,
		"undef" => true,
		"underline" => true,
		"unique" => true,
		"units" => true,
		"unload" => true,
		"unlock" => true,
		"unsigned" => true,
		"up" => true,
		"upshift" => true,
		"user" => true,
		"validate" => true,
		"values" => true,
		"varchar" => true,
		"variable" => true,
		"vc_t" => true,
		"verify" => true,
		"view" => true,
		"void" => true,
		"wait" => true,
		"waiting" => true,
		"warning" => true,
		"wcolor" => true,
		"weekday" => true,
		"when" => true,
		"whenever" => true,
		"while" => true,
		"white" => true,
		"window" => true,
		"with" => true,
		"without" => true,
		"wordwrap" => true,
		"work" => true,
		"wrap" => true,
		"year" => true,
		"yellow" => true,
		"yes" => true,
		"zerofill" => true
	);

	$global_scope = array(
		"g_navto_tran_id" => true,
		"g_navto_prg_id" => true,
		"g_prms" => true,
		"g_command_code" => true,
		"g_screen_pos" => true,
		"g_chosen" => true,
		"g_direction" => true,
		"g_help_scr_name" => true,
		"g_help_fld_name" => true,
		"g_std_err_chan" => true,
		"g_std_app_chan" => true,
		"g_std_func_chan" => true,
		"g_std_info_chan" => true,
		"g_std_log_chan" => true,
		"g_channel_init" => true,
		"g_channel_enable" => true,
		"g_channel_disable" => true,
		"g_max_channels" => true,
		"g_icomm" => true,
		"g_user" => true,
		"g_class_func" => true,
		"g_ctrl_w" => true,
		"g_aud" => true,
		"g_fpcwc_max" => true,
		"g_alorg_max" => true,
		"g_last_x_coord" => true,
		"g_last_y_coord" => true,
		"g_last_z_coord" => true,
		"g_accum_wgt" => true,
		"g_accum_cub" => true,
		"g_accum_rpt_tim" => true,
		"g_accum_lvl_tim" => true,
		"g_accum_cub_tim" => true,
		"g_accum_wgt_tim" => true,
		"g_accum_dly_tim" => true,
		"g_accum_ftg_tim" => true,
		"g_orig_dcpt_id" => true,
		"g_error_flag" => true,
		"g_prev_othd_id" => true,
		"g_detail_sel_aseld" => true,
		"g_assg_sel_aseld" => true,
		"g_update_current_aseld" => true,
		"g_update_prev_aseld" => true,
		"g_detail_sel_aothd" => true,
		"g_dtl_sel_aothd" => true,
		"g_count_aothd" => true,
		"g_update_aothd" => true,
		"g_update_prev_aothd" => true,
		"g_assg_sel_aothd" => true,
		"g_fpcwc" => true,
		"g_alorg" => true,
		"g_alorg_info" => true,
		"g_fpcwc_info" => true,
		"g_prev_aseld" => true,
		"g_aseld" => true,
		"g_start_pt" => true,
		"g_end_pt" => true,
		"g_seqch" => true,
		"g_albdf" => true,
		"g_sdc" => true,
		"g_prev_aassg" => true,
		"g_aassg" => true,
		"g_sjbcd" => true,
		"g_asg_sdcpt" => true,
		"g_stg_sdcpt" => true,
		"g_stg_whse_id" => true,
		"g_asg_whse_id" => true,
		"g_alorg_pt" => true,
		"g_fpcwc_pt" => true,
		"g_init_flag" => true,
		"g_key_flg" => true,
		"g_prepare_flg" => true,
		"g_assg_dc_id" => true
	);

	$module_scope = array();
	$cursor_list = array();
	$prepared_list = array();

	// Perform the colorization

	$in_function_dec  = false;
	$after_main = false;
	$in_sql = false;
	$in_record = false;
	$in_construct = false;
	$in_input = false;
	$in_screen = false;

	echo "<TT>\n";
	echo "<FONT COLOR=\"#000000\">";


	while (!feof($fp))
	{
		$line = fgets($fp, 10240);

		echo "<BR>";

		$linepos = 0;
		$length = strlen($line);

		$in_single_quote  = false;
		$in_double_quote  = false;
		$in_line_comment  = false;
		$in_function_line = false;
		$in_variable      = false;

		// Errors only show in column 1

		if ($length > 0 && $line[0] == "|" && ! $in_block_comment)
		{
			setColor($error_color);
			echo str_replace(" ", "&nbsp;", htmlspecialchars(substr($line, $linepos)));
			$linepos = $length;
		}

		while ($linepos < $length)
		{
			$last_char = $char;
			$char = $line[$linepos];

			if ($in_block_comment)
			{
			    	 if ($char == " ")  echo "&nbsp;";
				else if ($char == "\"") echo "&quot;";
				else if ($char == "<")  echo "&lt;";
				else if ($char == ">")  echo "&gt;";
				else if ($char == "\t") echo "&nbsp;&nbsp;&nbsp;&nbsp;";
				else                    echo $char;
				++$linepos;
				if ($char == "}")
				{
					$in_block_comment = false;
				}
			}

			else if ($in_single_quote)
			{
			    	 if ($char == " ")  echo "&nbsp;";
				else if ($char == "\"") echo "&quot;";
				else if ($char == "<")  echo "&lt;";
				else if ($char == ">")  echo "&gt;";
				else if ($char == "\t") echo "&nbsp;&nbsp;&nbsp;&nbsp;";
				else                    echo $char;
				++$linepos;
				if ($char == "'" && $last_char != "\\")
				{
					if ($firstspecial)
					{
						$firstspecial = false;
					}
					else
					{
						$in_single_quote = false;
					}
				}
			}

			else if ($in_double_quote)
			{
			    	 if ($char == " ")  echo "&nbsp;";
				else if ($char == "\"") echo "&quot;";
				else if ($char == "<")  echo "&lt;";
				else if ($char == ">")  echo "&gt;";
				else if ($char == "\t") echo "&nbsp;&nbsp;&nbsp;&nbsp;";
				else                    echo $char;
				++$linepos;
				if ($char == "\"" && $last_char != "\\")
				{
					if ($firstspecial)
					{
						$firstspecial = false;
					}
					else
					{
						$in_double_quote = false;
					}
				}
			}

			else // Not in anything special

			{
				if ($char == "'" && $last_char != "\\")
				{
					$in_single_quote = true;
					$firstspecial = true;
					setColor($quote_color);
				}
				else if ($char == "\"" && $last_char != "\\")
				{
					$in_double_quote = true;
					$firstspecial = true;
					setColor($quote_color);
				}
				else if ($char == "{" && $last_char != "\\")
				{
					$in_block_comment = true;
					$firstspecial = true;
					setColor($comment_color);
				}
				else if (($char == "#" && $last_char != "\\") || ($char == "-" && $linepos < ($length - 1) && $line[($linepos + 1)] == "-"))
				{
					setColor($comment_color);
					echo str_replace(" ", "&nbsp;", htmlspecialchars(substr($line, $linepos)));
					$linepos = $length;
				}
				else
				{
					if ((!$seen_real) && ($char != " ") && ($char != "\t") && ($char != "\n"))
					{
						echo "<A NAME=\"start_of_code\">";
						$seen_real = true;
					}
					// Now we determine just what kind of word we're on the start of.

					$wordlength = strcspn(substr($line, $linepos), "&()\"'#-+*/[],;:$@%^<>= |\t\n");
					if ($wordlength == 0)
					{
						if ($char == "-" && $lastword == "control")
						{
							setColor($keyword_color);
						}
						else if ($char != "\n" && $char != " " && $char != "\t")
						{
							setColor($token_color);
						}

						     if ($char == " ")  echo "&nbsp;";
						else if ($char == "<")  echo "&lt;";
						else if ($char == ">")  echo "&gt;";
						else if ($char == "\t") echo "&nbsp;&nbsp;&nbsp;&nbsp;";
						else                    echo $char;

						++$linepos;

						if ($char == "]" && $linepos < ($length - 1) && $line[($linepos)] == ".")
						{
							setColor($variable_color);
							echo ".";
							++$linepos;
							if ($linepos < ($length - $wordlength) && $line[($linepos + $wordlength)] == "*")
							{
								echo "*";
								$linepos++;
							}
							$in_variable = true;
						}

						if ($char == "(") $in_function_dec = true;
						if ($char == ")") $in_function_dec = false;
					}
					else if ($word == "].")
					{
						setColor($token_color);
						echo "]";
					}
					else
					{
						$word = substr($line, $linepos, $wordlength);
						$lastword = $downword;
						$downword = strtolower($word);
						if (strspn($word, "0123456789") == $wordlength)
						{
							setColor($number_color);
							echo $word;
						}
						else if ($lastword == "declare")
						{
							setColor($cursor_color);
							echo $word;
							$cursor_list[$downword] = true;
						}
						else if ($lastword == "goto" || $lastword == "label")
						{
							setColor($goto_color);
							echo $word;
						}
						else if ($lastword == "prepare")
						{
							setColor($prepared_color);
							echo $word;
							$prepared_list[$downword] = true;
						}
						else if ($lastword == "control" && $wordlength == 1)
						{
							setColor($keyword_color);
							echo $word;
						}
						else if ($sqlstart[$downword])
						{
							if ($lastword == "record")
							{
								$in_record = false;
							}
							setColor($keyword_color);
							echo $word;
							$in_sql = true;
						}
						else if ($keywords[$downword])
						{
							if (!$sqlwords[$downword])
							{
								$in_sql = false;
							}
							if ($in_screen && ($downword != "to" && $downword != "from"))
							{
								$in_screen = false;
							}
							if (($downword == "to" && !($in_initialize || $in_for)) || $downword == "field" || ($downword == "from" && ($in_construct || $in_input)))
							{
								$in_screen = true;
							}
							if ($in_initialize && $downword != "to")
							{
								$in_initialize = false;
							}
							if ($downword == "initialize")
							{
								$in_initialize = true;
							}
							if ($in_for && $downword != "to")
							{
								$in_for = false;
							}
							if ($downword == "for")
							{
								$in_for = true;
							}
							if ($in_input && ($downword != "from" && $downword != "without" && $downword != "defaults"))
							{
								$in_input = false;
							}
							if ($in_construct && ($downword != "on" && $downword != "from"))
							{
								$in_construct = false;
							}
							if ($downword == "input")
							{
								$in_input = true;
							}
							if ($downword == "construct")
							{
								$in_construct = true;
							}
							if ($downword == "main")
							{
								$after_main = true;
								$function_scope = array();
							}
							if ($downword == "record")
							{
								if ($lastword == "end")
								{
									$in_record = false;
								}
								else
								{
									$in_record = true;
								}
							}
							if ($downword == "function" || $downword == "report")
							{
								if ($lastword == "end")
								{
									$function_scope = array();
								}
								else
								{
									$in_function_line = true;
									$current_function = $word;
								}
							}
							setColor($keyword_color);
							echo $word;
						}
						else if ($sqlwords[$downword])
						{
							setColor($keyword_color);
							echo $word;
						}
						else if ($module_scope[$downword]
							|| $function_scope[$downword]
							|| $global_scope[$downword]
							|| $function_scope[substr($downword, 0, strcspn($downword, "."))]
							|| $module_scope[substr($downword, 0, strcspn($downword, "."))]
							|| $global_scope[substr($downword, 0, strcspn($downword, "."))]
						)
						{
							setColor($variable_color);
							echo $word;
							if ($linepos < ($length - $wordlength) && $line[($linepos + $wordlength)] == "*")
							{
								echo "*";
								$linepos++;
							}
						}
						else if ($lastword == "define")
						{
							setColor($variable_color);
							echo $word;
							if ($after_main)
							{
								$function_scope[$downword] = true;
							}
							else
							{
								$module_scope[$downword] = true;
							}
						}
						else if ($in_function_dec)
						{
							setColor($variable_color);
							echo $word;
						}
						else if ($cursor_list[$downword])
						{
							setColor($cursor_color);
							echo $word;
						}
						else if ($prepared_list[$downword])
						{
							setColor($prepared_color);
							echo $word;
						}
						else if ($in_record && $lastword != "like")
						{
							$in_sql = false;
							setColor($variable_color);
							echo $word;
						}
						else if ($in_screen)
						{
							setColor($screen_color);
							echo $word;
							if ($linepos < ($length - $wordlength) && $line[($linepos + $wordlength)] == "*")
							{
								echo "*";
								$linepos++;
							}
						}
						else if ($in_sql || $in_construct || $in_input)
						{
							setColor($database_color);
							echo $word;
							if ($linepos < ($length - $wordlength) && $line[($linepos + $wordlength)] == "*")
							{
								echo "*";
								$linepos++;
							}
						}
						else if ($in_variable)
						{
							$in_variable = false;
							setColor($variable_color);
							echo $word;
						}
						else // Must be a function name
						{
							setColor($function_color);
							echo $word;
						}
						$linepos += $wordlength;
					}
				}
			}
		}
	}

	echo "</FONT>\n";
	echo "</TT>\n";
}
?>
