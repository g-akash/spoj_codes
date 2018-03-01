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

vvll facs(100005);

void do_prime_work()
{
	vi prims(100005);
	for(int i=2;i<100005;i++)
	{
		if(prims[i])continue;
		facs[i].pb((ll)i);
		//cout<<i<<endl;
		for(int j=2*i;j<100005;j+=i)
		{
			facs[j].pb((ll)i);
			prims[j]=1;
		}
	}
	return;
}

ll get_ans(vll rounds)
{
	//do_prime_work();
	//cout<<"within get_ans"<<endl;
	//foi(rounds.size())cout<<rounds[i]<<" ";cout<<endl;
	umm(ll,ll) um;
	foi(rounds.size())
	{
		ll curr = rounds[i];
		ll num = curr;
		foj(facs[curr].size())
		{
			ll fac = facs[curr][j];
			ll cnt = 0;
			
			while(num%fac==0)
			{
				//cout<<curr<<" "<<fac<<endl;
				cnt+=1;
				num/=fac;
			}
			if(um.find(fac)==um.end())um[fac]=cnt;
			else
			{
				um[fac]=max(um[fac],cnt);
			}
		}
	}

	ll ans = 1;
	umm(ll,ll)::iterator it;
	it = um.begin();
	while(it!=um.end())
	{
		foi(it->second)
		{
			ans*=(it->first);
			ans%=1000000007;
		}
		it++;
	}
	return ans;

}

int main()
{
	do_prime_work();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vi vec(n+1);
		foi1(n)cin>>vec[i];
		vi visited(n+1);
		foi(n+1)visited[i]=0;
		vll rounds(0);
		foi1(n)
		{
			if(visited[i])continue;
			visited[i]=1;
			int nex = vec[i];
			int count = 1;
			while(!visited[nex])
			{
				visited[nex]=1;
				nex=vec[nex];
				count+=1;
			}
			rounds.pb((ll)count);
		}
		cout<<get_ans(rounds)<<endl;
	}
}