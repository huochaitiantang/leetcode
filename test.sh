#/bin/bash

g++ $1 -o test -std=c++11
./test
rm ./test
