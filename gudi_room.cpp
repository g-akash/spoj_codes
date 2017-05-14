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

int a,h;

string th(string s)
{
	foi(h)
	{
		s=s.substr(s.length()-1)+s.substr(0,s.length()-1);
	}
	return s;
}

string ta(string s)
{
	//cout<<s<<" taaaa"<<endl;
	for(int i=1;i<s.length();i+=2)
	{
		int tmp = int(s[i])-48;
		tmp=(tmp+a)%10;
		s=s.substr(0,i)+to_string(tmp)+s.substr(i+1);
	}
	//cout<<s<<" kk"<<endl;
	return s;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s,var;
		
		cin>>s>>a>>h;
		map<string,int> m;
		stack<string> st;
		st.push(s);
		while(!st.empty())
		{
			var=st.top();
			st.pop();
			if(m.find(var)!=m.end())continue;
			m[var]=1;
			s=th(var);
			//cout<<s<<" th"<<endl;
			st.push(s);
			s=ta(var);
			st.push(s);
			//cout<<s<<" ta"<<endl;
		}
		cout<<(m.begin())->first<<endl;
	}
}