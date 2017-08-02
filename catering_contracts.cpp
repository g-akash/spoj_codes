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


int n;
vi traf;
vvi edges;
vi vol_in,vol_ex;


int get_traffic(int node, int parent, bool incl)
{
	if(incl)
	{
		if(vol_in[node]!=-1)return vol_in[node];
		int ans1=0,ans2=0;
		for(int i=0;i<edges[node].size();i++)
		{
			if(edges[node][i]==parent)continue;
			ans1 += get_traffic(edges[node][i],node,false);
			ans2 += get_traffic(edges[node][i],node,true);
		}
		ans1+=traf[node];
		vol_in[node]=max(ans1,ans2);
		return vol_in[node];

	}
	else
	{
		if(vol_ex[node]!=-1)return vol_ex[node];
		int ans=0;
		for(int i=0;i<edges[node].size();i++)
		{
			if(edges[node][i]==parent)continue;
			ans += get_traffic(edges[node][i],node,true);
		}
		vol_ex[node]=ans;
		return ans;
	}
}



int main()
{

	cin>>n;
	traf.resize(n);
	vol_in.resize(n);
	vol_ex.resize(n);
	foi(n)
	{
		cin>>traf[i];
		vol_in[i]=-1;
		vol_ex[i]=-1;
	}
	edges.resize(n);
	int a,b;
	foi(n-1)
	{
		cin>>a>>b;
		a--;b--;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	int ans1 = get_traffic(0,-1,true);
	int ans2 = get_traffic(0,-1,false);
	cout<<max(ans1,ans2)<<endl;

}