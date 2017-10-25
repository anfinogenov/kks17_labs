#!/usr/bin/env bash

gcc `ls | grep .c$` -o main.out
./main.out

