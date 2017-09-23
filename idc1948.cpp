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


int dist_num(int n)
{
	int ans = 0;
	while(n!=0)
	{
		ans=ans*10+9;
		n/=10;
	}
	return ans;
}


vi prims;

void make_primes()
{
	vi primes(10000);
	for(int i=2;i<10000;i++)
	{
		if(primes[i])continue;
		prims.pb(i);
		for(int j=2*i;j<10000;j+=i)
		{
			primes[j]=1;
		}
	}
	return;
}


int main()
{
	int t;
	cin>>t;
	make_primes();
	while(t--)
	{
		int n;
		cin>>n;
		int num2 = dist_num(n);
		num2-=2*n;
		num2 = abs(num2);
		int ans = 0;
		for(int i=0;i<prims.size();i++)
		{
			if(num2%prims[i]==0)
			{
				ans=prims[i];
				break;
			}
		}
		if(num2==1)
		{
			cout<<-1<<endl;
			continue;
		}
		if(ans)
		{
			cout<<ans<<endl;
		}
		else
		{
			cout<<num2<<endl;
		}
		
	}
}