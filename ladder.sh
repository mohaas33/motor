#!/bin/bash

#Initialize file
filename='ladder.txt'

#initialize motor
#motorinit
#sleep 1

#initial x,y
echo "0 0" > $filename

#delta x,y
dx=500
dy=500

#Generate x,y coordinates in steps of 500
for i in {0..4}
do
    x=$(($x + $dx))
    y=$(($y + $dy))
	 echo "$x $y" >> $filename
done

#Move motor 1 and motor 2 to each x and y location 
while IFS=' ' read -r i j
do
    quickmove.sh $i 2
    sleep 3
    quickmove.sh $j 1
    sleep 3
done < $filename

exit
