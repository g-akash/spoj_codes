#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include <unistd.h>

using namespace std;

#define ll long long int

ll extended_euclid(ll a, ll b)
{
	ll r0,r1,r2,s0,s1,s2,t0,t1,t2,q;
	r0=a;r1=b;s0=1;s1=0;t0=0;t1=1;
	while(r1!=1)
	{
		q=r0/r1;
		//cout<<r1<<" "<<s1<<" "<<t1<<" "<<q<<endl;
		//sleep(1);
		
		r2=r0-q*r1;s2=s0-q*s1;t2=t0-q*t1;
		r0=r1;s0=s1;t0=t1;
		r1=r2;s1=s2;t1=t2;
	}
	//cout<<s1<<" "<<t1<<endl;
	return t1;
}
	

int main()
{
	//cout<<extended_euclid(240,46)<<endl;
	ll t;
	cin>>t;
	for(ll i=0;i<t;i++){
	ll n,p;
	cin>>n>>p;
	if(n>=p){cout<<0<<endl;continue;}
	ll frm=1,srm=1;
	for(ll j=n+1;j<p;j++)
	{
		frm*=j;
		frm%=p;
	}
	//cout<<frm<<endl;
	srm=extended_euclid(p,frm);
	//cout<<srm<<endl;
	srm=(srm*(p-1))%p;
	while(srm<0)srm+=p;
	while(srm>=p)srm-=p;
	cout<<srm<<endl;
}
}
