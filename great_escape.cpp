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


int main()
{
	int n,m,a,b;
	cin>>n>>m;
	vvi edges(n+1);
	vi sp(n+1);
	foi(n+1)sp[i]=100000000;
	foi(m)
	{
		cin>>a>>b;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	int s,t;
	cin>>s>>t;
	queue<int> q;
	sp[s]=0;
	q.push(s);
	int ans=0;
	vi inqueue(n+1);
	while(!q.empty())
	{
		int var = q.front();
		q.pop();
		inqueue[var]=0;
		if(var==t)
		{
			ans=sp[t];
			break;
		}
		for(int i=0;i<edges[var].size();i++)
		{
			if(sp[edges[var][i]]>sp[var]+1)
			{
				sp[edges[var][i]]=sp[var]+1;
				if(!inqueue[edges[var][i]])
				{
					q.push(edges[var][i]);
					inqueue[edges[var][i]]=1;
				}
			}
		}

	}
	cout<<ans<<endl;
}