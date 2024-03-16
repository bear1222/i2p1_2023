#!/bin/bash

for i in {4..5}
do 
    ./geninput2 > "./testcase/$i.in" < "tmp"
    ./ans < "./testcase/$i.in" > "./testcase/$i.out"
    sleep 1
done
