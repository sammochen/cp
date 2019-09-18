#!/bin/bash

n=$(ls ./.in | wc -w)

n=$(($n + 1))

>./.in/in$n

gedit ./.in/in$n
