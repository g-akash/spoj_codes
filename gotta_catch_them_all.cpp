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

vi vec;

void get_fac()
{
	for(int i=1;i<vec.size();i++)
	{
		for(int j=i;j<vec.size();j+=i)
		{
			vec[j]+=1;
		}
	}
	return;
}

int main()
{
	int n,t;
	cin>>n>>t;
	vec.resize(t+1);
	get_fac();
	vi res;
	res.pb(-1);
	foi1(vec.size()-1)
	{
		res.pb(vec[i]);
	}
	res.pb(100000000);
	//cout<<"kk"<<endl;
	sort(res.begin(),res.end());
	//foi(res.size())cout<<res[i]<<" ";cout<<endl;
	foi(n)
	{
		int var;
		cin>>var;
		var = vec[var];
		int x=0,y=res.size()-1;
		while(y-x>1)
		{
			int mid=(x+y)/2;
			if(res[mid]>=var)y=mid;
			else x=mid;
		}
		cout<<x<<endl;
	}
}