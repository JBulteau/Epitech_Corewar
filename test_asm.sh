 #!/bin/bash

CHAMPIONS_PATH=./champions/*.s

rm -rf res
mkdir res
rm -f res/*.res

for f in $CHAMPIONS_PATH; do
	echo "Compiling "$f
	name=`echo $f | rev | cut -d'/' -f1 | rev`
	compiled=${name%.*}'.cor'
	
	./binaires-champ-corewar/asm $f
	if [[ -f $f ]]
	then
		echo "OK - ASM EXAMPLE"
		hexdump -C $compiled > a
	else
		echo "PAS OK"
	fi

	./asm/asm $f
	if [[ -f $f ]]
	then
		echo "OK - ASM"
		hexdump -C $compiled > b
	else
		echo "PAS OK"
	fi

	diff a b > c
	if [ -s c ]
	then
        	echo "DIFF"
		rm a b
		mv c res/${name%.*}'.res'
	else
        	echo "NO DIFF"
		rm a b c
	fi
done
rm -f *.cor
