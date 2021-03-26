#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calcFunc(double x){
    return (pow(x,3)-(2.0*(pow(x,2.0)))+5.0);
}

double simpsons38rule(double x0, double xlast){
    double h = (xlast-x0)/3.0;
    double x1 = x0 + h;
    double x2 = x0 + (2.0*h);
    double fun =((3.0*h)/8.0);
    fun = fun* (calcFunc(x0)+ (3.0*(calcFunc(x1) )) + (3.0*(calcFunc(x2))) + calcFunc(xlast) );
    return fun;
}
int main()
{
    printf("fonksiyonun direkt yerine koyuldugunda [0-3] arasindaki integral degeri: %f\n",simpsons38rule(0.0,3.0));

    double n=0.0;
    printf("0-3 araligini bolmek istediginiz n degerini giriniz: ");
    scanf("%lf",&n);

    double xsfr =0.0;
    double xson =3.0;

    double artis = (xson - xsfr)/n;
    double i;
    double top=0.0;

    double x0=0.0;
    double x3=0.0;
    printf("\n");
    for (i=x0; i<xson; i= i+artis){
        x0 = i;
        x3 = i+artis;
        if(x3 >= xson){
            break;
        }
        top = top + simpsons38rule(x0,x3);
        printf("x0: %f, x3:  %f, func: %f, top: %f\n ",x0,x3,simpsons38rule(x0,x3), top);

    }
    printf("\n sonuc olarak %f kere bolunerek cikan integralin toplam sonucu: %f\n",n,top);

    return 0;
}
