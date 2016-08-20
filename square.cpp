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
		double s1,ans=0;
		cin>>s1;
		ans=0.5+0.5*(1-(2.0/3.0)*(1/sqrt(s1/2.0)));
		cout<<fixed<<setprecision(6)<<ans<<endl;
	}
}