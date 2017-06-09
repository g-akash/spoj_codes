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
		int var;
		cin>>var;
		umm(int,ll) um;
		umm(int,ll)::iterator it;
		int srt = sqrt(var);
		for(int i=2;i<=srt&&var!=1;i++)
		{
			while(var%i==0)
			{
				var/=i;
				um[i]+=1;
			}
		}
		if(var!=1)um[var]+=1;
		ll ans = 1;
		it = um.begin();
		while(it!=um.end())
		{
			ans*=(it->second+1);
			it++;
		}
		cout<<ans<<endl;

	}
}