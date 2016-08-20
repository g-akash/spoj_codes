#include<iostream>
#include<stdio.h>
using namespace std;

#define ll long long int

int main()
{
	int t;
	scanf("%d",&t);
	{
		for(int i=0;i<t;i++)
		{
			ll n;
			scanf("%lld",&n);
			ll var = (2*n)/3;
			while(var*3<2*n)var++;
			ll a1= (var*(var-1))/2;
			ll a2 = ((n-var)*(2*(n-var)+2))/2;
			cout<<a1+a2<<endl;

		}
	}
}