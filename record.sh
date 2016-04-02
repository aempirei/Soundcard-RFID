#!/bin/bash

if [ ! -f "$1" ]; then
	echo
	echo usage: $0 filename
	echo
	exit
fi

# if arecord is missing it can be found in the debian package alsa-utils
# see http://linux.die.net/man/1/arecord for different format options

arecord -f S16_LE -c 1 -r 125000 $1
