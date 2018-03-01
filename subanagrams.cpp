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



int main()
{
	int n;
	cin>>n;
	vvi vec(n);
	foi(n)vec[i].resize(26);
	string s;
	foi(n)
	{
		cin>>s;
		for(int j=0;j<s.length();j++)
		{
			vec[i][int(s[j])-97]+=1;
		}
	}
	bool printed = false;
	foi(26)
	{
		int mn = 10000000;
		for(int j=0;j<n;j++)
		{
			mn=min(mn,vec[j][i]);
		}
		foj(mn)
		{
			printed = true;
			cout<<char(i+97);
		}
	}
	if(!printed)cout<<"no such string";
	cout<<endl;
}