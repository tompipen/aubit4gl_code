:	"@(#)mkdist.sh	6.5 89/11/14"
#
#	@(#)FGLBLD Version 6.12 (04/04/1990)
#	Make binary distribution

: ${FGLBLDDIR:=.}

#Soure the configuration file
. etc/fglbldrc


DISTRIBUTION=$FGLBLDDIR/Distribution

case "$1" in
-c)	check=yes
	mkchk=-n;;
"")	check=no;;
*)	echo "Usage: $0 [-c]" >&2
	exit 1;;
esac

# Remove the existing distribution directory
if [ $check = no ]
then
	rm -fr $DISTRIBUTION >/dev/null 2>&1

	# Check that there is a distribution directory (it may still exist)
	if [ ! -d $DISTRIBUTION ]
	then
		mkdir $DISTRIBUTION
		chmod 755 $DISTRIBUTION
	fi
fi

# Check existence of file list
:	${FGLTYPE:=RDS}

case $FGLTYPE in


RDS)	ext=RDS;;
C4GL)	ext=4GL;;
*)		echo "$arg0: unknown type $FGLTYPE -- should be RDS or C4GL" >&2
		exit 1
esac

objfile=./etc/fglbld-$ext.lst
if [ ! -f $objfile ]
then
	if [ -f ./etc/$objfile ]
	then
		objfile=./etc/$objfile
	elif [ -f $FGLBLDDIR/$objfile ]
	then
		objfile=$FGLBLDDIR/$objfile
	elif [ -f $FGLBLDDIR/etc/$objfile ]
	then
		objfile=$FGLBLDDIR/etc/$objfile
	else
		echo "$0: $objfile missing" >&2
		exit 1
	fi
fi

cat $objfile |
while read file type link owner group perms
do
	case "$file" in
	\#*)	: Comment
		continue;;
	"")	: Blank
		continue;;
	esac

	if [ $type = directory ]
	then
		if [ $check = yes ]
		then
			continue
		fi
		if [ ! -d $DISTRIBUTION/$file ]
		then
			mkdir $DISTRIBUTION/$file
			chmod 755 $DISTRIBUTION/$file
		fi
		continue
	fi

	if [ $type = deleted ]
	then
		continue
	fi

	if [ $type = link ]
	then
		continue
	fi

	source=$file

	basefname=`basename $file`

	#we no longer use .4pr as extension for per files
	perfname=`basename $file .4pr`
	if [ "$perfname" != "$basefname" ]
    then
        #striping .4pr was successfull - file had .4pr extension
		source="./per/$perfname.per"
	fi

    #we renamed fglbld.RDS fglbld.4GL and fglbld.src
	lstfname=`basename $file .RDS`
	if [ "$lstfname" != "$basefname" ]
    then
		source="./etc/$lstfname-RDS.lst"
	fi




	if [ ! -r $source ]
	then
		#maybe the path in .lst file is wrong?
		source=`basename $file`
		if [ ! -r $source ]
		then
			if [ "$source" == "fgldb" ] &&  [ "$I4GL_DEBUG" == "no" ]
			then
                #ignore this one
				continue
            else
				#is it in per?
				source="./per/`basename $file`"
				if [ ! -r $source ]
				then
					#is it in man?
					source="./man/`basename $file`"
					if [ ! -r $source ]
					then
						source="./sql/`basename $file`"
						if [ ! -r $source ]
						then
							source="./include/`basename $file`"
							if [ ! -r $source ]
							then
								echo "$0: $file ($source) not found - check your build success" >&2
								if [ $check = no ]
								then
									exit 1
								else
									continue
								fi
                            fi
                        fi
                    fi
                fi
            fi
		fi

	fi

	echo $DISTRIBUTION/$file
	if [ $check = no ]
	then
		cp $source $DISTRIBUTION/$file
		chmod $perms $DISTRIBUTION/$file
	fi

done


echo "Distribution directory successfuly created. To install:"
echo ""
echo "1.  Change into the distribution directory."
echo "    Type: cd Distribution"
echo "2.  Set and export the variables FGLBLDDIR, FGLBLDBIN, FGLUSR, FGLGRP"
echo "    unless the default is acceptable."
echo "3.  Run install script."
echo "    Type: ./install"
echo "4.  Exit from superuser."
echo "    Type: exit"
echo ""

