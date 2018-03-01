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


vi primes;

void make_primes()
{

	primes.resize(1000005);
	primes[0]=1;
	primes[1]=1;
	for(int i=2;i<1000005;i++)
	{
		if(primes[i])continue;
		for(int j=2*i;j<1000005;j+=i)
		{
			primes[j]=1;
		}

	}
	return;
}


int main()
{
	make_primes();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=2;i<n;i++)
		{
			if(primes[i]==primes[n-i]&&primes[i]==0)
			{
				cout<<i<<" "<<n-i<<endl;
				break;
			}
		}
	}
}
