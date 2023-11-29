#include<stdio.h>
#include<math.h>
void chiadoi(double a, double b, double e, double z){
	double c = (a+b)/2.0;
	z=log(c)-1;
	if(z==0){
		printf("Nghiem can tim = %lf",c);
	}
	else{
		double b1,a1;
		if(z*(log(a)-1)<0){a1=a;b1=c;}
		else{ a1=c;b1=b;
		}
		if(fabs(b1-a1)<e) {
		printf("nghiem can tim la :%.15lf",c);}
		else{ chiadoi(a1,b1,e,z);
		}
		}
	}
	int main()
	{
		double a,b,e,z;
		printf("Nhap e="); scanf("%lf",&e);
		printf("Nhap a="); scanf("%lf",&a);
		
		printf("Nhap b="); scanf("%lf",&b);
		chiadoi(a,b,e,z);
		return 0;
	}
