#!/bin/sh

[ -z "$SERIALLINE" ] && export SERIALLINE=/dev/ttyUSB0

MOTOR=$2
[ -z "$MOTOR" ] && MOTOR=1

echo "C,IA1M0,R" > $SERIALLINE
echo "C,IA2M0,R" > $SERIALLINE

exit
