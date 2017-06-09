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


class node
{
public:
	int val,parent,lchl,rchl;
	string pchl;
	node()
	{
		lchl = 0;
		parent = 1;
		rchl = 0;
	}
};

int main()
{
	int n,q;
	cin>>n>>q;
	vector<node> vec(n+1);
	foi1(n)vec[i].val=i;
	int a,b;
	string x;
	foi1(n-1)
	{
		cin>>a>>b>>x;
		if(x=="L")
		{
			vec[a].lchl = b;
			vec[b].parent = a;
			vec[b].pchl = "L";
		}
		else
		{
			vec[a].rchl = b;
			vec[b].parent = a;
			vec[b].pchl = "R";
		}
		
	}
	
	foi(q)
	{
		
		cin>>a;
		string tmp="";
		
		while(a!=1)
		{
			tmp+=vec[a].pchl;
			a=vec[a].parent;
		}
		int ans=1;
		for(int j=tmp.length()-1;j>=0;j--)
		{
			if(tmp[j]=='R')
			{
				if(vec[ans].lchl==0)
				{
					ans=-1;
					break;
				}
				ans=vec[ans].lchl;
			}
			else
			{
				if(vec[ans].rchl==0)
				{
					ans=-1;
					break;
				}
				ans=vec[ans].rchl;	
			}
			
		}
		cout<<ans<<endl;
	}

}