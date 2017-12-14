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


int wrongSolver(std::vector <unsigned int> a) {
	int n = a.size();
	std::vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	unsigned int mn = prefSum[0] + sufSum[0];
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	return where;
}


int main()
{
	ll t;
	cin>>t;
	//cout<<t<<endl;
	ll mxval =  (ll)1<<32;
	while(t--)
	{
		ll curr_sum = 0;
		ll n;
		cin>>n;
		ll pos=0,val=0;
		for(ll i=0;i<n;i++)
		{
			if(curr_sum+(ll)200000+(n-i-(ll)1)>=mxval)
			{
				pos = i;
				ll var = mxval-(n-i-(ll)1)-curr_sum;
				// if(var%(ll)2==(ll)0)val=var/(ll)2;
				// else val = var/(ll)2+(ll)1;
				break;
			}
			else
			{
				curr_sum+=(ll)100000;
			}
		}
		vector<unsigned int>  vals(n);
		//cout<<n<<endl;
		// cout<<(curr_sum+val+val+(n-pos-1))%mxval<<" "<<(curr_sum+1+val+(n-pos-1))%mxval<<endl;
		// cout<<(curr_sum+val+val+(n-pos-1))<<" "<<(curr_sum+1+val+(n-pos-1))<<endl;
		for(ll i=0;i<=pos;i++){cout<<100000<<" ";}
			//cout<<val<<" ";
		for(ll i=pos+1;i<n;i++){cout<<1<<" ";}cout<<endl;
		//cout<<pos+1<<" "<<wrongSolver(vals)<<endl;

	}
}