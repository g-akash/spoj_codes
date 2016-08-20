#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

#define ll long long int

unordered_map<ll,ll> m;

ll coins(ll n)
{
	if(n<=1)return n;
	if(m.find(n)!=m.end())return m[n];
	ll a,b,c,x,y,z;
	a=n/2;b=n/3;c=n/4;
	x=coins(a);y=coins(b);z=coins(c);
	if(x+y+z>=n)m[n]=x+y+z;
	else m[n]=n;
	return m[n];
}
	

int main()
{
	ll n;
	while(cin>>n)
	{
		cout<<coins(n)<<endl;
	}
}
