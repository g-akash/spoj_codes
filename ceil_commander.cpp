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


vvi edges;
string marker;
vector<char> ans;
vi visited;


bool dowork(int node, int pos, int diff)
{
	if(visited[node])return true;
	visited[node]=1;
	ans[node]=marker[pos];
	pos+=diff;
	if(pos==marker.length())
	{
		pos-=1;
		diff=-1;
	}
	else if(pos==0)
	{
		return false;
	}
	bool t_ans=true;
	for(int i=0;i<edges[node].size();i++)
	{
		t_ans=t_ans&&dowork(edges[node][i],pos,diff);
	}
	return t_ans;
}


int main()
{
	int n;
	cin>>n;
	edges.resize(n+1);
	ans.resize(n+1);
	visited.resize(n+1);
	int a,b;
	foi(n-1)
	{
		cin>>a>>b;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	// make the string here

	int start=0;
	foi1(n)
	{
		if(edges[i].size()==1)
		{
			start=i;
			break;
		}
	}

	for(int i=1;i<26;i++)
	{
		for(int j=i;j>0;j--)
		{
			string str(1,char(91-j));// = string(char(91-j))
			marker+=str;
		}
	}
	marker+="A";

	if(dowork(start,0,1))
	{
		foi1(n)cout<<ans[i]<<" ";
		cout<<endl;
	}
	else
	{
		cout<<"Impossible"<<endl;
	}

}