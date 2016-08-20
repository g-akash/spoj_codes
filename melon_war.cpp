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
		float x,y;
		cin>>x>>y;
		if(x*9.806>y*y)
		{
			cout<<"Scenario #"<<i+1<<": "<<-1<<endl; continue;
		}
		cout<<fixed<<setprecision(2)<<"Scenario #"<<i+1<<": "<<180.0/(2.0*acos(0.0))*.5*(asin((x*9.806)/(y*y)))<<endl;
	}
}