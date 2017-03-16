#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


bool cond(ll c, ll d, ll l)
{
	if(l%4!=0)return true;
	if(l<d*4)return true;
	if(l>d*4+c*4)return true;
	ll og=max((ll)0,c-2*d);
	if(l<d*4+og*4)return true;
	return false;
}

int main()
{
	ll c,d,l,n;
	cin>>n;
	foi(n)
	{
		cin>>c>>d>>l;
		if(cond(c,d,l))cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
}