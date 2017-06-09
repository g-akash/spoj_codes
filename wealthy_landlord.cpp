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
	ll x[1001][1001];
	bool y [1001][1001];
	foi(1001)foj(1001){y[i][j]=false;x[i][j]=-1;}
	ll n,x1,y1,x2,y2,c;
	cin>>n;
	foi(n)
	{
		cin>>x1>>y1>>x2>>y2>>c;
		for(int j=x1;j<=x2;j++)
		{
			for(int k=y1;k<=y2;k++)
			{
				if(x[j][k]==-1)
				{
					x[j][k]=c;
				}
				else
				{
					x[j][k]+=c;
					y[j][k]=true;
				}
			}
		}
	}
	ll ans=0;
	foi1(1000)
	{
		foj1(1000)
		{
			if(y[i][j])ans+=x[i][j];
		}
	}
	cout<<ans<<endl;	
}