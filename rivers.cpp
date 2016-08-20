#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define ll long long int

int main()
{
	ll t;
	cin>>t;
	for(ll i=0;i<t;i++)
	{
		ll n,m,q;
		cin>>n>>m>>q;
		n--;m--;
		vector<ll> x,y;
		x.resize(100100);
		y.resize(100100);
		ll a,b;
		for(ll j=0;j<q;j++)
		{
			cin>>a>>b;
			a--;
			b--;
			x[a]=1;
			y[b]=1;
		}
		x[0]=1;
		x[n]=1;
		y[m]=1;
		y[0]=1;
		vector<ll> x1,y1;
		for(ll j=0;j<100100;j++)if(x[j]==1)x1.push_back(j);
		for(ll j=0;j<100100;j++)if(y[j]==1)y1.push_back(j);
		sort(x1.begin(),x1.end());
		sort(y1.begin(),y1.end());
		ll maxl=0,maxb=0,minl=1000000,minb=1000000,var;
		for(ll j=1;j<x1.size();j++){var=x1[j]-x1[j-1];if(var>maxl)maxl=var;if(var!=0&&var<minl)minl=var;}
		for(ll j=1;j<y1.size();j++){var=y1[j]-y1[j-1];if(var>maxb)maxb=var;if(var!=0&&var<minb)minb=var;}
		cout<<(ll)(x1.size()-1)*(ll)(y1.size()-1)<<" "<<minl*minb<<" "<<maxl*maxb<<endl;

	}
}