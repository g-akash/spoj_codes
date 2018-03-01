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


vi st,ed;

vector<char> vec;
umm(int,int) um;

bool does_satisfy(int a, int b)
{
	for(int i=0;i<st.size();i++)
	{
		if(st[i]>a&&ed[i]>=b&&st[i]<=b)return false;
		else if(st[i]<=a&&ed[i]>=a&&ed[i]<b)return false;
	}
	if((b-a+1)%2==1)return false;
	return true;
}


void solve(int a, int b)
{
	if(a>=b)return;
	int val = a*10000+b;
	//if(um.find(val)!=um.end())return;
	bool cansolve = false;
	for(int i=a+1;i<=b;i++)
	{
		if(does_satisfy(a,i))
		{
			cansolve=true;
			vec[a]='(';
			vec[i]=')';
			solve(a+1,i-1);
			solve(i+1,b);
			break;
		}
	}
	if(!cansolve)
	{
		vec[a]='(';
		vec[b]=')';
		solve(a+1,b-1);
	}
	//um[val]=1;
	return;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vec.resize(n);
		um.clear();
		st.resize(k);
		ed.resize(k);
		foi(k)cin>>st[i]>>ed[i];
		solve(0,n-1);
		char ch = '(';
		foi(n)if(vec[i]=='('||vec[i]==')')cout<<vec[i];
		else {cout<<ch;if(ch=='(')ch=')';else ch='(';}
		cout<<endl;
	}
}