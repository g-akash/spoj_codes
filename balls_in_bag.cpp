#include<iostream>
#include<math.h>
#include<iomanip>


using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a,b;
		cin>>a>>b;
		if(b%2==0)cout<<fixed<<setprecision(6)<<0.0<<endl;
		else cout<<fixed<<setprecision(6)<<1.0<<endl;
	}
}