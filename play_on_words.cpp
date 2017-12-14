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


void print_ans(bool ans)
{
	if(ans)
	{
		cout<<"Ordering is possible."<<endl;
	}
	else
	{
		cout<<"The door cannot be opened."<<endl;
	}
	return ;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int ans = 1;
		int n;
		cin>>n;
		string s,s1;
		vi st(26),ed(26);
		vi ss(26);
		int css = 0;
		foi(n)
		{
			cin>>s;
			s1 = s.substr(0,1)+s.substr(s.length()-1,1);
			if(s1[0]==s1[1])
			{
				css+=1;
				ss[(int)s1[0]-97]+=1;
			}
			else
			{
				st[(int)s1[0]-97]+=1;
				ed[(int)s1[1]-97]+=1;
			}
		}

		if(css==n)
		{
			foi(26)
			{
				if(ss[i]!=0&&ss[i]!=n)
				{
					if(ans==1)
					{
						print_ans(false);
						ans=0;
						break;
					}
				}
			}
			if(ans==1)
			{
				print_ans(true);
				ans=0;
			}
		}
		else
		{
			int ds=0,de=0;
			foi(26)
			{
				if(st[i]==ed[i])continue;
				else if(st[i]==ed[i]+1)ds+=1;
				else if(ed[i]==st[i]+1)de+=1;
				else
				{
					if(ans==1)
					{
						print_ans(false);
						ans=0;
						break;
					}
				}
			}
			if(ds==de&&(ds==0||ds==1))
			{
				foi(26)
				{
					if(ss[i]==0)continue;
					if(st[i]==0&&ed[i]==0)
					{
						if(ans==1)
						{
						print_ans(false);
						ans=0;
						break;
						}
					}
				}
				if(ans==1)
				{print_ans(true);ans=0;}

			}
			else
			{
				if(ans==1){print_ans(false);ans=0;}
			}
		}
	}
}