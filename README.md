
### 1-st Script should do:
- [ ] Create txt file with coordinates the motors should follow for R1, R2 R3 ([example of txt file](https://github.com/mohaas33/motor/blob/main/config/setXY_R1.txt))
### 2-nd Script should do:
- [ ] Move to the negative minimum for both of the motors;
- [ ] Get as input file name with coordinates and dX dY bias for (0,0) coordinate
- [ ] Read the coordinates from the txt file and correct those for the dX dY line by line;
- [ ] Set the motors to the coordinates (1 step is 1.8 deg => 0.2cm*1.8/360=10 micrometers => 1mm=1000 steps);
- [ ] Sleep for some time (1 sec for example) and move to the next coordinate;
