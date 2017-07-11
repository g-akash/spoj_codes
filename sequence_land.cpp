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

int n,k;

vvi ids;

vvi rels;
vi visited;


bool match(int i, int j)
{
	
	int count=0,x=0,y=0;
	while(x<ids[i].size()&&y<ids[j].size())
	{
		if(ids[i][x]==ids[j][y])
		{
			count++;
			x++;
			y++;
			continue;
		}
		else if(ids[i][x]<ids[j][y])
		{
			x++;
			continue;
		}
		else
		{
			y++;
		}
		
	}
	if(count>=k)return true;
	return false;
}

int get_ans(int x)
{
	
	if(visited[x])return 0;
	visited[x]=1;
	int ans=1;
	for(int i=0;i<rels[x].size();i++)
	{
		ans+=get_ans(rels[x][i]);
	}
	return ans;
}

int main()
{
	cin>>n>>k;
	int num,var;
	ids.resize(n);
	rels.resize(n);
	visited.resize(n);
	foi(n)
	{
		cin>>num;
		foj(num)
		{
			cin>>var;
			ids[i].pb(var);
		}
		sort(ids[i].begin(),ids[i].end());
	}
	foi(n)
	{
		for(int j=i+1;j<n;j++)
		{
			if(match(i,j))
			{
				rels[i].pb(j);
				rels[j].pb(i);
			}
			
		}
	}
	
	cout<<get_ans(0)<<endl;

}