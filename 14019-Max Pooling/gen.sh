#!/bin/bash

for i in {0..10}
do 
    echo "./testcase/$i.out start."
    ./ans < "./testcase/$i.in" > "./testcase/$i.out"
    echo "./testcase/$i.out finish."
done
