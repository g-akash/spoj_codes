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


bool isprime(int x)
{
	bool prime = true;
	for(int i=2;i<x;i++)
	{
		if(x%i==0)return false;
	}
	//cout<<x<<endl;
	return true;
}
vi vec;

string getval(char ch)
{
	int val = int(ch);
	string ans;
	if(val<=vec[0])
	{
		ans=string(1,char(vec[0]));
		return ans;
	}
	for(int i=1;i<vec.size();i++)
	{
		if(val<=vec[i]&&val>=vec[i-1])
		{
			if(vec[i]-val<val-vec[i-1])
			{
				ans=string(1,char(vec[i]));
				return ans;
			}
			else
			{
				ans=string(1,char(vec[i-1]));
				return ans;
			}
		}
	}
	ans=string(1,vec[vec.size()-1]);
	return ans;
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=2;i<256;i++)if(isprime(i)&&((i>=65&&i<=90)||(i>=97&&i<=122))){vec.push_back(i);}
	while(t--)
	{
		string s,ans="";
		int n;
		cin>>n;
		cin>>s;
		foi(s.length())
		{
			string var = getval(s[i]);
			//cout<<var<<endl;
			ans=ans+var;
		}
		//cout<<"kk"<<endl;
		cout<<ans<<endl;
	}
}