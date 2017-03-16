#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

#define ull long long int

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ull a,b,c,d,e,f;
		ull x,y,z;
		cin>>x>>y>>z;
		a=x*x+y*(y+2*z);
		//cout<<a<<" hobo"<<endl;
		b=(ull)sqrt(a);
		
		//cout<<a<<" "<<sqrt(a)<<endl;
		if(b*b!=a){cout<<"Not this time."<<endl;continue;}
		b=b*z;
		c=z*x;
		d=(y+2*z);
		if((c+b)%d!=0){cout<<"Not this time."<<endl; continue;}
		if((c+b)/d<=x)cout<<(c+b)/d<<endl;
		else cout<<"Not this time."<<endl;
	}
}