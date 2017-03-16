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
	ll us,ps,bo;
	cin>>us>>ps>>bo;
	ll n,cst;
	cin>>n;
	string s;
	vector<ll> u,p;
	foi(n)
	{
		cin>>cst>>s;
		if(s=="USB")
		{
			u.pb(cst);
		}
		else p.pb(cst);
	}
	sort(u.begin(),u.end());
	sort(p.begin(),p.end());
	ll ans=0;
	ll x=0,y=0;
	bool bus=x<u.size(),bps=y<p.size(),bbo=true;
	while(bus&&us>0)
	{
		ans+=u[x];
		x++;
		us--;
		if(x>=u.size())bus=false;
	}
	while(bps&&ps>0)
	{
		ans+=p[y];
		y++;
		ps--;
		if(y>=p.size())bps=false;
	}
	while((bps||bus)&&bo>0)
	{
		if(bps&&bus)
		{
			if(u[x]<=p[y])
			{
				ans+=u[x];
				x++;
			}else
			{
				ans+=p[y];
				y++;
			}
		}
		else if(bps)
		{
			ans+=p[y];
			y++;
		}
		else
		{
			ans+=u[x];
			x++;
		}
		bo--;
		if(x>=u.size())bus=false;
		if(y>=p.size())bps=false;
	}
	cout<<x+y<<" "<<ans<<endl;
}