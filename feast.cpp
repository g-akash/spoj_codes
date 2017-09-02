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

ll s,n;
vll tmp;
umm(ll,ll) um;

ll num_ways(ll a, ll b)
{
	if(a>=tmp.size())
	{
		if(b==0)return 1;
		else return 0;
	}
	if(b==0)return 1;
	if(b<0)return 0;
	ll val = b*1000+a;
	if(um.find(val)!=um.end())return um[val];
	ll ans=0;
	ans+=num_ways(a+1,b);
	ans+=num_ways(a+1,b-tmp[a]);
	um[val] = ans;
	return ans;
}


int main()
{
	int t;
	cin>>t;
	int cas=1;
	while(t--)
	{
		
		cin>>s>>n;
		vll val(n),num(n);
		ll mxnum=0,ans=0;
		foi(n)
		{
			cin>>val[i]>>num[i];
			mxnum=max(mxnum,num[i]);
		}
		for(ll i=1;i<=mxnum;i++)
		{
			ll tmpsum = s/i;
			if(tmpsum*i!=s)continue;
			tmp.clear();
			for(ll j=0;j<n;j++)
			{
				if(num[j]>=i&&val[j]<=tmpsum)
				{
					tmp.pb(val[j]);
				}
			}
			um.clear();

			ans+=num_ways(0,tmpsum);
			//cout<<tmpsum<<" "<<ans<<" "<<tmp.size()<<endl;

		}
		cout<<"Case "<<cas<<": "<<ans<<endl;
		cas++;
	}
}