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
		string s;
		cin>>s;
		int ans = 0;
		char curr_ch = ':';
		int curr = 0;
		for(int i=0;i<s.length();i++)
		{
			if(curr_ch=='<'||curr_ch=='>')
			{
				if(s[i]=='=')
				{
					continue;
				}
				else
				{
					if(curr_ch==s[i])
					{
						curr+=1;
						ans=max(ans,curr);
					}
					else
					{
						curr=1;
						curr_ch=s[i];
						ans=max(ans,curr);
					}
				}
			}
			else
			{
				if(s[i]=='=')
				{
					continue;
				}
				else
				{
					curr_ch=s[i];
					curr=1;
					ans=max(ans,curr);
				}
			}
		}
		cout<<ans+1<<endl;
	}
}