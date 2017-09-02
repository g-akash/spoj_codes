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

umm(int,int) um;


void remove_from_map(int x)
{
	um[x]-=1;
	if(um[x]==0)um.erase(x);
	return;
}

void times_served(int x)
{
	vi ans(0);
	for(int i=x;i<x+120;i+=30)
	{
		if(um.find(i)!=um.end())
		{
			ans.pb(i);
		}
		else break;
	}
	foi(ans.size())
	{
		remove_from_map(ans[i]);
	}
	return;
}





int main()
{
	int n;
	cin>>n;
	
	vi vec(n);
	foi(n)
	{
		scanf("%d",&vec[i]);
		um[vec[i]]+=1;
	}
	sort(vec.begin(),vec.end());
	int ans=0;
	foi(n)
	{
		if(um.find(vec[i])==um.end())continue;
		ans+=1;
		times_served(vec[i]);
		
	}
	cout<<ans<<endl;
}