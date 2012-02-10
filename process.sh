#!/bin/bash

if [ ! -f "$1" ]; then
	echo
	echo usage: $0 filename
	echo
	exit
fi

cat "$1" | ./decode | ./bits|tr -d '\n'|perl -pe 's/000111/\n/g' | ./manchester | grep -v failure | sort | uniq
