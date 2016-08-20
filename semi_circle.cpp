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
		double r;
		cin>>r;
		cout<<fixed<<setprecision(2)<<"Case "<<i+1<<": "<<4.0*r*r+0.25<<endl;
	}
}