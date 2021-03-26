#include <stdio.h>
#include <stdlib.h>


double sayisalTurevBase( double doty[], int h, int x0){
    double turev = ( (doty[x0+h] - doty[x0] ) / h ) ;
    return turev;
}

double sayisalTurev1(double doty[], int h, int x0){
    double turev =   (4*(doty[x0+h]) ) -(3*(doty[x0])) -(doty[x0+(2*h)])  ;
    turev = turev / (2*h);
    return turev;
}

double sayisalTurev2( double doty[], int h, int x0){
    double turev = (doty[x0+h])  -(doty[x0-h]) ;
    turev = turev / (2*h);
    return turev;
}

double sayisalTurev3(double doty[], int h, int x0){
    double turev =  (3*(doty[x0]) ) -(4*(doty[x0-h])) +(doty[x0-(2*h)]) ;
    turev = turev / (2*h);
    return turev;
}

int main()
{
    double doty[4] = {-4, 5, 26, 65};
    int arraysize = 4;


    int h = 1;
    int i =0;

    double turev;

    for (i =0 ; i< arraysize ; i++ ){
        if (i==0){
            printf("for point: %d derivation is: %f \n", i,sayisalTurev1(doty,h,i));
            continue;
        }
        if( i == (arraysize-1)){
            printf("for point: %d derivation is: %f \n", i,sayisalTurev3(doty,h,i));
            continue;
        }
        turev = (doty[i+h] -doty[i-h] )/2*h;
        printf("for point: %d derivation is: %f \n",i ,turev);
    }


    return 0;
}
