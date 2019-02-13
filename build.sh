#!/usr/bin/env bash

#$1 = Target (compile | debug)
#$2 = file directory
#$3 = output filename

cd "${2}"
echo -n "I'm in "
pwd

if [[ $1 == "compile" ]]; then
    g++ -std=c++14 -o "${3}.out" *.cpp
elif [[ $1 == "debug" ]]; then
    g++ -std=c++14 -g -o "${3}.out" *.cpp
fi