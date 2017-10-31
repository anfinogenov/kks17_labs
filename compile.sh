#!/usr/bin/env bash

cd sources
echo -n "Compilation start"
time gcc `ls . | grep .c$` -o ../main.out &&
echo -e "Compilation success!\n" 
cd .. 
if [[ $1 == 'exec' ]] 
then
    echo "Execution start"
    ./main.out plain_text.txt enc_text.txt 13 
fi

