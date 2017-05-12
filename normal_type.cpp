#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define foi1(n) for(ll i=1;i<=n;i++)
#define foj1(n) for(ll j=1;j<=n;j++)
#define vi vector<ll>
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
	vi vec(n);
	foi(n)cin>>vec[i];
	set<ll> st;
	foi(n)st.insert(vec[i]);
	ll dist = st.size();
	umm(ll,ll) um;
	st.clear();
	ll tot=0,beg=0,curr=0,ans=0,count=0;
	foi(n)
	{
		if(um.find(vec[i])==um.end())
		{
			um[vec[i]]+=1;
			count++;
		}
		else um[vec[i]]+=1;
		while(um[vec[beg]]>1)
		{
			um[vec[beg]]-=1;
			if(um[vec[beg]]==0)
			{
				count--;
				um.erase(vec[beg]);
			}
			beg++;
		}

		if(count==dist)
			{
//				cout<<i-1<<" "<<beg<<endl;
				ans+=(beg+1);
			}
	}
	cout<<ans<<endl;
}