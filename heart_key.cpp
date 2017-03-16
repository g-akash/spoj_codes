#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
#define foi(x) for(int i=0;i<x;i++)
#define ull unsigned long long int
#define MOD %1000000007

int main()
{
	int k;
	cin>>k;
	ull a=1,b=1,var;
	foi(k)
	{
		cin>>var;
		var=var MOD;
		a*=var;
		b*=var;
		a=a MOD;
		b=b MOD;
	}
	a-=1;
	a+=1000000007;
	a=a MOD;
	cout<<a<<"/"<<b<<endl;
}