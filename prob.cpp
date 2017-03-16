#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

long long int gcd(long long int a, long long int b)
{
	if(a==0)return b;
	if(b==0)return a;
	if(a%b==0)return b;
	return gcd(b,a%b);
}

int main()
{
	long long int n,k,a,b;
	cin>>n>>k;
	while(k!=-1&&n!=-1)
	{
		if(n<=1||k<=2){a=0;b=1;}
		else if(k%2==0)
		{
			a=(((k-2))*(k))/4;
			b=(n*(n-1))/2;
		}
		else
		{
			a=((k-1)*(k-1))/4;
			b=(n*(n-1))/2;

		}

		if(a==0)cout<<0<<endl;
		else if(a==b)cout<<1<<endl;
		else
		{
			long long int ansi=gcd(a,b);
			cout<<a/ansi<<"/"<<b/ansi<<endl;
		}
		cin>>n>>k;
	}
	
}