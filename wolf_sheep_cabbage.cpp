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
		int n,m,a,b;
		cin>>n>>m;
		int isol = n;
		vi iso(n+1);
		vi edg(n+1);
		foi(m)
		{
			cin>>a>>b;
			if(iso[a]==0)
			{
				iso[a]=1;
				isol-=1;
			}
			if(iso[b]==0)
			{
				iso[b]=1;
				isol-=1;
			}
			edg[a]+=1;
			edg[b]+=1;
		}
		if(m>=3)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			string ans = "NO";
			foi1(n)if(edg[i]==m)ans="YES";
			cout<<ans<<endl;
		}
	}
}