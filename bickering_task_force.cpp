#include <iostream>
#include <vector>
//#include <unordered_map>
#include <string>
#include <math.h>
//#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <stdio.h>

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
	int n,m,k;
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&k);
	vvi hates(n+1),hts(n+1);
	vi num_hates(n+1);
	vi is_in(n+1);
	foi(n+1)
	{
		hates[i].resize(n+1);
		is_in[i]=true;
	}
	int a,b;
	foi(m)
	{
		scanf("%d",&a);
		scanf("%d",&b);
		if(hates[a][b]==0)
		{
			hts[a].pb(b);
			num_hates[a]++;
		}
		hates[a][b]=1;
		if(hates[b][a]==0)
		{
			hts[b].pb(a);
			num_hates[b]++;
		}
		hates[b][a]=1;
	}
	int ans=n;
	while(ans>0)
	{
		bool did_changed=false;
		for(int i=1;i<=n;i++)
		{
			if(num_hates[i]<k&&is_in[i])
			{
				is_in[i]=false;
				num_hates[i]=0;
				did_changed=true;
				ans--;
				for(int j=0;j<hts[i].size();j++)
				{
					num_hates[hts[i][j]]-=1;
					hates[hts[i][j]][i]=0;
				}

			}
		}


		if(!did_changed)break;
	}
	
	if(ans>0)
	{
		printf("YES\n%d",ans);
	}
	else printf("NO\n");
}