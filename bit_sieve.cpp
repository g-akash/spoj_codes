#include<bits/stdc++.h>

using namespace std;
#define SIZE 80000000



bitset<SIZE> prime;
int primes[6000000];

int main()
{
	prime.flip();
	prime[1]=0;
	int k=1,i,j;
	for(i=2;i<SIZE&&k<5000000;++i)
	{
		if(prime[i]){
		primes[k]=i;
		k++;
		for(j=2*i;j<SIZE;j+=i)
		{
			prime[j]=0;
		}
	}
	}
	int n,var;
	//cout<<primes.size()<<endl;
	/*cin>>n;
	//
	for(i=0;i<n;i++)
	{
		cin>>var;
		cout<<primes[var-1]<<endl;
	}*/
}