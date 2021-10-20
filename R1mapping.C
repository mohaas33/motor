#include <cmath>
#include <iostream>
#include <fstream>
using namespace std ;

int main() {
  double rpoints[32]={8.739, 9.159, 9.167, 9.605, 9.613, 10.051, 10.059, 10.496, 10.504, 10.942, 10.950, 11.388, 11.396, 11.833, 11.841, 12.279, 12.287, 12.725,12.733, 13.170, 13.178, 13.616, 13.624, 14.062, 14.070, 14.507, 14.515, 14.953, 14.961, 15.339, 15.407, 15.852};
  int len = sizeof(rpoints)/sizeof(rpoints[0]);
  const int arr_s = len/2;
  double rmid[arr_s];
  int i=0;
  int j=0;
  
  for(int i=0; i<len; i = i+2){
    rmid[j] = (rpoints[i]+rpoints[i+1])/2.0;
    j++;
  }

  double dX = 7;
  double dY = 4;
  double inch_to_mm = 0.19685;
  double phi = 0.52;
  double deltaphi[arr_s];
  int numpoints=0;

  for(int k = 0; k < arr_s; k++){ 
    deltaphi[k] = 0.2/rmid[k];
    numpoints = numpoints + round(phi/deltaphi[k]);
  }
  
  double xpoints[numpoints];
  double ypoints[numpoints];
  double tot_angle=-phi/2.0;
  int p=0;
  int p_max=round(phi/deltaphi[0]);
  
  for(int w = 0; w < arr_s; w++){
      
    for(p; p <= p_max; p++){
      xpoints[p] = 1000*((rmid[w]*cos(tot_angle))-dX)/inch_to_mm;
      ypoints[p] = 1000*((rmid[w]*sin(tot_angle))-dY)/inch_to_mm;
      tot_angle = tot_angle + deltaphi[w];
    }
    
    p_max = p_max + round(phi/deltaphi[w+1]);
    tot_angle = -phi/2.0;
  }

  ofstream myfile;
   myfile.open("./config/R1_points.txt",std::ofstream::trunc);
  for(int z = 0; z < numpoints; z++){
    myfile << round(xpoints[z]) << " " << round(-ypoints[z]) << ".\n";
  }

  myfile.close();
  
  return 0;
  
}
    
    
			    
