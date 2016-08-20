#include<iostream>
#include<algorithm>

using namespace std;

#define ll long long int

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ll t1,tl,sum;
		cin>>t1>>tl>>sum;
		ll n=(2*sum)/(t1+tl);
		ll d= (tl-t1)/(n-5);
		ll a=t1-2*d;
		cout<<n<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<a<<" ";
			a+=d;
		}
		cout<<endl;

	}
}

