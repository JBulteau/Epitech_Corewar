#!/bin/bash

check_return()
{
        if [ $? == $1 ]; then
                echo "RETURN VALUE: OK"
        else
                echo "NOPE"
        fi
}

make -C ..
if [ $# -eq 0 ]
then
	CHAMPIONS_PATH=../champions/invalid/*.s
else
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
	
	../binaires-champ-corewar/asm $f
	../asm/asm $f
	check_return 84
done
rm *.cor
