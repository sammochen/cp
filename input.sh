#!/bin/bash

n=$(ls ./in | wc -w)

n=$(($n + 1))

echo "$1" >./in/in$n