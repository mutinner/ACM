#!/bin/bash

cd Code
tim='C++/'$(date +%Y-%m-%d)'/'

if [ ! -d $tim ]; then
	mkdir $tim
fi

flag=0

while getopts "lr:" opt; do
	let flag=1
	if [ "$(ls -a $tim)" ]; then
		let num=0
		for it in ${tim}*
		do
			arr[num]=$it
			let num++
		done
		let num--
		case $opt in
			l)
				echo ${arr[num]}
				vim ${arr[num]}
				;;
			r)
				if [ $num -ge $OPTARG ]; then
					let num-=${OPTARG}
					vim ${arr[num]}
				fi
				;;
		esac
	fi	
done

if [ $flag -eq 0 ]; then
	cd $tim
	file=$(date +%T)".cpp"
	vim $file
	cd ~/Code/$tim
	cur=1
	if [ -f $file ]; then
		while read line
		do
			let cur++
		done <$file
		if [ $cur -lt 14 ]; then
			rm $file
			cd ~/Code
			if [ ! "$(ls -A $tim)" ]; then
				rmdir $tim
			fi
		fi
	fi
fi
