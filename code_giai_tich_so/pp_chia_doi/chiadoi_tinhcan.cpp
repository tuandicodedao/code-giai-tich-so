#include<stdio.h>
#include<math.h>
void chiadoi(double a, double b, double e, double z, int n){
	double c = (a+b)/2.0;
	z=pow(c,1/n);
	if(z==0){
		printf("Nghiem can tim = %lf",c);
	}
	else{
		double b1,a1;
		if(z*(pow(a,1/n)<0)){a1=a;b1=c;}
		else{ a1=c;b1=b;
		}
		if(fabs(b1-a1)<e) {
		printf("nghiem can tim la :%.15lf",c);}
		else{ chiadoi(a1,b1,e,z,n);
		}
		}
	}
	int main()
	{
		int n;
		double a,b,e,z;
		printf("Nhap e="); scanf("%lf",&e);
		printf("Nhap n="); scanf("%d",&n);
		printf("Nhap a="); scanf("%lf",&a);
		
		printf("Nhap b="); scanf("%lf",&b);
		chiadoi(a,b,e,z,n);
		return 0;
	}
