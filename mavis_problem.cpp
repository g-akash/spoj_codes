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

int bit[100009];


void insert(int val)
{
	int add = 1;
	int ind = val;
	while(ind<100009)
	{
		bit[ind]+=add;
		ind+=(ind&-ind);
	}
	return;
}

int get_ans(int ind)
{
	int ans  = 0;
	while(ind>0)
	{
		ans+=bit[ind];
		ind-=(ind&-ind);
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	vi vec(n);
	foi(n)
	{
		cin>>vec[i];
	}
	//int ans = 0;
	vi ans;
	for(int i=n-1;i>=0;i--)
	{
		ans.pb(get_ans(vec[i]-1));
		insert(vec[i]);
	}
	for(int i=n-1;i>=0;i--)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	//cout<<ans<<endl;

}