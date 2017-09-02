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
	string s;
	cin>>n>>s;
	vector<string> vec;
	for(int i=0;i<s.length();i++)
	{
		for(int j=1;j<s.length();j++)
		{
			if(i+j-1>=s.length())break;
			int x = i, y = i+j-1;
			string s1 = s.substr(x,y-x+1);
			bool is_palindrome=true;
			for(int k=0;k<=s1.length()/2;k++)
			{
				if(s1[k]!=s1[s1.length()-1-k])
				{
					is_palindrome=false;
					break;
				}
			}
			if(is_palindrome)vec.push_back(s1);

		}
	}
	sort(vec.begin(),vec.end());
	//cout<<vec.size()<<endl;
	ll ans = 1;
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i]!=vec[i-1])ans++;
	}
	cout<<ans<<endl;
}