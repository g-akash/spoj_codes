#include <iostream>
#include <vector>
//#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>

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
	ll n,k;

	vi vec;
	vi ans(1000000);


	cin>>n;
	vec.resize(n);
	foi(n)cin>>vec[i];
	int ml=-1,curr=1;
	ans[0]=1;
	for(int i=1;i<1000000;i++)
	{
		ans[i]=0;
		for(int j=0;j<n;j++)
		{
			if(i>=vec[j])
			{
				if(ans[i-vec[j]]==1)
				{
					ans[i]=1;
					break;
				}
			}
			else break;
		}
		if(ans[i]==1)curr++;
		else curr=0;
		if(curr>=vec[0])
		{
			ml=i;
			break;
		}
	}

	int var;
	cin>>k;
	foi(k)
	{
		cin>>var;
		if(var<=ml)
		{
			if(ans[var]==1)cout<<"TAK"<<endl;
			else cout<<"NIE"<<endl;
		}
		else
		{
			cout<<"TAK"<<endl;
		}
	}

}