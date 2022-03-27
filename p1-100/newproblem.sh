#!/bin/sh
mkdir p$1

touch p$1/p$1.cpp

echo "/*
    Problem $1

    Author: $2
*/

#include <iostream>

using namespace std;

int main(){

    return 0;
}" > p$1/p$1.cpp