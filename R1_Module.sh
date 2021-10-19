#!/bin/bash

#initialize file
filename='R1_points.txt'

#initialize motor
#motorinit
#sleep 1

#Move motor 1 and motor 2 to each x and y location 
while IFS=' ' read -r i j
do
    quickmove.sh $i 2
    sleep 3
    quickmove.sh $j 1
    sleep 3
done < $filename

exit
