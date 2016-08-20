#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long long int a,b,c;
		scanf("%lld",&a);
		scanf("%lld",&b);
		scanf("%lld",&c);
		printf("%lld\n",a*a-2*b);

	}
}