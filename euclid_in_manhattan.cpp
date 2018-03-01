#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()



int main()
{
	ll n;
	cin>>n;
	ll x,y;
	umm(ll,ll) umx,umy,um;
	ll a,b;
	vll vx(n),vy(n);
	foi(n)
	{
		cin>>a>>b;
		vx[i]=a;
		vy[i]=b;
		umx[a]+=1;
		umy[b]+=1;
		um[a*(ll)10000000000+b]+=1;
	}
	ll ans=0;
	foi(n)
	{
		ll tmp = 0;
		tmp+=umx[vx[i]];
		tmp+=umy[vy[i]];
		tmp-=(um[vx[i]*(ll)10000000000+vy[i]]);
		tmp-=1;
		ans+=tmp;
	}
	cout<<ans/2<<endl;
	
}
