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




string get_type(string s)
{
	if(int(s[0])<97)return "error";
	if(s[s.length()-1]=='_')return "error";
	if(s.find("__")<s.length())return "error";
	bool unds = false;
	bool cap = false;
	bool nums = false;
	foi(s.length())
	{
		if(s[i]=='_')unds=true;
		if((int)s[i]<=90)cap=true;
		if((int)s[i]<58)nums = true;
	}
	if(nums) return "error";
	if(cap&&unds)return "error";
	else if(cap)return "Java";
	else return "C++";
}


int main()
{
	string s;
	while(cin>>s)
	{
		string ans = "";
		int unds=0,cap=0;
		string type = get_type(s);
		if(type == "error")
		{
			cout<<"Error!"<<endl;
		}
		else if(type == "C++")
		{
			for(int i=0;i<s.length();i++)
			{
				if(s[i]=='_')
				{
					i+=1;
					if(i<s.length())
					ans+=string(1,char((int)s[i]-32));
				}
				else
				{
					ans+=s.substr(i,1);
				}
			}
			cout<<ans<<endl;
		}
		else if(type == "Java")
		{
			for(int i=0;i<s.length();i++)
			{
				if((int)s[i]<91)
				{
					ans+=("_"+string(1,char((int)s[i]+32)));
				}
				else 
				{
					ans+=s.substr(i,1);
				}
			}
			cout<<ans<<endl;
		}
	}
}