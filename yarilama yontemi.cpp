#include <iostream>
#include <cmath>
#include <iomanip> 
	
using namespace std;

float function(float x){
 return pow(x,3)-7*pow(x,2)+14*x-6;
}

int main() {
  float a, b, p, TOL, FA, FB, FP;
  int NO=10000;
  TOL= 1E-3;
  a=0,b=1;
  int i=1;
  cout <<setw(15)<<"i" <<setw(15)<<"a"<<setw(15)<<"b"<<setw(15)<<"p"<<setw(15)<<"f(p)"<<endl; 
  while(i<NO){
    p=(a+b)/2;
    cout <<setw(15)<<  i << setw(15) ;
    cout <<  a << setw(15) ;
    cout <<  b << setw(15) ;
    cout <<  p << setw(15) ;
    
    cout << function(p)<< endl;

    if(function(p)==0 || ((b-a)/2)<TOL ){
      cout << "FOUND: " << p << endl;
      return 0;
    }
    i = i+1;

    if( (function(a)*function(p))>0 ){
      a=p;
      FA=FP;
    }else{
      b=p;
    }

  }

  cout << "Method failed after NO iterations..";
  return 0;

}
