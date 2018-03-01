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

vll facs;
ll n,a,b,c;

void make_facs()
{
	ll srt = sqrt(n);
	for(int i=1;i<srt;i++)
	{
		if(n%i==0)
		{
			facs.push_back(i);
			facs.push_back(n/i);
		}
	}
	if(n%srt==0)
	{
		facs.push_back(srt);
	}
	sort(facs.begin(),facs.end());
	return;
}

ll get_ans()
{
	ll ans = 0;
	for(int i=0;i<facs.size();i++)
	{
		if(facs[i]<=a)
		{
			ll var = n/facs[i];
			for(int j=0;j<facs.size();j++)
			{
				if(facs[j]<=b&&var%facs[j]==0)
				{
					if(var/facs[j]<=c)
					{
						ans+=1;
					}
				}
			}
		}
	}
	return ans;
}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		facs.resize(0);
		cin>>n>>a>>b>>c;
		make_facs();
		cout<<get_ans()<<endl;

	}
}