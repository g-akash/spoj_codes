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


class city{
public:
	int cit,len;
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vvi edge(n+1);
		int a,b;
		foi(m)
		{
			cin>>a>>b;
			edge[a].pb(b);
			edge[b].pb(a);
		}
		int strt = 1, ed = n;
		city c,var;
		vi ml(n+1);
		foi1(n)ml[i]=10000000;
		ml[1]=0;
		c.cit = 1;
		c.len = 0;
		queue<city> q;
		q.push(c);
		while(!q.empty())
		{
			c=q.front();
			int ct = c.cit,ln = c.len;
			//cout<<ct<<" "<<ln<<endl;
			q.pop();
			if(c.cit==ed)
			{
				cout<<c.len<<endl;
				break;
			}
			for(int i=0;i<edge[ct].size();i++)
			{

				if(ml[edge[ct][i]]>ln+1)
				{
					//cout<<edge[ct][i]<<" add"<<endl;
					var = c;
					var.cit = edge[ct][i];
					var.len+=1;
					q.push(var);
					ml[edge[ct][i]]=ln+1;
				}
			}
		}

	}
}