#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
double fx (double x,int n,double a){
    return pow(x,n)-a;
}
int main()
{
    double a,f0;
    int n;
    cout<<"Nhap vao gia tri cua n: "; 
    cin>>n;
    cout<<"Nhap vao gia tri cua a: ";
    cin>>a;
    double c,e;
    cout<<"epsilon e= ";
    cin>>e;
    f0=fx(0,n,a);
    if(n%2==0)
    {
        double p = 0, q = 1+a;
        while ((q-p)>e)
        {
            c = (p+q)/2;
            double fc = fx(c,n,a);
            if (fc==0) break;
            else if(fc<0) p=c;
            else q=c;
        }
        std :: cout<< std::setprecision(16)<<"Can bac "<<n<<" cua "<<a<<" la:"<<c<<" va "<<-1*c<<endl;
    }
    else
    {
        double p=0,q;
        if(f0>0) q=-1-a;
        else q=1+a;
        while ((q-p)>e)
        {
            c = (p+q)/2;
            double fc = fx(c,n,a);
            if (fc==0) break;
            else if(fc<0) p=c;
            else q=c;
        }
        std :: cout<< std::setprecision(16)<<"Can bac "<<n<<" cua "<<a<<" la:"<<c<<endl;
    }
    return 0;
}