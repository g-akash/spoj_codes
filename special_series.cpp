#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

#define ull unsigned long long int

int main()
{
	ull t;
	cin>>t;
	for(ull i=0;i<t;i++)
	{
		ull n;
		cin>>n;
		n=n%6;
		if(n==0)cout<<0<<endl;
		if(n==1)cout<<1<<endl;
		if(n==2)cout<<4<<endl;
		if(n==3)cout<<6<<endl;
		if(n==4)cout<<5<<endl;
		if(n==5)cout<<2<<endl;
	}
}
		
