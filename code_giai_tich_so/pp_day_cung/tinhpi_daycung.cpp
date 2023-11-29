#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x)
{
        // Thay doi ham so o day:
    return tan(x/4)-1;
}
double f1(double x){
	return 1/(4*pow(cos(x/4),2));
}
 double f2(double x){
 	return (sin(x/4))/(8*pow(cos(x/4),3));
 }
int main()
{    int count=0;
    float x,e, a, b,d,x0,x1;
    printf("Nhap e ="); scanf("%f",&e);
    printf("\nNhap khoang nghiem a, b: ");
    scanf("%f%f", &a, &b);
     if(f(a)*f(b)<0&&f1(a)*f1(b)>0&&f2(a)*f2(b)>0){
     	if(f(a)*f2(a)>0){
     		d=a;
     		x0=b;
		 }
		 else{d=b; x0=a;
		 }
		 double max, min, M,m;
		 max=fabs(f1(a)); min=fabs(f1(b));
		 if(max>min){M=max; m=min;
		 }
		 else{
		  m=max; M=min;}
		  double e0=e*m/(M-m);
		  {x1=x0-f(x0)*(x0-d)/(f(x0)-f(d));
		  while (fabs(x1-x0)>=e0){
		  	count++;
		  	x0=x1;
		  	x1=x0-f(x0)*(x0-d)/(f(x0)-f(d));
		  	printf("\n Vong lap thu %d: x=%.16lf", count,x1);
		  }
	 }
	 
    printf("\nNghiem cua phuong trinh x = %.16lf ", x1);}
    return 0;
}
