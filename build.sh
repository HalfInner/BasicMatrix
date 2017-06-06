#!/bin/sh

g++ -std=gnu++17 -fsyntax-only src/TMatrix.hpp 

mkdir -p bin
CPPFLAGS='-std=gnu++17 -g -Wall -Wextra'
g++ $CPPFLAGS -isystem gtestinclude/ -pthread src/mGTest.cpp lib/libgtest.a  -o bin/test
