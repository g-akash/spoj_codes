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


int sum_squares(int x)
{
	int ans = 0;
	while(x!=0)
	{
		int var = x%10;
		x/=10;
		ans+=(var*var);
	}
	return ans;
}


int main()
{
	ll a,b,var,oa,ob;
	cin>>a>>b;
	oa = a;
	ob = b;
	while(!(a==0&&b==0))
	{
		//cout<<a<<" "<<b<<endl;
		umm(ll,ll) m1,m2;
		m1.clear();
		m2.clear();
		ll ans = 100000000;
		m1[a]=1;
		
		while(true)
		{
			var = sum_squares(a);
			
			if(m1.find(var)!=m1.end())break;
			m1[var]=m1[a]+1;
			a=var;
		}
		m2[b]=1;
		
		while(true)
		{
			
			var = sum_squares(b);
			
			if(m2.find(var)!=m2.end())break;
			m2[var]=m2[b]+1;
			b=var;
		}
		umm(ll,ll)::iterator it = m2.begin();
		while(it!=m2.end())
		{
			if(m1.find(it->first)!=m1.end())
			{
				if(it->second+m1[it->first]<ans)
				{
					ans = it->second+m1[it->first];
				}
			}
			it++;
		}
		if(ans==100000000)ans=0;
		cout<<oa<<" "<<ob<<" "<<ans<<endl;
		cin>>a>>b;
		oa = a;
		ob = b;

	}
}