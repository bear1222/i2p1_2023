#!/bin/bash

for i in {0..6}
do 
#    ./geninput > "./testcase2/$i.in" < "tmp"
    ./ans < "./testcase/$i.in" > "./testcase/$i.out"
#    sleep 5
done
