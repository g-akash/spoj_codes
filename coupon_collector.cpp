#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<double> v;
	v.resize(1004);
	v[1]=1;
	for(double i=2;i<1004.0;i=i+1.0)
	{
		v[i]=v[i-1]+(1/i);
	}
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		double var;
		cin>>var;
		double ans=var*v[var];
		ans*=100;
		ans=round(ans);
		ans/=100;
		cout<<fixed<<setprecision(2)<<ans<<endl;
	}
}