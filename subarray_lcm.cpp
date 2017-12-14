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


vvi facs(1000005);
vi primes(1000005);
vi last_loc(1000005);
void make_primes()
{
	primes[0]=1;
	primes[1]=1;
	for(int i=2;i<1000005;i++)
	{
		if(primes[i])continue;
		facs[i].pb(i);
		for(int j=2*i;j<1000005;j+=i)
		{
			facs[j].pb(i);
			primes[j]=1;
		}
	}
}


int main()
{
	make_primes();
	int t;
	cin>>t;
	while(t--)
	{
		foi(1000005){
			last_loc[i]=0;
		}
		int n;
		cin>>n;
		vi arr(n+1);
		foi1(n)cin>>arr[i];
		int ans = 0,curr=0;
		foi1(n)
		{
			int val2=1000000;
			for(int j=0;j<facs[arr[i]].size();j++)
			{
				val2 = min(val2,i-last_loc[facs[arr[i]][j]]);
				last_loc[facs[arr[i]][j]]=i;
			}
			curr = min(curr+1,val2);
			ans=max(ans,curr);
		}
		if(ans<=1)cout<<-1<<endl;
		else cout<<ans<<endl;
	}

}