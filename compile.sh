#!/usr/bin/env bash

cd sources
echo -n "Compilation start"
time gcc `ls . | grep .c$` -o ../main.out &&
echo -e "Compilation success!\n" 
cd .. 
echo "Execution start"
./main.out

