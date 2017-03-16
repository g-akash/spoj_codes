#include <bits/stdc++.h>

using namespace std;


#define ll long long int

int main()
{
	ll n,k,a,b,t;
	cin>>n>>k>>a>>b>>t;
	ll tme=0;
	if(k>=n)
	{
		tme+=k*n;
		n-=n;
	}
	else
	{
		n-=k;
		tme+=k*a;
		if(b*k<=a*k+t)
		{
			tme+=b*n;
			n-=n;
		}
		else
		{
			ll trns=n/k;
			tme+=(trns*(a*k+t));
			n-=(trns*k);
			if(b*n<=a*n+t)
			{
				tme+=b*n;
			}
			else
			{
				tme+=(a*n+t);
			}
		}
	}
	cout<<tme<<endl;
}