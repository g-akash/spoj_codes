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


int get_ans(int a, int b)
{
	if(a<b)return 0;
	if(a==b)return 1;
	int ans = 1;
	for(int i=1;i<=a;i++)ans*=i;
		for(int i=1;i<=b;i++)ans/=i;
			for(int i=1;i<=a-b;i++)ans/=i;

	return ans;
}

int main()
{
	int n,c;
	cin>>n>>c;
	string s;
	vi vec;
	foi(c)
	{
		cin>>s;
		int f=0,la=53;
		foi(9)
		{	int curr = 0;
			if(s[f]=='0')curr+=1;
			if(s[f+1]=='0')curr+=1;
			if(s[f+2]=='0')curr+=1;
			if(s[f+3]=='0')curr+=1;
			if(s[la]=='0')curr+=1;
			if(s[la-1]=='0')curr+=1;
			f+=4;
			la-=2;
			vec.pb(curr);
		}
	}
	int ans = 0;
	foi(vec.size())
	{
		ans+=get_ans(vec[i],n);
	}
	cout<<ans<<endl;
}