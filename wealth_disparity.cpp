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


vi wel;
int root;
vvi childs;


vi dowork(int node)
{
	vi ans(2),tmpans;
	ans[0]=0;
	ans[1]=100000000;
	for(int i=0;i<childs[node].size();i++)
	{
		tmpans=dowork(childs[node][i]);
		ans[1]=min(ans[1],tmpans[1]);
		ans[0]=max(ans[0],tmpans[0]);

	}

	ans[0]=max(ans[0],wel[node]-ans[1]);
	ans[1]=min(ans[1],wel[node]);
	return ans;
}


int main()
{
	int n,var;
	cin>>n;
	wel.resize(n+1);
	childs.resize(n+1);
	foi1(n)
	{
		cin>>wel[i];
	}
	foi1(n)
	{
		cin>>var;
		if(var==-1)
		{
			root = i;
		}
		else
		{
			childs[var].pb(i);
		}
	}
	vi ans = dowork(root);
	cout<<ans[0]<<endl;


}