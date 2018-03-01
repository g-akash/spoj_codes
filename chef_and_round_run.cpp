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
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)cin>>vec[i];
		vector<int> ans(n);
		int fin_ans=0;
		for(int k=0;k<n;k++)
		{
			int i = k;
			if(ans[i]!=0)continue;
			unordered_map<int,int> curr;
			vector<int> st;
			while(true)
			{
				if(ans[i]!=0)
				{
					for(int j=0;j<st.size();j++)
					{
						ans[st[j]]=-1;
					}
					break;
				}
				else if(curr.find(i)!=curr.end())
				{
					bool found = false;
					for(int j=0;j<st.size();j++)
					{
						if(found)
						{
							ans[st[j]]=1;
						}
						else
						{
							if(st[j]==i)
							{
								found=true;
								ans[st[j]]=1;
							}
							else
							{
								ans[st[j]]=-1;
							}
						}
					}
					break;
				}
				else
				{
					st.push_back(i);
					curr[i]=1;
				}
				i=(i+vec[i]+1)%n;
			}
		}
			for(int i=0;i<ans.size();i++)
			{
				if(ans[i]==1)fin_ans+=1;
			}
			cout<<fin_ans<<endl;
	}
}
