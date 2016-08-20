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
		double n;
		cin>>n;
		cout<<fixed<<setprecision(11)<<0.5+(((n+1)*(n+2))-2.0)/(4*(n+1)*(n+2))<<endl;
	}
}