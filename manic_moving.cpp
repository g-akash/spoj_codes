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
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define foi1(n) for(ll i=1;i<=n;i++)
#define foj1(n) for(ll j=1;j<=n;j++)
#define vi vector<ll>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()
#define MAX 100000000000

vvi mcosts,edges;
vi finans,load;

ll calc(ll x)
{
	if(x==0)return 0;
	if(x==2)return mcosts[load[0]][load[1]]+mcosts[load[1]][load[2]];
	ll var=0,currval = min(		
		finans[(x-4)/2]+mcosts[load[x-4]][load[x-3]]+mcosts[load[x-3]][load[x-2]]
			+mcosts[load[x-2]][load[x-1]]+mcosts[load[x-1]][load[x]],
		
		finans[(x-4)/2]+mcosts[load[x-4]][load[x-3]]+mcosts[load[x-3]][load[x-1]]
			+mcosts[load[x-1]][load[x-2]]+mcosts[load[x-2]][load[x]]);
	
	ll minval=currval;
	for(ll i=x-4;i>0;i-=2)
	{
		currval=finans[(i-2)/2]+currval
			-mcosts[load[i+3]][load[i+1]]
				-mcosts[load[i]][load[i+1]]
				+mcosts[load[i-2]][load[i-1]]
				+mcosts[load[i+1]][load[i-1]]
				+mcosts[load[i+1]][load[i]]
				+mcosts[load[i]][load[i+3]];
		minval=min(currval,minval);
	}
	return minval;
}


int main()
{
	ll t;
	cin>>t;
	for(ll K=1;K<=t;K++)
	{
		
		ll n,m,k,a,b,g;
		cin>>n>>m>>k;
		finans.resize(k+1);
		vvi edgs(n+1),mincosts(n+1);
		vvi costs(n+1);
		vi loads(2*k+1);
		
		loads[0]=1;
		
		foi(n+1)
		{
			costs[i].resize(n+1);
			mincosts[i].resize(n+1);
		}
		
		foi(n+1)
		{
			foj(costs[i].size())
			{
				costs[i][j]=MAX;
				mincosts[i][j]=MAX;
				if(i==j)mincosts[i][j]=0;
			}
		}
		
		foi(m)
		{
			cin>>a>>b>>g;

			if(g<costs[a][b])
			{
				costs[a][b]=g;
				costs[b][a]=g;
				
			}
			if(costs[a][b]==MAX)
			{
				edgs[a].pb(b);
				edgs[b].pb(a);
			}
		}
		foi(k)
		{
			cin>>loads[2*i+1]>>loads[2*i+2];
			finans[i]=MAX;
		}
		finans[k]=MAX;
		//at this poll first calculate the mincosts.
		for(ll i=1;i<=n;i++)
		{
			foj1(n)if(i!=j)mincosts[i][j]=costs[i][j];
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				for(ll k=1;k<=n;k++)
				{
					mincosts[i][j]=min(mincosts[i][j],mincosts[i][k]+mincosts[k][j]);
				}
			}
		}
		// for(ll i=1;i<=n;i++)
		// {
		// 	foj1(n)cout<<mincosts[i][j]<<" ";cout<<endl;
		// }


		//we assume that mincosts are available at this poll
		
		edges=edgs;
		mcosts=mincosts;
		load=loads;
		
		for(ll i=0;i<loads.size();i+=2)
		{
			finans[i/2]=calc(i);
						
		}
		cout<<"Case #"<<K<<": ";
		if(finans[k]<MAX&&finans[k]>=0)cout<<finans[k]<<endl;
		else cout<<-1<<endl;
	}
}