#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>

using namespace std;
vector<double> returns;

double calc_value(double r)
{
	double mulp=1.0+r;
	double rfac=1.0;
	double ans=0.0;
	for(int i=returns.size()-1;i>=0;i--)
	{
		ans+=returns[i]*rfac;
		rfac*=mulp;
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	for(int testno=0;testno<t;testno++)
	{
		int n;
		cin>>n;
		returns.resize(n+1);
		cin>>returns[0];
		returns[0]*=(-1.0);
		for(int i=1;i<=n;i++)
		{
			cin>>returns[i];
		}
		double x=-1.0,y=1.0;
		while(y-x>.000000000001)
		{
			double mid=(x+y)/2.0;
			if(calc_value(mid)>=0)x=mid;
			else y=mid;
			//cout<<mid<<calc_value(mid)<<endl;
		}
		cout<<"Case #"<<testno+1<<": "<<fixed<<setprecision(12)<<x<<endl;
	}
}