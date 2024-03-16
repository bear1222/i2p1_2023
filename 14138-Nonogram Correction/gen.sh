#!/bin/bash

for i in {0..9}
do 
    echo "$i"
    ./ans < "./testcase/$i.in" > "./testcase/$i.out"
done
