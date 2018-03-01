#include <iostream>
#include <vector>
//#include <unordered_map>
#include <string>
#include <math.h>
//#include <map>
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

class node
{
public:
	ll n,p;
	node(ll a, ll b)
	{
		n=a;
		p=b;
	}
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m,s,e;
		cin>>n>>m>>s>>e;
		vvll edges(n+1);
		vll visited(n+1);
		foi(n+1)visited[i]=100000000;
		ll a,b;
		foi(m)
		{
			cin>>a>>b;
			edges[a].pb(b);
			edges[b].pb(a);

		}
		queue<node> q;
		node nd(s,0), tmp(s,0);
		q.push(nd);
		bool ans = false;
		ll path = 0;
		tmp = q.front();
		q.pop();
		for(int i=0;i<edges[tmp.n].size();i++)
		{
			if(visited[edges[tmp.n][i]]>tmp.p+(ll)1)
			{
				node nd1(edges[tmp.n][i],tmp.p+(ll)1);
				q.push(nd1);
			}
		}
		while(!q.empty())
		{
			tmp = q.front();
			q.pop();
			if(tmp.n==e)
			{
				path = tmp.p;
				ans=true;
				break;
			}
			visited[tmp.n]=tmp.p;
			for(int i=0;i<edges[tmp.n].size();i++)
			{
				if(visited[edges[tmp.n][i]]>tmp.p+(ll)1)
				{
					node nd1(edges[tmp.n][i],tmp.p+(ll)1);
					q.push(nd1);
				}
			}
		}
		if(ans&&s!=e)
		{
			if(s!=e)cout<<"YES "<<max(path-1,(ll)0)<<endl;
			else cout<<"YES "<<0<<endl;
		}
		else 
		{
			cout<<"NO"<<endl;
		}
	}
}