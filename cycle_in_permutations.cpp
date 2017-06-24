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
	int n;
	cin>>n;
	vi vec(n);
	foi(n)cin>>vec[i];
	vi visited(n);
	vvi ans;
	vi tmp;
	foi(n)
	{
		if(visited[i])continue;
		tmp.resize(0);
		int strt = i;
		tmp.pb(i+1);
		visited[strt]=1;
		int nx = vec[strt];
		while(!visited[nx-1])
		{
			tmp.pb(nx);
			visited[nx-1]=1;
			nx=vec[nx-1];

		}
		tmp.pb(strt+1);
		ans.pb(tmp);
	}
	cout<<ans.size()<<endl;
	foi(ans.size())
	{
		foj(ans[i].size())cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}