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
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k,tot=0,rsmax=(ll)(-1)*1e12;
		ll lsmax = rsmax,mxsub = rsmax;
		ll t1=rsmax,t2=rsmax;
		cin>>n>>k;
		vll vec(n);
		foi(n){cin>>vec[i];tot+=vec[i];}
		vll rsum(n),lsum(n),msub(n);
		lsum[0]=vec[0];
		lsmax = max(lsmax,lsum[0]);
		msub[0]=vec[0];
		mxsub = msub[0];
		for(int i=1;i<n;i++)
		{
			lsum[i]=lsum[i-1]+vec[i];
			lsmax = max(lsmax,lsum[i]);
			msub[i]=max(msub[i-1]+vec[i],vec[i]);
			mxsub=max(mxsub,msub[i]);
		}
		rsum[n-1]=vec[n-1];
		rsmax = rsum[n-1];
		for(int i=n-2;i>=0;i--)
		{
			rsum[i]=rsum[i+1]+vec[i];
			rsmax = max(rsmax,rsum[i]);
		}
		if(tot>=0&&k>1)
		{
			if(lsmax<0&&rsmax<0)t1=max(lsmax,rsmax);
			else t1 = max((ll)0,lsmax)+max((ll)0,rsmax);
			if(k>=2)t1+=(k-(ll)2)*tot;
		}
		else if(k>1)
		{
			if(lsmax<0&&rsmax<0)t1=max(lsmax,rsmax);
			else t1 = max((ll)0,lsmax)+max((ll)0,rsmax);
		}
		cout<<max(mxsub,t1)<<endl;






	}
}