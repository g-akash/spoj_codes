#include<iostream>
#include<vector>

using namespace std;

#define ll long long int

int main()
{
	int n;
	vector<ll> v,ans;
	cin>>n;
	v.resize(n);
	ans.resize(n);
	ans[0]=-1;
	ans[1]=-1;
	for(int i=0;i<n;i++)cin>>v[i];
	ll a,b,c;
	a=max(v[0],v[1]);
	b=min(v[0],v[1]);
	c=-1000000;
	if(!(n<=2))
	{
		for(int i=2;i<n;i++)
		{
			if(v[i]<=c){}
			else if(v[i]>=c&&v[i]<=b){c=v[i];}
			else if(v[i]>=b&&v[i]<=a){c=b;b=v[i];}
			else if(v[i]>=a){c=b;b=a;a=v[i];}
			ans[i]=a*b*c;
		}
	}
	for(int i=0;i<n;i++)cout<<ans[i]<<endl;
}
