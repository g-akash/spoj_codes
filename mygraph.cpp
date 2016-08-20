#include<iostream>
#include<math.h>

using namespace std;

#define ll long long int

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ll n,q;
		cin>>n>>q;
		ll ans,k,quo;
		quo=n/(q-1);
		k=n%(q-1);
		ans=(k*((quo*(quo+1))/2))+((q-1-k)*((quo*(quo-1))/2));
		cout<<ans<<endl;
	}
}
