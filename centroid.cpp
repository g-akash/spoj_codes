#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()


int n;
vi visited;
vvi vec, neigh;


int visit(int x)
{
	//cout<<x<<endl;
	if(visited[x])return 0;
	int tot=0;
	visited[x]=1;
	int nex=0;
	foi(vec[x].size())
	{
		neigh[x][i]=visit(vec[x][i]);
		tot+=neigh[x][i];
		if(neigh[x][i]==0)
		{
			nex=i;
		}
		//cout<<x<<" "<<vec[x][i]<<" "<<neigh[x][i]<<endl;
		//tot+=neigh[vec[x][i]];
	}
	if(tot+1!=n)
		neigh[x][nex]=(n-tot-1);
		return tot+1;
}	

bool can_be(int x, int y)
{
	int tot=0;
	foi(vec[x].si)
	{
		if(vec[x][i]!=y)tot+=neigh[x][i];
	}
	tot+=1;
	if(tot<=n/2){return true;}
	foi(vec[x].si)
	{
		if(vec[x][i]!=y&&tot-neigh[x][i]<=n/2&&neigh[x][i]<=n/2){return true;}
	}
	return false;
}

bool is_centroid(int x)
{
	foi(vec[x].si)
	{
		if(!can_be(vec[x][i],x))
			return false;
	}
	return true;
}

int main()
{
	cin>>n;
	visited.resize(n+1);
	vec.resize(n+1);
	neigh.resize(n+1);
	int a,b;
	foi(n-1)
	{
		cin>>a>>b;
		vec[a].pb(b);
		neigh[a].pb(0);
		vec[b].pb(a);
		neigh[b].pb(0);
	}
	visit(1);
	
	foi1(n)
	{
		cout<<i<<endl;
		if(is_centroid(i))cout<<"1 ";
		else cout<<"0 ";
	}
	cout<<endl;
}