#!/bin/sh
#
#   4gltree
#
#   Contributed by Sadru Fidai <SFidai@aol.com>
#


#input formats
#file_name:function func_name(lakjdfs...
#file_name:  call func_name(....
#file_name: lkajdfs = func_name(......
#file_name: if func_name(......
#file_name: or func_name(......
#start report view_hold_end to hold_header
#output to report view_hold_end()
#finish report view_hold_end

XREF=0

if [ "$1" = "-?" ]
then
   echo  usage: 4gltree [-x] [-c]
   echo         -x Generate Cross Ref
   echo         -c Generate file for cflow format
   exit
fi

if [ `ls *.4gl 2>/dev/null| wc -l ` -eq 0 ]
then
   echo Error: No .4gl files in the directory
   echo
   exit
fi


if [ "$1" = "-x" ]
then
   XREF=1
fi

if [ "$1" = "-c" ]   # cflow interface
then
   XREF=2
fi

trap "rm -f /tmp/4tree[12]$$;exit" 1 2 3 15 

cat <<EOF >/tmp/4tree1$$
function print_func_line(){
        if (XREF == "1")
        {
           if (called_func != "")
              printf("%s|%s|%s\n", called_func, calling_func, prog_file);
        }
        else
        if (XREF == "2")
        {
           if (func_piped == 0)  #if first line of that function
           {
              if (first_time == 0)
                 printf ("}\n"); # complete prev function
              printf ("int %s()\n{\n", calling_func);
           }
           else
           {
              if (called_func == "")
                 printf ("}\n"); # complete prev function
           }
           #if (called_func == "")
           #   printf ("}\n"); #close previous function
           #else
           if (called_func != "")
              printf ("%s();\n", called_func);
        }
        else
           printf("%s|%s|%s\n", calling_func, prog_file, called_func);

        called_func="";
        func_piped=1;
        first_time=0;
        #printf("progfile=%s, calling_func=%s, called_func=%s\n", prog_file, calling_func, called_func);
}
BEGIN{
        calling_func = "MAIN";
        called_func = ""
        prog_file = "";
        first_time = 1;
        func_piped = 0;
}
/(:function|:FUNCTION|:report|:REPORT[ 	][ 	]*[a-zA-Z0-9][a-zA-Z0-9_]*[(])/{
        if (first_time == 0 && func_piped == 0)
           print_func_line();      # Print previous function line
        calling_func=\$2;
        prog_file = \$1;
        sub(":.*","", prog_file);
        sub("[(].*","",calling_func);
        func_piped=0;
        first_time=0;
        #print "calling function: " calling_func;
        next;
}
/(if|or|and|call|=)[ 	(][ 	(]*[a-zA-Z0-9][a-zA-Z0-9_]*\(/{
        called_func="";
        #print  "matched line: " \$0

        if (prog_file == "")
        {
           prog_file = \$1;
           sub(":.*","", prog_file);
        }

        i=0;
        start_match=0;

        while (1)
        {
        #print "in while "
        #i=match(\$0,"if[ 	]*[a-z0-9][a-z0-9_]*\(");
        i=match(\$0,"if[ 	(][ 	(]*[a-zA-Z0-9][a-zA-Z0-9_]*[(]");

        if (i > 0)
        {
           start_match=i+3;
           break;
        }

        i=0;
        #i=match(\$0,"call[ 	(]*[a-zA-Z0-9][a-zA-Z0-9_]*[(]");
        # Thu Jan 12 16:21:36 EST 1995
        #i=match(\$0,"call[ 	][ 	]*[a-zA-Z0-9][a-zA-Z0-9_]*[(]");
        i=match(\$0,"call[ 	][ 	]*[a-zA-Z0-9][a-zA-Z0-9_]*[ (]");
 
        #print "after call match, i: " i
        #print "RSTART: " RSTART
        #print "RLENGTH: " RLENGTH

        if (i > 0)
        {
           start_match=i+5;
           break;
        }

        i=0;
        i=match(\$0,"=[ 	(]*[a-zA-Z0-9][a-zA-Z0-9_]*[(]");

        if (i > 0)
        {
           start_match=i+2;
           break;
        }

        i=0;
        i=match(\$0,"or[ 	(][ 	(]*[a-zA-Z0-9][a-zA-Z0-9_]*[(]");

        if (i > 0)
        {
           start_match=i+3;
           break;
        }

        i=0;
        i=match(\$0,"and[ 	(][ 	(]*[a-zA-Z0-9][a-zA-Z0-9_]*[(]");

        if (i > 0)
        {
           start_match=i+4;
           break;
        }
        }
        #print;
        #print "rec length: " length(\$0)
        #print "start Match: " start_match


        if (start_match > 0)
        {
           func_done=0;
           for (i=start_match;i<length(\$0);i++) 
           {
               if ((substr(\$0,i,1) == "") || (substr(\$0,i,1) == "(") || (substr(\$0,i,1) == "	") || (substr(\$0,i,1) == " "))
               {
                  if (func_done == 1)
                     break;
                  else
                     continue;
               }

               #if (substr(\$0,i,1) == "(" )
               #   break;
               func_done=1;

               called_func = called_func substr(\$0,i,1);
   
           }
           #print "called function: " called_func;
           print_func_line();
        }
        next;
}

#start report view_hold_end to hold_header
#output to report view_hold_end()
#finish report view_hold_end
#/(start|finish|output).*[ 	]report[ 	]*[a-z0-9][a-z0-9_]*/

{next;}

END{
        #if (first_time == 1 && func_piped == 0)
        if (func_piped == 0)
           print_func_line();
        if (XREF == "2")
           if (func_piped != 0)  #if first line of that function
              printf ("}\n"); # complete prev function
}
EOF

cat <<EOF >/tmp/4tree2$$
BEGIN{
   multi_comments=0
}

/{/{
    #print "at open, multi_comments: " multi_comments;

     #if (multi_comments==1)
     #   next;
     #else
     if (multi_comments!=1)
     {
     recline=\$0;
     outrec=""
     comment_on=0;
    #print "before for loop, recline: " recline " length: " length(recline);
     for (i=1;i <= length(recline); i++ )
     {
        if (substr(recline,i,1) !="{" && comment_on == 0)
        {
           outrec= outrec substr(recline,i,1);
           continue;
        }

        if (comment_on == 1 && substr(recline,i,1)  == "}")
        {
           comment_on=0;
           continue;
        }

        if (substr(recline,i,1)  == "{" && comment_on == 0)
        {
           comment_on=1;
           continue;
        }

        if (comment_on == 1)
        {
           continue;
        }
        outrec= outrec substr(recline,i,1);
     }
     if (comment_on == 1)
     {
        multi_comments=1;
        next;
     }
     print outrec;
     next;
     }
}

/}/{
     if (multi_comments == 1)
     {
        recline=\$0;
        outrec= "";
        comment_on=1;
        for (i=1;i <= length(recline); i++ )
        {
           if (substr(recline,i,1) !="}" && comment_on == 1)
           {
              continue;
           }
   
           if (comment_on == 1 && substr(recline,i,1)  == "}")
           {
              comment_on=0;
              continue;
           }
           outrec= outrec substr(recline,i,1);
        }
        multi_comments=0;
     }
     else
         outrec=\$0;

     print outrec
     next;
}

/--/{
   sub("--.*\$","");
}

/#/{
   sub("#.*\$","");
}

{
   if (multi_comments==1)
      next;
   print;
}           
EOF

#cp /tmp/4tree1$$ /tmp/4tree1.nawk
#cp /tmp/4tree2$$ /tmp/4tree2.nawk
#exit

#egrep -e "(^function|^report[ 	]*[a-z0-9][a-z0-9_]*\(|(if|or|and)[ 		]*[a-z0-9][a-z0-9]*\(| = [a-z0-9][a-z0-9]*\(|ll [a-z0-9][a-z0-9]*\()" *.4gl |
#nawk -f /tmp/4tree
#grep .  *.4gl | nawk -f $HOME/bin/filter_comments | grep . |
#grep .  *.4gl | nawk -f /tmp/4tree2$$ | grep . | pg
#grep .  *.4gl | nawk -f /tmp/4tree2.nawk |
grep .  *.4gl | awk -f /tmp/4tree2$$ |  grep . |
case $XREF in

    0) #functions list
       awk -f /tmp/4tree1$$ XREF=$XREF
       #nawk -f /tmp/4tree1.nawk XREF=$XREF
       ;;
    
    1) #reverse functions xref
       awk -f /tmp/4tree1$$ XREF=$XREF | sort -u -t\| +0 -1 +1 -2
       ;;
    
    2) #create c-skeleton file to be used with cflow
       awk -f /tmp/4tree1$$ XREF=$XREF
       ;;
esac

#if [ $XREF -eq 0 ]
#then
#   nawk -f /tmp/4tree$$
#else
#   nawk -f /tmp/4tree$$ | sort -t\| +2 -3 +1 -2
#fi

rm -f /tmp/4tree[12]$$
