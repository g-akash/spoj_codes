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
	int n;
	cin>>n;
	vector<vector<ull> > rels(n);
	vector<string> vecs;
	foi(n)
	{
		string s;
		cin>>s;
		vecs.pb(s);
		for(int j=0;j<n;j+=64)
		{
			ull var=0;

			for(int k=j;k<j+64&&k<n;k++)
			{
				if(s[k]=='1')var=var*2+1;
				else var*=2;
			}
			rels[i].pb(var);
		}
	}
	int ans = 0;
	foi(n)
	{
		for(int j=i+1;j<n;j++)
		{
			int tmp = 0;
			for(int k=0;k<rels[i].size();k++)
			{
				if((rels[i][k]&rels[j][k])!=0)tmp=2;
			}
			if(vecs[i][j]!='1')ans+=tmp;
		}
	}
	cout<<ans<<endl;
}