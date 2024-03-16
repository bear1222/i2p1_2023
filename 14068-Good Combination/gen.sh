#!/bin/bash

for i in {0..6}
do 
    ./ans < "./testcase/$i.in" > "./testcase/$i.out"
done
