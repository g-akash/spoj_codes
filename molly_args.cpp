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



int main()
{
	ll a=10000,b=50000,c=1e14;
	ll ba=b-a,ab=a*b;
	vector<ll> vec(100005);
	for(ll i=0;i<100005;++i){
		ll var=i-20000;
		vec[i]=c+6*ab*var;
		var*=(i-20000);
		vec[i]+=3*var*ba;
		var*=(i-20000);
		vec[i]+=-2*var;
	}
	int t;
	cin>>t;
	while(t--)
	{
		ll x;
		cin>>x;
		foi(vec.size())
		{
			if(vec[i]>=x)
			{
				cout<<i-20000<<endl;
				break;
			}
		}
	}
}