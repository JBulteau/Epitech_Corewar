#!/bin/bash

make
if [ $# -eq 0 ]
then
	CHAMPIONS_PATH=./champions/invalid/*.s
else
	#for var in "$@"; do
	#	echo "$var"
	#done
	CHAMPIONS_PATH=$1
fi

rm -rf res
mkdir res
rm -f res/*.res

dif=0
no_dif=0
for f in $CHAMPIONS_PATH; do
	echo "---------------------------------------------------------"
	echo "Compiling "$f
	echo "---------------------------------------------------------"
	
	./binaires-champ-corewar/asm $f
	./asm/asm $f
done
rm *.cor
