#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> primes;
	primes.resize(1000001);
	
	primes[1]=1;
	for(int i=2;i<=1000000;i++)primes[i]=0;
	for(int i=2;i<=1000000;i++)
	{
		if(primes[i]==1)continue;
		for(int j=2*i;j<=1000000;j+=i)primes[j]=1;
	}
	for(int i=1;i<=1000000;i++)if(primes[i]==0)cout<<i<<" ";
}
