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


vll prims;

void make_primes()
{
	vi nums(34000000);
	for(int i=2;i<34000000;i++)
	{
		if(nums[i]==1)continue;
		prims.pb((ll)i);
		for(int j=2*i;j<34000000;j+=i)
		{
			nums[j]=1;
		}
	}
}

void do_work(ll var)
{
	for(int i=0;i<prims.size()&&var>1;i++)
	{
		int count=0;
		if(var%prims[i]!=0)continue;
		while(var%prims[i]==0)
		{
			count+=1;
			var/=prims[i];
		}
		cout<<prims[i]<<"^"<<count<<" ";
	}
	if(var!=1)
	{
		cout<<var<<"^"<<1<<" ";
	}
	cout<<endl;
}


int main()
{
	make_primes();
	ll var;
	cin>>var;
	while(var!=0)
	{
		do_work(var);
		cin>>var;
	}
}