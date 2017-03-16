#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int main()
{
	ll n;
	cin>>n;
	vector<ll> vec(n);
	vector<ll> ev(n),od(n),eve(n),ode(n);
	ll sum=0;
	foi(n)
	{
		cin>>vec[i];
	}
	sum=vec[0];
	ev[0]=0;od[0]=0;
	if(sum%2==0)ev[0]=1;
	else od[0]=1;
	foi1(n-1)
	{
		sum+=vec[i];
		if(sum%2==0)
		{
			ev[i]=ev[i-1]+1;
			od[i]=od[i-1];
		}
		else
		{
			ev[i]=ev[i-1];
			od[i]=od[i-1]+1;
		}

	}
	sum=vec[n-1];
	eve[n-1]=0;ode[n-1]=0;
	if(sum%2==0)eve[n-1]=1;
	else ode[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		sum+=vec[i];
		if(sum%2==0)
		{
			eve[i]=eve[i+1]+1;
			ode[i]=ode[i+1];
		}
		else
		{
			eve[i]=eve[i+1];
			ode[i]=ode[i+1]+1;
		}
	}
	ll ans=0;
	sum=0;
	foi(n-1)
	{
		sum+=vec[i];
		//cout<<ans<<" ";
		ll v1=ev[i],v2=od[i],v3=eve[i+1],v4=ode[i+1];

		if(sum%2==0)ans+=(((v1))*((((v3)*(v3+1))/2)+((v4*(v4-1))/2)));
		else if(sum%2==1)ans+=((((v2-1)))*((((v3)*(v3+1))/2)+((v4*(v4-1))/2)));
		ans%=1000000007;
		
	}	
	cout<<ans<<endl;
}