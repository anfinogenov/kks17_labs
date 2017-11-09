#!/usr/bin/env bash

if [ -z $* ]
then
echo "No options found!"
exit 1
fi

while getopts "ec" opt
do
case $opt in 
c)  cd sources; 
    echo -n "Compilation start"; 
    time gcc `ls . | grep .c$` ../tests/test.c -o ../main.out && 
    echo -e "Compilation success!\n"; 
    cd ..;;
e)  echo "Execution start"; 
    ./main.out plain_text.txt enc_text.txt 13 vigenere; 
    echo "Execution ended, result: $?";;
esac
done
