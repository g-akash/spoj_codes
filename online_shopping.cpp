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



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vvll prices(n),disc(n),ans(n);
		foi(n)
		{
			prices[i].resize(m);
			disc[i].resize(m);
			ans[i].resize(m);
		}
		foi(n)
		{
			foj(m)cin>>prices[i][j];
		}
		foi(n)
		{
			foj(m)cin>>disc[i][j];
		}
		foi(m)ans[0][i]=prices[0][i];
		foi1(n-1)
		{
			vll tmp = ans[i-1];
			sort(tmp.begin(),tmp.end());
			foj(m)
			{
				ans[i][j]=ans[i-1][j]+max((ll)0,prices[i][j]-disc[i-1][j]);
				ans[i][j]=min(ans[i][j],tmp[0]+prices[i][j]);
			}

		}
		vll tmp = ans[n-1];
		sort(tmp.begin(),tmp.end());
		cout<<tmp[0]<<endl;


	}
}