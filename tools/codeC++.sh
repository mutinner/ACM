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
				if [ $num -ge 0 ]; then
					vim ${arr[num]}
				fi
				;;
			r)
				if [ $num -ge $OPTARG ]; then
					let num-=${OPTARG}
					vim ${arr[num]}
				fi
				;;
		esac
		if [ -f ${arr[num]:0:23} ]; then
			rm ${arr[num]:0:23}
		fi
	fi	
done

if [ $flag -eq 0 ]; then
	cd $tim
	file=$(date +%T)
	cpp=$file'.cpp'
	vim $cpp
	cd ~/Code/$tim
	cur=1
	if [ -f $cpp ]; then
		while read line
		do
			let cur++
		done <$cpp
		if [ $cur -lt 14 ]; then
			rm $cpp
			cd ~/Code
			if [ ! "$(ls -A $tim)" ]; then
				rmdir $tim
			fi
		fi
	fi
	if [ -f $file ]; then
		rm $file
	fi
fi
