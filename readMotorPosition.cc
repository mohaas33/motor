
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>

#include "serialComm.h"

using namespace std;

int main( int argc, char *argv[])
{

  if ( argc < 2)
    {
      cout << " Usage " << argv[0] << " <serialport>" << endl;
      cout << "   e.g " << argv[0] << " /dev/ttyUSB0" << endl;
      return 1;
    }

  char axis ='X';

  char c;
  while ((c = getopt(argc, argv, "xyzXYZ")) != EOF)
    {
      switch (c) 
	{
	case 'x':
	case 'X':
	  axis='X';
	  ;
	  break;

	case 'y':
	case 'Y':
	  axis='Y';
	  ;
	  break;

	case 'z':
	case 'Z':
	  axis='Z';
	  ;
	  break;

	}
    }


  Communication *tn = new serialComm ( argv[optind]);

  tn->Connect();
  tn->print(axis);
  char astring[12];
  int i;
  int status;

  for ( i = 0; i < 12; i++)
    {
      if ( ( status = tn->readChar(&astring[i], 10) < 0) )
	{
	  //	  cout << "timeout at char " << i << endl;
	  continue;
	}
    }
  //  if (status) return 1;

  //astring[0] = 0; // was astring[i]=0;
  //int val = atoi (astring);
  //cout << val << endl;
  //cout << astring << endl;

  char ss[11];
  i = 0;
  for(i=0; i<12; ++i){
    if(astring[i]=='+' or astring[i]=='-') {
      ss[0] = astring[i];
      break;
    }
  }
  int ii=1;
  for(int newi = i+1; newi<12; newi++){
    ss[ii] = astring[newi];
    ii++;
  }
  cout<< atoi(ss) << endl;

  return 0;

}

