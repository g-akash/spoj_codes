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


int n;
string s;





int main()
{
	
	cin>>n>>s;
	vi v0,v1,v2;
	v0.resize(n+5);
	v1.resize(n+5);
	v2.resize(n+5);
	v0[0]=0;
	if(s[0]==s[1])v1[0]=0;
	else v1[0]=2;
	for(int i=2;i<n;i++)
	{
		for(int j=0;j<=i/2;j++)
		{
			int a0=1000000,a1=1000000,a2=1000000;
			if(j>=1)a0=v1[j-1]+1;
			if(j>=1&&s[j]==s[i-j])a1=v0[j-1];
			a2=v1[j]+1;
			v2[j]=min(a1,min(a0,a2));
		}
		v0=v1;
		v1=v2;

	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=0;j<=i/2;j++)
		{
			int a0=1000000,a1=1000000,a2=1000000;
			a0=v1[j]+1;
			if(s[j]==s[i-j])a1=v0[j];
			a2=v1[j+1]+1;
			v2[j]=min(a1,min(a0,a2));
		}
		v0=v1;
		v1=v2;
	}
	cout<<v2[0]<<endl;
}