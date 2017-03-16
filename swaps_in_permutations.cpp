#include <iostream>
#include <stdio.h>
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


vi visited;


class num
{
public:
	int ind,val;
};
vector<num> vec;
vector<vector<int> > edges,conn;


void get_conn(int a, int b)
{
	if(visited[a])return;
	visited[a]=1;
	conn[b].pb(a);
	foi(edges[a].size())
	{
		if(!visited[vec[edges[a][i]].ind])
		get_conn(vec[edges[a][i]].ind,b);
	}
	return;
}

int main()
{
	int n,m,a,b;
	cin>>n>>m;
	vec.resize(n+1);
	edges.resize(n+1);
	conn.resize(n+1);
	visited.resize(n+1);
	num var;
	foi(n)
	{
		//cin>>a;
		scanf("%d",&a);
		var.ind=i+1;
		var.val=a;
		vec[i+1]=var;
	}
	foi(m)
	{
		//cin>>a>>b;
		scanf("%d%d",&a,&b);
		edges[a].pb(b);
		edges[b].pb(a);
	}
	foi1(n)
	{
		if(visited[i])continue;
		get_conn(i,i);
	}
	foi1(n)
	{
		if(conn[i].size()==0)continue;
		vector<int> index(conn[i].size()),vals(conn[i].size());
		foj(conn[i].size())
		{
			index[j]=(vec[conn[i][j]].ind);
			vals[j]=(vec[conn[i][j]].val);
		}
		sort(vals.begin(),vals.end());
		sort(index.begin(),index.end());
		foi(vals.size())
		{
			vec[index[i]].val=vals[vals.size()-1-i];
		}
	}
	//foi1(n)cout<<vec[i].val<<" ";cout<<endl;
	foi1(n)printf("%d ",vec[i].val);printf("\n");
	

}