#!/bin/sh

[ -z "$SERIALLINE" ] && export SERIALLINE=/dev/ttyUSB0

echo "C,I2M-0,R" > $SERIALLINE


