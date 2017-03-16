#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>

using namespace std;


int main()
{
	int t;
	cin>>t;
	double ans=1;
	for(int i=0;i<t;i++)
	{
		double n,r,var=0;
		cin>>n>>r;
		double drama = (n*(n+1.0)*(2.0*n+1.0))/6.0;
		for(double j=1;j<=n;j=j+1)
		{
			var+=((j/r)*((j*j)/drama));
		}
		ans*=var;
	}
	cout<<fixed<<setprecision(4)<<ans<<endl;
}