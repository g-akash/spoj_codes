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


bool all_nines(string s)
{
	foi(s.length())
	{
		if(s[i]!='9')return false;
	}
	return true;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s1;
		string ans="";
		cin>>s1;
		int n = (int)(s1.size());
		if(all_nines(s1))
		{
			ans = "1";
			string s2(s1.length()-1,'0');
			ans+=s2;
			ans+="1";
			cout<<ans<<endl;
			continue;
		}
		else
		{
			vector<char> s(s1.length());
			foi(s1.length())s[i]=s1[i];
			bool is_first = true,is_eq = true;
			for(int i=n/2-1;i>=0;i--)
			{
				if(s[i]<s[n-1-i])
				{
					is_first=false;
				}
				if(s[i]!=s[n-1-i])
				{
					is_eq=false;
					break;
				}

			}
			if(!is_eq&&is_first)
			{
				foi(n/2)
				{
					s[n-1-i]=s[i];
				}
			}
			else
			{
				for(int i=n/2-!(n&1);i>=0;i--)
				{
					if(s[i]<'9')
					{
						for(int j=i+1;j<=n/2-!(n&1);j++)s[j]=s[n-1-j]='0';
						s[i]++;
						while(i>=0)
						{
							s[n-1-i]=s[i];
							i--;
						}
						break;
					}
				}
			}
			foi(s.size())cout<<s[i];cout<<endl;
		}
	}
}