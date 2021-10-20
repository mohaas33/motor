#!/bin/bash

#initialize file
filename='./config/R1_points.txt'

dirname="/home/tpc/Products/logFiles/$1"
#Make directory
if [ ! -d $dirname ]; then
  mkdir -p $dirname;
fi 

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

    echo "Y=$j"
    quickmove.sh $j 1
    if [ "$steps" -eq 0 ];
    then
        sleep $t_long
    fi
    if [ "$steps" -gt 0 ];
    then
        sleep $t_short
    fi
    
    timestamp=`date "+%Y_%m_%d_h%H_m%M_s%S"`
    filename="$dirname/$1-X-$i-Y-$j-$timestamp.txt"
    if [ -e $filename ]; then
      echo "File $1 already exists!"
    else
      echo $filename
      echo "X $j Y $i" >> "$filename"
      ../gasControlMKS/MKSLogger.py $filename 1 1
      ../dataqO2/simle_O2_monitor.py >> "$filename"
      ../picologic_libusb/picologic $filename 10
    fi
    sleep $t_short
    steps=$((steps+1))

done < $filename

exit
