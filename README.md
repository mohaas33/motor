## Calculate the X,Y steps



### Running test

- For R1 frames:

`./R1_Module_run.sh PadPlane00_R1`
It loops over X,Y positions in the `./config/R1_points.txt` and creates txt files for each X,Y position.
Example of the output:

X 13012 Y 13849

00149 00149 00079

-0.019  0.019  0.039  0.042 

1634750775343 -0.001 -0.012 -0.000 -0.010 -0.012 -0.011 -0.014 -0.003 -0.010 -0.010 -0.017 -0.010 

1634750775343 -0.005 -0.012 -0.004 -0.014 -0.008 -0.011 -0.018 -0.011 -0.017 -0.010 -0.009 -0.010 

1634750775343 -0.005 -0.016 -0.004 -0.014 -0.016 -0.007 -0.010 -0.007 -0.017 -0.010 -0.013 -0.010 

1634750775344 -0.005 -0.004 -0.004 -0.014 -0.008 -0.011 -0.010 -0.007 -0.013 -0.010 -0.013 -0.013 

1634750775344 -0.005 -0.012 -0.004 -0.010 -0.012 -0.011 -0.018 -0.011 -0.010 -0.014 -0.013 -0.013 

1634750775344 -0.001 -0.012 -0.004 -0.010 -0.012 -0.011 -0.010 -0.011 -0.013 -0.014 -0.013 -0.010 

1634750775344 -0.005 -0.008 -0.004 -0.014 -0.012 -0.007 -0.014 -0.007 -0.017 -0.010 -0.017 -0.013 

1634750775344 -0.005 -0.008 -0.008 -0.014 -0.016 -0.011 -0.018 -0.007 -0.013 -0.010 -0.013 -0.013 

1634750775344 0.003 -0.012 -0.000 -0.010 -0.016 -0.011 -0.018 -0.011 -0.013 -0.006 -0.013 -0.006 

1634750775344 0.003 -0.016 -0.004 -0.014 -0.012 -0.011 -0.018 -0.007 -0.017 -0.014 -0.017 -0.010 

It contains:

- X,Y position in steps 1000 steps = 5 mm;
- Flowmeter flow 4 and 6, pressure;
- O2 measurement (only first number is the measurement);
- Ten picoamper-meter measurements (1 per second) 12 channels per line

### 1-st Script should do:
- [x] Create txt file with coordinates the motors should follow for R1, R2 R3 ([example of txt file](https://github.com/mohaas33/motor/blob/main/config/setXY_R1.txt))
### 2-nd Script should do:
- [x] Move to the negative minimum for both of the motors;
- [x] Get as input file name with coordinates and dX dY bias for (0,0) coordinate
- [x] Read the coordinates from the txt file and correct those for the dX dY line by line;
- [x] Set the motors to the coordinates (1 step **should be** 1.8 deg => 0.2cm*1.8/360=10 micrometers => 1mm=1000 steps) Measured number **5mm=1000** steps;
- [x] Sleep for some time (1 sec for example) and move to the next coordinate;
