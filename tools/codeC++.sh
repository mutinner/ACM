#!/bin/bash

cd Code
DATE='C++/'$(date +%Y-%m-%d)'/'

if [ ! -d $DATE ]; then
	mkdir $DATE
fi

cd $DATE
file=$(date +%T)".cpp"
file=${file//:/-}
vim $file

cd ~/Code/$DATE
cur=1

if [ -f $file ]; then
	while read LINE
	do
		let cur++
	done <$file
	if [ $cur -lt 14 ]; then
		rm $file
		cd ~/Code
		if [ ! "$(ls -A $DATE)" ]; then
			rmdir $DATE
		fi
	fi
fi

