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
	ll n,m,v1,v2,v3,v4;
	cin>>n>>m;
	ll mat[n][m];
	foi(n)
	foj(m)
	cin>>mat[i][j];
	cin>>v1>>v2>>v3>>v4;
	ll rmax=0,cmax=0;
	foi(n)
	{
		ll nop=0,mk=0,ad=0;
		foj(m)
		{
			nop+=abs(mat[i][j]);
			mk+=abs(v2);
			ad+=abs(mat[i][j]+v1);
		}
		rmax+=max(nop,max(mk,ad));
	}
	foj(m)
	{
		ll nop=0,mk=0,ad=0;
		foi(n)
		{
			nop+=abs(mat[i][j]);
			mk+=abs(v4);
			ad+=abs(mat[i][j]+v3);
		}
		cmax+=max(nop,max(mk,ad));
	}
	cout<<(rmax>cmax?rmax:cmax)<<endl;
}