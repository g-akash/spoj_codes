#include <iostream>
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

vector<string> vec;
vi num,prims;

void make_prims()
{
	vi var(1000005);
	for(int i=2;i<1000005;i++)
	{
		if(var[i]==1)continue;
		for(int j=2*i;j<1000005;j+=i)
		{
			var[j]=1;
		}
	}
	for(int i=2;i<1000005;i++)
	{
		if(var[i]==0)prims.pb(i);
	}
	return;
}

void fact(int v)
{	
	int x=num[v];
	int var=sqrt(x);
	for(int i=0;i<prims.size()&&prims[i]<=var;i++)
	{
		if(x%prims[i]==0)
			{
				vec[v]+=("k"+to_string(i));
				while(x%prims[i]==0&&x!=0)x/=prims[i];
			}
	}
	if(x!=0)vec[v]+=("k"+to_string(x));
	return;
}


int main()
{
	int n;
	cin>>n;
	vec.resize(n);
	num.resize(n);
	make_prims();
	foi(n)
	{
		vec[i]="";
		cin>>num[i];
	}
	foi(n)
	{
		fact(i);
	}
	sort(vec.begin(),vec.end());
	int mx=1,curr=1;
	foi1(n-1)
	{
		if(vec[i]==vec[i-1])curr++;
		else curr=1;
		mx=max(mx,curr);
	}
	cout<<mx<<endl;


}