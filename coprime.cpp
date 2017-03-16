#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

#define ull unsigned long long int 


ull gcd(ull a,ull b)
{
	if(a==b)return a;
	if(a<=0)return b;
	if(b<=0)return a;
	return gcd(b,a%b);
}

int main()
{
	int t;
	cin>>t;
	unsigned long long int n,m;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		m=n/2;
		while(m>=1)
		{
			if(gcd(n,m)==1){cout<<m<<endl;break;}
			m--;
		}

	}
}