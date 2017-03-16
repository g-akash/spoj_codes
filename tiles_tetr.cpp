#include<iostream>
#include<math.h>

using namespace std;

#define ll long long int

ll gcd(ll a, ll b)
{
	if(a==0)return b;
	if(b==0)return a;
	if(a%b==0)return b;
	return gcd(b, a%b);
}

int main()
{
	
	ll x,y;
	cin>>x>>y;
	while(x!=0&&y!=0)
	{
		ll var=gcd(x,y);
		var=(x*y)/var;
		cout<<(var/x)*(var/y)<<endl;
		cin>>x>>y;
	}

}