#!/bin/bash

for i in {0..3}
do 
    ./ans < "./testcase/$i.in" > "./testcase/$i.out"
done
