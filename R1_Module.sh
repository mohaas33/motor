#!/bin/bash

#initialize file
filename='./config/R1_points.txt'

#initialize motor

echo "move to X = 0 position"
# move to X = 0 position
goto_NegativeLimit_motor2.sh
# wait until it gets there
sleep 150
echo "move to Y = 0 position"
# move to Y = 0 position
goto_NegativeLimit_motor1.sh
# wait until it gets there
sleep 150

motorinit
sleep 3

t_long=60
t_short=30
steps=0
lines=$(wc -l < "$filename")
#Move motor 1 and motor 2 to each x and y location 
while IFS=' ' read -r i j
do
    echo "processing step $steps of $lines ..."
    echo "X=$i"
    quickmove.sh $i 2
    if [ "$steps" -eq 0 ];
    then
        sleep $t_long
    fi
    if [ "$steps" -gt 0 ];
    then
        sleep $t_short
    fi

    echo "X=$j"
    quickmove.sh $j 1
    if [ "$steps" -eq 0 ];
    then
        sleep $t_long
    fi
    if [ "$steps" -gt 0 ];
    then
        sleep $t_short
    fi

    steps=$((steps+1))

done < $filename

exit
