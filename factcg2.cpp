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
#include <stdio.h>

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
vector<bool> primes(5000005);

void make_primes()
{
	
	for(int i=1;i*i<5000005;i++)
	{
		for(int j=1;j*j<5000005;j++)
		{
			int n = (4*i*i)+(j*j);
			if(n<5000005&&(n%12==1||n%12==5))
				primes[n]=primes[n]^true;
			n = (3*i*i)+(j*j);
			if(n<5000005&&n%12==7)
				primes[n]=primes[n]^true;
			n = (3*i*i)-(j*j);
			if(i>j&&n<5000005&&n%12==11)
				primes[n]=primes[n]^true;
		}
	}
	prims.pb(2);
	prims.pb(3);
	for(int i=2;i<5000005;i++)
	{
		if(primes[i])
		{

			prims.pb(i);
			if(i>10000)continue;
			for(int j=i*i;j<5000005;j+=i*i)
			{

				primes[j]=0;
			}
		}
	}
	return;
}

int main()
{
	make_primes();
	//foi(100)cout<<prims[i]<<" ";
	//cout<<endl;
	vector<string> vs(10000005);
	int n;
	while(scanf("%d",&n))
	{
		int orig = n;
		for(int i=0;i<prims.size()&&n!=1;i++)
		{
			if(primes[n])
			{
				vs[orig]+="x "+to_string(n)+" ";
				n=1;
				break;
			}
			
			while(n%prims[i]==0)
			{
				n/=prims[i];
				vs[orig]+="x "+to_string(prims[i])+" ";
				if(vs[n]!="")
				{
					//vs[orig]+=vs[n];
					break;
				}
			}
		}
		printf("%s\n",("1 "+vs[orig]+vs[n]).c_str());
	}
}