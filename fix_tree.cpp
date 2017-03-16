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

vi parents,visited;
vvi edges;
int ans=0,curr=1;

bool visit(int x)
{
	//cout<<x<<endl;
	if(visited[x]==curr)
		{

			return true;
		}
	visited[x]=curr;
	foi(edges[x].size())
	{
		if(visit(edges[x][i]))
		{
			ans++;
			edges[x][i]=0;
		}
	}
	return false;
}


int main()
{
	int n;
	cin>>n;
	parents.resize(n+1);
	visited.resize(n+1);
	edges.resize(n+1);
	foi1(n)
	{
		cin>>parents[i];
		if(parents[i]!=i)
		edges[parents[i]].pb(i);
	}
	foi1(n)
	{
		if(!visited[i])
			visit(i);
		curr++;
	}
	foi1(n)parents[i]=0;
	foi1(n)
	{
		foj(edges[i].size())
		{
			if(edges[i][j]!=0)
				parents[edges[i][j]]=i;
		}
	}
	int minp=0;
	foi1(n)
	{
		if(parents[i]==0)
			{
				ans++;
				if(minp==0)
				{
					minp=i;
				}
				parents[i]=minp;
			}
	}
	ans--;
	cout<<ans<<endl;
	foi1(n)cout<<parents[i]<<" ";
	cout<<endl;


}