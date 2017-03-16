#include <iostream>
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


int main()
{
	ll a,b;
	cin>>a>>b;
	unordered_map<ll,ll> par;
	par[a]=0;
	ll curr=a;
	queue<ll> q;
	q.push(curr);
	while(!q.empty())
	{
		if(q.front()==b)break;
		curr=q.front();
		q.pop();
		if(curr>b)continue;
		par[2*curr]=curr;
		par[10*curr+1]=curr;
		q.push(2*curr);
		q.push(10*curr+1);
	}
	if(q.empty())
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		curr=q.front();
		vector<ll> ans;
		while(curr!=0)
		{
			//cout<<curr<<" ";
			ans.pb(curr);
			curr=par[curr];
		}
		for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";cout<<endl;
	}
}