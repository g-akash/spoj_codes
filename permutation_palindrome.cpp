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
		vvi vec(26);
		for(int i=0;i<s.length();i++)
		{
			int chr = int(s[i])-97;
			vec[chr].pb(i+1);
		}
		int oddcount=0;
		foi(26)
		{
			if(vec[i].size()%2==1)oddcount+=1;
		}
		if(oddcount!=(int)(s.length())%2)
		{
			cout<<-1<<endl;
		}
		else
		{
			vi ans(s.length());
			int beg=0,ed=s.length()-1;
			int mid;
			if(oddcount==1)
			{
				mid = int(s.length())/2;
			}
			foi(26)
			{
				int str=0;
				if(vec[i].size()%2==1)
				{
					ans[mid]=vec[i][0];
					str=1;
				}
				for(int j=str;j<vec[i].size();j+=2)
				{
					ans[beg]=vec[i][j];
					ans[ed]=vec[i][j+1];
					beg+=1;
					ed-=1;
				}
			}
			foi(ans.size())cout<<ans[i]<<" ";cout<<endl;
		}
	}
}