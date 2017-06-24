#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int main()
{
	ll n;
	cin>>n;
	vll a(n),b(n);
	foi(n)
	{
		cin>>a[i];
	}
	foi(n)
	{
		cin>>b[i];
	}
	vll bsuml(n),bsumr(n),asuml(n),asumr(n);
	bsumr[n-1]=b[n-1];
	bsuml[0]=b[0];
	asuml[0]=a[0];
	asumr[n-1]=a[n-1];
	foi1(n-1)
	{

		bsuml[i]=bsuml[i-1]+b[i];
		bsumr[n-i-1] = bsumr[n-i]+b[n-i-1];
		asuml[i]=bsuml[i-1]+a[i];
		asumr[n-i-1] = bsumr[n-i]+a[n-i-1];
	}
	vll aminl(n),amaxr(n);
	aminl[0]=-asuml[0]+b[0];
	amaxr[n-1]=asumr[n-1];
	foi1(n-1)
	{
		aminl[i]=min(aminl[i-1],asuml[i]+b[i]-2*a[i]);
		amaxr[n-i-1] = max(amaxr[n-i],asumr[n-i-1]);
	}
	ll ans=0;
	foi(n)
	{
		ans=max(ans,a[i]);
		//cout<<ans<<" fir "<<i<<endl;
	}
	//ans = max(ans,asuml[0]+amaxr[1]);
	foi(n-1)
	{
		ans=max(ans,asuml[i]+amaxr[i+1]);
		//cout<<ans<<" sec "<<i<<endl;
	}
	foi1(n-1)
	{
		ans=max(ans,asuml[i]-aminl[i-1]);
		//cout<<asuml[i]<<" "<<aminl[i-1]<<endl;
		//cout<<ans<<" thi "<<i<<endl;
	}
	cout<<ans<<endl;
	


}