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

string s;


ll get_ans(char a, char b, char c)
{
	int count1=0, count2=0, count3=0;
	int ans = 0;
	foi(s.length())
	{
		if(s[i]==b)count2+=1;
		else if(s[i]==c)count3+=1;
		else ans+=(count2+count3);
	}
	count2=0;
	for(int i=s.length()-1;i>=0;i--)
	{
		if(s[i]==a)continue;
		else if(s[i]==b)count2+=1;
		else ans+=count2;
	}
	return ans;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		ll ans = 10000000000;
		ans = min(ans,get_ans('r','g','b'));
		ans = min(ans,get_ans('r','b','g'));
		ans = min(ans,get_ans('g','r','b'));
		ans = min(ans,get_ans('g','b','r'));
		ans = min(ans,get_ans('b','r','g'));
		ans = min(ans,get_ans('b','g','r'));
		cout<<ans<<endl;
	}
}