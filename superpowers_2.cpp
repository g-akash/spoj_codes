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


ull makebin(ull x)
{
	ull ans = 0;
	ull curr = 1;
	while(x>0)
	{
		if(x%2==1)ans=ans+curr;
		curr*=10;
		x/=2;
	}
	return ans;
}


ull calc_pow(ull a, ull b)
{
	ull curr = a;
	ull ans = 1;
	while(b>0)
	{
		if(b%2==1)ans*=curr;
		curr=curr*curr;
		ans%=1000000007;
		curr%=1000000007;
		b/=2;
	}
	return ans;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ull n;
		cin>>n;
		ull bin_2 = makebin(n);
		//cout<<bin_2<<endl;
		ull pw = calc_pow((ull)2,bin_2);
		pw = pw*pw;
		pw%=1000000007;
		cout<<pw<<endl;
	}
}