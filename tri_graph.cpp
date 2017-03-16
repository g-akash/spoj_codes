#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define ll long long int

int main()
{
	ll n,t=0;
	cin>>n;
	while(n!=0){
	vector<ll> a,b,c;
	a.resize(n);b.resize(n);c.resize(n);
	ll x;
	cin>>x;
	a[0]=1000000000;
	cin>>x;
	b[0]=x;
	cin>>x;
	c[0]=b[0]+x;
	for(int i=1;i<n;i++)
	{
		cin>>x;
		a[i]=x+min(a[i-1],b[i-1]);
		cin>>x;
		b[i]=x+min(min(a[i-1],a[i]),min(b[i-1],c[i-1]));
		cin>>x;
		c[i]=x+min(b[i-1],min(c[i-1],b[i]));
	}
	cout<<t+1<<". "<<b[n-1]<<endl;
	cin>>n;
	t++;
}
}