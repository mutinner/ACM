#!/bin/bash

cd ~/Code/C++
DATE=$(date +%F)

if [ ! -d $DATE'/' ]; then
	mkdir $DATE
fi

cd $DATE

file=$(date +%T)".cpp"
vim $file
