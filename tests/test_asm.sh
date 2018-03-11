#!/bin/bash

make -C ..
if [ $# -eq 0 ]
then
	CHAMPIONS_PATH=../champions/*.s
else
	#for var in "$@"; do
	#	echo "$var"
	#done
	CHAMPIONS_PATH=$1
fi

rm -rf ../res
mkdir ../res
rm -f ../res/*.res

dif=0
no_dif=0
for f in $CHAMPIONS_PATH; do
	echo "---------------------------------------------------------"
	echo "Compiling "$f
	echo "---------------------------------------------------------"
	name=`echo $f | rev | cut -d'/' -f1 | rev`
	compiled=${name%.*}'.cor'
	
	../binaires-champ-corewar/asm $f
	if [[ -f $f ]]
	then
		hexdump -C $compiled > a
		mv $compiled $name'-EXAMPLE.cor'
	else
		echo "PAS OK ---- SYNTAX EXAMPLE"
	fi

	../asm/asm $f
	if [[ -f $f ]]
	then
		hexdump -C $compiled > b
	else
		echo "PAS OK ----- SYNTAX"
	fi

	diff -y a b > c
	diff a b > d
	if [ -s d ]
	then
        	echo "DIFF"
		rm a b
		mv $compiled $name'-EXAMPLE.cor' 'res/'
		mv c res/${name%.*}'.res'
		((dif++))
	else
		rm a b c
		((no_dif++))
	fi
done
echo "NB DIFF : $dif"
echo "NB NO DIFF : $no_dif"
rm d
rm -f *.cor
