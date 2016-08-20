#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

#define ll long long

int main()
{
	ll int t;
	cin>>t;
	for(ll int i=0;i<t;i++)
	{
		ll int n;
		ll int ans=0,j;
		cin>>n;
		ll int srt=sqrt(n);
		ll int a,b,c,d,e,f;
		for(j=1;j<srt;j++)
		{
			
			a=n/j;
			b=n/(j+1);
			c=a-b;
			d=(c*(b+1+a)*j)/2;
			d+=(j*a);
			ans+=d;
			ans%=1000000007;
			//cout<<j<<" "<<d<<endl;
		}
		//d=0;
		j=srt;
		a=n/j;
		b=j;
		c=(a-b);
		//cout<<a<<" "<<b<<" "<<c<<endl;
		//~ if(a!=b)
		//~ d=(c*(b+1+a)*j)/2;
		//~ else
		d=(c*(b+a+1)*j)/2;
		ans+=d;
		ans%=1000000007;
		//if(b!=a)
		d=(n/j)*j;
		ans+=d;
		ans%=1000000007;
		//cout<<j<<" "<<d<<endl;
		cout<<ans<<endl;
	}
}
