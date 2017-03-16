#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		double v,ans;
		cin>>v;
		cout<<fixed<<setprecision(10)<<pow(4.0*v,2.0/3.0)*(pow(3,0.5)/2.0)+((6.0*v)/(pow(4.0*v,1.0/3.0)*(pow(3,1.0/2.0)/2.0)))<<endl;
	}
}