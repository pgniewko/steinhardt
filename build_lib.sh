#! /bin/bash -x

cd ./src/

if [ $? ]; then
  rm *.o
  rm libsteinhardt.a 

  g++-4.9 -O3 -Wall -lm -lgsl -lgslcblas -c -o steinhardt.o steinhardt.c
  ar -rcs libsteinhardt.a steinhardt.o
  ranlib libsteinhardt.a
  sudo cp libsteinhardt.a /usr/local/lib
  sudo cp steinhardt.h /usr/local/include
fi
