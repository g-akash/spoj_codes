#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

#define ll long long int
#define modd %12345678901

vector<ll> a11,a12,a21,a22;

void fibbo()
{
	a11[0]=1;a11[1]=1;
	a22[0]=1;a22[1]=0;
	a12[0]=0;a12[1]=1;
	a21[0]=0;a21[1]=1;
	ll x,y,z,w;
	for(int i=2;i<=60;i++)
	{
		x=(a11[i-1]*a11[i-1]+a12[i-1]*a21[i-1])modd;
		y=(a11[i-1]*a21[i-1]+a21[i-1]*a22[i-1])modd;
		z=(a21[i-1]*a11[i-1]+a22[i-1]*a21[i-1])modd;
		w=(a21[i-1]*a12[i-1]+a22[i-1]*a22[i-1])modd;
		a11[i]=x;
		a12[i]=y;
		a21[i]=z;
		a22[i]=w;
	}

}


int main()
{
	a11.resize(61);
	a12.resize(61);
	a21.resize(61);
	a22.resize(61);
	fibbo();
	for(int i=1;i<=60;i++)cout<<a12[i]<<endl;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ll x,y,z,w,a,b,c,d;
		x=1;w=1;
		ll n;
		cin>>n;
		ll var=1;
		for(int i=1;i<=60;i++)
		{
			var=n&0x1;
			if(var==0)continue;
			a=(x*a11[i]+y*a12[i])modd;
			b=(x*a12[i]+y*a22[i])modd;
			c=(z*a11[i]+w*a21[i])modd;
			d=(z*a12[i]+w*a22[i])modd;
			x=a;y=b;z=c;w=d;
		}
		cout<<y<<endl;


	}


}