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
#include <iomanip>

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

vi prims;

void make_primes()
{
	prims.resize(1000005);
	vi primes(1000005);
	primes[1]=1;
	for(int i=2;i<1000005;i++)
	{
		if(primes[i])continue;
		for(int j=2*i;j<1000005;j+=i)
		{
			primes[j]=1;
		}
	}
	for(int i=1;i<1000005;i++)
	{
		prims[i]=prims[i-1];
		if(primes[i]==0)
		{
			//cout<<i<<endl;
			prims[i]+=1;
		}
	}
}


int main()
{
	make_primes();
	//cout<<prims[1000]<<endl;
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int num = prims[b]-prims[a-1];
		int tot = (b-a+1);
		cout<<fixed<<setprecision(6)<<double(num)/double(tot)<<endl;
	}
}