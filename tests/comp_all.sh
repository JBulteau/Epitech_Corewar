#!/bin/bash

make -C ..
CHAMPIONS_PATH=../champions/*.s

for f in $CHAMPIONS_PATH; do
	../asm/asm $f
done