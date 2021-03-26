#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;


int main() {
  ifstream file ("VERI.TXT");
  string line;
  int pos;
  long double aradeger;
  vector <long double> inputs;
  vector <long double> outputs; 

  //getting the values into the inputs and outputs vectors
  //position of the blank = line.find(" ");
  //line's first part, from begin to the blank position = line.substr(0,line.find(" "));
  //line's second part, from blank to the end = line.substr(line.find(" "));
  if (file.is_open())
  {
    while ( getline (file,line) )
    {
      inputs.push_back(atof(line.substr(0,line.find(" ")).c_str()));
      outputs.push_back(atof(line.substr(line.find(" ")).c_str()));
    }
    file.close();

  }
  else{
    cout << "Unable to open file";
  }

  cout << "bulmak istediginiz ara degeri giriniz: ";
  cin  >> aradeger;

  long double sum=0;
  long double pay=1, payda=1;

  for(int i=0 ; i< inputs.size() ; i++){
    pay=1;
    payda=1;
    for(int j=0; j<inputs.size(); j++){
      if(j == i){
        continue;
      }
      pay*=(aradeger-inputs[j]);
      payda*=(inputs[i]-inputs[j]);
    }
    sum+=( (pay/payda)*outputs[i] );
  }
  cout << "bu ara deger icin fonksiyon sonucu: " << sum ;

  return 0; 
}