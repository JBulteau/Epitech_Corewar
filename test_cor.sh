#!/bin/bash
./asm/asm ./champions/live1.s

check_return()
{
        if [ $? == $1 ]; then
                echo "OK"
        else
                echo "NOPE"
        fi
}

echo "---------------------------------------------------------"
echo "Invalid file"
echo "---------------------------------------------------------"
./corewar/corewar notfound.cor b.cor c.cor d.cor
check_return 84

echo "---------------------------------------------------------"
echo "Too many args"
echo "---------------------------------------------------------"
./corewar/corewar live1.cor live1.cor live1.cor live1.cor live1.cor
check_return 84

rm live1.cor