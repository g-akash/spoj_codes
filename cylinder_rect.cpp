#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>

using namespace std;

#define pi 3.141592653589

int main()
{
	double b,l;
	cin>>b>>l;
	while(!(b==0&&l==0))
	{
		double v1,v2,v3,r;
		if(b/2.0<=l/(2.0*(1+pi)))
		{
			r=b/2.0;
			v1=r*pi*r*b;
		}
		else 
		{
			r=l/(2.0*(1+pi));
			v1=r*pi*r*b;
		}

		//r = min(b/2.0,l/(2.0*(1+pi)));
		//cout<<r<<endl;
		//v1 = 2.0*pi*r*b;
		//cout<<r<<" ";
		if(b/(2.0*pi)<=l/(2.0))
		{
			r=b/(2.0*pi);
			v2=r*pi*r*(l-2.0*r);
		}
		else
		{
			r=l/(2.0*(1));
			v2=r*pi*r*(l-2.0*r);
		}
		if(l/4.0<=b/(2.0*pi))
		{
			r=l/(4.0);
			v2=r*pi*r*(l-2.0*r);
		}
		//cout<<r<<endl;
		//cout<<v1<<" "<<v2<<endl;
		cout<<fixed<<setprecision(3)<<max(v1,v2)<<endl;
		cin>>b>>l;
	}

}