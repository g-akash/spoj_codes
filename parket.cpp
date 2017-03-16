#include<iostream>
#include<math.h>

using namespace std;

#define ll long long int

int main()
{
	ll r,b;
	cin>>r>>b;
	ll a,c,d;
	c=b+r;
	b=(r/2+2);
	
	cout<<((b+(ll)(sqrt(b*b-4*c)))/2)<<" "<<((b-(ll)(sqrt(b*b-4*c)))/2)<<endl;
}