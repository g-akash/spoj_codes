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
		int n;
		cin>>n;
		vi votes(n+1);
		int totalVotes = 0;
		bool ispossible = true;
		vi haveVotes,rest;
		foi1(n)
		{
			cin>>votes[i];
			totalVotes+=votes[i];
			if(votes[i]==n)
			{
				ispossible = false;
			}
			if(votes[i]>0)
			{
				haveVotes.push_back(i);
			}
			else
			{
				rest.push_back(i);
			}
		}
		if(totalVotes!=n)
		{
			ispossible = false;
		}
		if(!ispossible)
		{
			cout<<"-1"<<endl;
			continue;
		}
		//foi(haveVotes.size())cout<<haveVotes[i]<<" ";cout<<endl;
		vi ans(n+1);
		for(int i=0;i<haveVotes.size();i++)
		{
			ans[haveVotes[i]]=haveVotes[(i+1)%int(haveVotes.size())];
			votes[haveVotes[(i+1)%int(haveVotes.size())]]-=1;
		}
		int curr=0;
		for(int i=0;i<rest.size();i++)
		{
			while(curr<haveVotes.size()&&votes[haveVotes[curr]]==0)curr++;
			if(curr==haveVotes.size()){break;}
			ans[rest[i]]=haveVotes[curr];
			votes[haveVotes[curr]]-=1;
		}
		foi1(n)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
		
		
	}
}
