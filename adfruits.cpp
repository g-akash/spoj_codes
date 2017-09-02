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
#include <string>

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


string s1,s2;
umm(int,string) um;

string LCS(int x, int y)
{
	if(x>=s1.length())return "";
	if(y>=s2.length())return "";
	if(um.find(x*1000+y)!=um.end())return um[x*1000+y];
	if(s1[x]==s2[y]&&s1[x]!=' ')
	{
		string ans = s1.substr(x,1)+LCS(x+1,y+1);
		um[x*1000+y] = ans;
		return ans;
	}
	else
	{
		string ans1 = LCS(x+1,y), ans2 = LCS(x,y+1);
		if(ans1.length()>ans2.length())
		{
			um[x*1000+y] = ans1;
			return ans1;
		}
		else
		{
			um[x*1000+y] = ans2;
			return ans2;
		}
	}
}


string ans;


void add_s1_to_ans(int &x, char ch)
{
	for(int i=x;i<s1.length();i++)
	{
		if(s1[i]==ch)
		{
			ans+=s1.substr(x,i-x);
			x=i+1;
			return;
		}
	}
}


void add_s2_to_ans(int &y, char ch)
{
	for(int i=y;i<s2.length();i++)
	{
		if(s2[i]==ch)
		{
			ans+=s2.substr(y,i-y);
			y=i+1;
			return;
		}
	}
}

int main()
{
	
	while(cin>>s1>>s2)
	{
		transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
		um.clear();
		ans = "";
		string lcs = LCS(0,0);
		int x = 0,y = 0;

		for(int i=0;i<lcs.length();i++)
		{
			add_s1_to_ans(x,lcs[i]);
			add_s2_to_ans(y,lcs[i]);
			ans+=lcs.substr(i,1);
		}
		if(x<s1.length())ans+=s1.substr(x);
		if(y<s2.length())ans+=s2.substr(y);
		cout<<ans<<endl;

	}
}