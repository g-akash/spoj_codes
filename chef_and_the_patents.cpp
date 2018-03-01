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
		ll n,m,x,k;
		cin>>n>>m>>x>>k;
		string s;
		cin>>s;
		ll e=0,o=0;
		foi(s.length())
		{
			if(s[i]=='E')e+=1;
			else o+=1;
		}
		ll tot = 0;
		foi1(m)
		{
			if(i%2==1)
			{
				if(o>=x){tot+=x;o-=x;}
				else {tot+=o;o-=o;}
			}
			else
			{
				if(e>=x){tot+=x;e-=x;}
				else {tot+=e;e-=e;}
			}
		}
		if(tot>=n)cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}