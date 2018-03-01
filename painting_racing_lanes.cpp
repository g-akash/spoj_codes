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
		vvi vec(10);
		foi(10)
		{
			vec[i].resize(501);
		}
		int q,s,e,l;
		cin>>q;
		foi(q)
		{
			cin>>s>>e>>l;
			for(int j=s;j<=e;j++)
			{
				vec[l][j]=1;
			}
		}
		int ans = 500;
		for(int i=1;i<=500;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(vec[j][i]==vec[j+1][i]&&vec[j][i]==1)
				{
					ans-=1;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
}