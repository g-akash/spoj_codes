#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

string get_str(vector<bool> vec)
{
	string ans="";
	foi(vec.size())ans+=to_string(vec[i]);
	return ans;
}


int main()
{
	int t;
	cin>>t;
	int var;
	while(t--)
	{
		umm(string,int) um;
		int n,m;
		scanf("%d %d",&n,&m);
		vector<bool> vec(n),nex(n);
		vector<vector<bool> > patterns;
		foi(n){scanf("%d",&var);vec[i]=var;}
		string str;
		str = get_str(vec);
		patterns.pb(vec);
		int count=0;
		if(vec[0]==0)nex[0]=1;
		while(count!=m&&um.find(str)==um.end())
		{
			
			um[str] = count;
			
			if(vec[1])nex[0]=true;
			else nex[0]=false;
			if(vec[n-2])nex[n-1]=true;
			else nex[n-1]=false;
			for(int i=1;i<n-1;i++)
			{
				if(vec[i-1]&&vec[i+1])nex[i]=true;
				else nex[i]=false;
			}
			vec=nex;
			str = get_str(vec);
			patterns.pb(vec);
			count++;
			
			
		}
		//cout<<patterns.size()<<endl;
		//cout<<m<<" "<<count<<" "<<um[str]<<endl;
		if(count==m+1)
		{
			foi(n)
			{
				var = patterns[patterns.size()-1][i];
				printf("%d ",var);
			}
		}
		else
		{
			int pos;
			m-=(um[str]);
			int dv = count-(um[str]);
			//cout<<dv<<endl;
			if(m%(dv)==0)pos = patterns.size()-1;
				else pos = m%(dv)+um[str];
			foi(n)
			{
				var = patterns[pos][i];
				printf("%d ",var);
			}
		}
		printf("\n");

	}
}