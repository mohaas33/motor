#include <cmath>
#include <iostream>
#include <fstream>
using namespace std ;

int main() {
  double rpoints[32]={16.197, 16.599, 16.607, 17.000, 17.008, 17.402, 17.410, 17.804, 17.812, 18.206, 18.214, 18.608, 18.616, 19.010, 19.018, 19.412, 19.419, 19.813, 19.821, 20.215, 20.223, 20.617, 20.625, 21.019, 21.027, 21.421, 21.429, 21.823, 21.831, 22.224, 22.232, 22.634};

  double mm_per_inch = 25.4;
  double step_per_mm = 1000.0/5.0;
  
  ofstream myfile;
  myfile.open("./config/R2_points.txt",std::ofstream::trunc);

  double darc = 0.25; // inches
  double phi0 = 0.26; // radians 
  for(int w = 0; w < 32; w+=2){
    double rmid = (rpoints[w]+rpoints[w+1])/2.0;
    double dphi = darc/rmid;
    if(w % 2 == 0){
      for(double p=-phi0; p<phi0; p+=dphi){
	double x = (rmid*cos(p))*mm_per_inch*step_per_mm;
	double y = (rmid*sin(p))*mm_per_inch*step_per_mm;
	myfile << round(x) << " " << round(-y) << "\n";
      }
    }
    else {
      for(double p=phi0; p>-phi0; p-=dphi){
	double x = (rmid*cos(p))*mm_per_inch*step_per_mm;
	double y = (rmid*sin(p))*mm_per_inch*step_per_mm;
	myfile << round(x) << " " << round(-y) << "\n";
      }
    }
  }

  myfile.close();
  
  return 0;
  
}
    
    
			    
