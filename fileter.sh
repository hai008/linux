#!/bin/bash
p=""
struct=""
i=0
for line in $(cat $1)
do
	pre=$(echo $line | awk '{print $0}' | cut -c 1)
	if [[ $pre == "\`" ]]; then
		colum=$(echo $line | awk -F "\`" '{print $2}')
		if [[ $i == 0 ]];then
			p=$p"static const std::string TABLE_NAME=\""$colum"\";"
		else
			p=$p"\r\n"
			struct=$struct"\n"
			p=$p"static const std::string FLD_"$(echo $colum | cut -c2- | tr 'a-z' 'A-Z')"=\""$colum"\";"
			struct=$struct"std::string str"$(echo $colum | sed 's/'F'/''/g' | sed 's/^\w\|\_\w/\U&/g' | sed 's/\_/''/g')";"
		fi
		i=$(( $i + 1 ))
	fi
done
echo
echo -e $p
echo 
echo -e $struct
echo
