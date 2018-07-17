#!/bin/bash  
 
if [ $# != 3 ]; then  
    echo 'Usage: addr2line.sh executefile addressfile functionfile'  
    exit  
fi;  
index=0
cat $2 | while read line  
do  
     if [ "$line" = 'Enter' ]; then  
             read line1  
             read line2  
#           echo $line >> $3  	
 			 index=$((index+6))

             str=$(printf "%-"$index"s-" "-")
			 text=$(echo -e ""  " ${str// /-}") 
             text1="$text  $(addr2line -e $1 -f $line1 -s)"
             text2="$text  $(addr2line -e $1 -f $line2 -s | sed 's/^/    /' )"
			 echo $text1 >> $3
 			 echo $text2 >> $3

             echo >> $3  
     elif [ "$line" = 'Exit' ]; then
			 index=$((index-6))

			 continue
             read line1  
             read line2  
             addr2line -e $1 -f $line2 -s | sed 's/^/    /' >> $3  
			 index=$((index-1))
             str=$(printf "%-"$index"s-" "-")
			 echo -e "}out "$index " ${str// /-}/c" >> $3   
             addr2line -e $1 -f $line1 -s >> $3  
#           echo $line >> $3  
             echo >> $3  
     fi;  
done 
#./addr2line.sh ./objs/nginx  /usr/local/nginx/sbin/mydebug.log mylog.log