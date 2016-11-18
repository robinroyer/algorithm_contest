#!/bin/sh

for nbGroup in {10,20,40,80}; do
    for maxGroupeSize in {1,3,5}; do
        for p in {0.3,0.6}; do
            for i in {1..5}; do
                python3 ./gen.py $nbGroup $maxGroupeSize $p > ./data/$nbGroup\_$maxGroupeSize\_$p.$i
            done
         done
    done
done
