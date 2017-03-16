#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()


bool allpos(vi & pos)
{
	foi(pos.size())if(pos[i]<0)return false;
	return true;
}

bool allsam(vvi & ancs, vi & pos)
{
	foi(pos.size())
	{
		if(ancs[i][pos[i]]!=ancs[0][pos[0]])return false;
	}
	return true;
}
vvi ancs;
vi ch,var;
int main()
{
	int n,q;
	cin>>n>>q;
	vi par(n+1,0);
	par[1]=0;
	for(int i=2;i<=n;i++)
	{
		cin>>par[i];
	}
	for(int i=0;i<q;i++)
	{
		int k;
		cin>>k;
		ancs.clear();
		ancs.resize(k);
		var.resize(k);
		ch.resize(0);
		foj(k)cin>>var[j];
		sort(var.begin(),var.end())
		foj(k)
		{
			if(j==0){ch.pb(var[j]);continue;}
			else if(var[j]!=var[j-1])ch.pb(var[j]);
		}
		k=ch.size();
		foj(k)
		{
			ancs[j].pb(ch[j]);
			int nx=ch[j];
			while(nx!=0&&ancs[j].size()<=n)
			{
				ancs[j].pb(nx);
				nx=par[nx];
			}
		}
		bool prnt=false,cont=true;
		foj(k)ch[j]=ancs[j].size()-1;
		while(cont)
		{
		
			
				foj(k)
				{
					ch[j]--;
					if(ch[j]<0)
					{
						cout<<ancs[j][ch[j]+1]<<endl;
						cont=false;
						break;
					}
					else if(ancs[j][ch[j]]!=ancs[0][ch[0]])
					{
						cout<<ancs[j][ch[j]+1]<<endl;
						cont=false;
						break;
					}
				}
			
			
		}
		
		
	}
}