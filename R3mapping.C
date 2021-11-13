#include <cmath>
#include <iostream>
#include <fstream>
using namespace std ;

int main() {
  double rpoints[32]={22.974, 23.406, 23.414, 23.838, 23.845, 24.270, 24.277, 24.701, 24.709, 25.133, 25.141, 25.565, 25.573, 25.997, 26.005, 26.429, 26.437, 26.861, 26.869, 27.293, 27.301, 27.725, 27.733, 28.157, 28.165, 28.589, 28.596, 29.021, 29.028, 29.452, 29.460, 29.857};

  double mm_per_inch = 25.4;
  double step_per_mm = 1000.0/5.0;
  
  ofstream myfile;
  myfile.open("./config/R3_points.txt",std::ofstream::trunc);

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
    
    
			    
