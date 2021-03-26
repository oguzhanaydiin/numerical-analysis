#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;

float function(float x){
 return (pow(x,3)-7*pow(x,2)+14*x-6);
}

float functionderiv(float x){
 return (3*pow(x,2)-14*x+14);
}

int main() {
  float a, b, p, p0, TOL;
  int NO=10000;
  TOL= 1E-3;
  a=0,b=1;
  p0 = 0.5;
  int i=1;
  cout << setw(15) <<"i" << setw(15) << "p"<<setw(15) << "f(p)"<<endl;
  while(i<NO){
    p= p0 - (function(p0)/functionderiv(p0));
    cout << setw(15) << i ;
    cout << setw(15) << p ;
    cout << setw(15) << function(p) <<endl;

    if( abs(p-p0) < TOL ){
      cout << "FOUND: " << p << endl;
      return 0;
    }
    i = i+1;

    p0=p;

  }

  cout << "Method failed after NO iterations..";
  return 0;

}

