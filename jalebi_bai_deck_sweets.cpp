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
	int t;
	cin>>t;
	while(t--)
	{
		string s,t;
		cin>>s>>t;
		string s1="",t1="";
		s1+=s.substr(0,1);
		for(int i=1;i<s.length();i++)
		{
			if(s[i]!=s[i-1])
			{
				s1+=s.substr(i,1);
			}
		}
		t1+=t.substr(0,1);
		for(int i=1;i<t.length();i++)
		{
			if(t[i]!=t[i-1])
			{
				t1+=t.substr(i,1);
			}
		}
		if(s1==t1)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}