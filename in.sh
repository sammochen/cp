#!/bin/bash

if [[ $# -ne 1 ]] ; then
    echo "No input" >&2
    exit 0
fi

n=$(ls ./.in | wc -w)

n=$(($n + 1))

echo "$1" >./.in/in$n
