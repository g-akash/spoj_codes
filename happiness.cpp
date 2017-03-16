#include<iostream>
#include<map>
#include<math.h>


using namespace std;

#define ll long long int

ll count=0;
map<ll,ll> m;

ll happiness(ll n)
{
	ll ans=0;
	if(m.find(n)!=m.end())return -1;

	m[n]=1;
	if(n==1)return count;
	while(n!=0)
	{
		ans+=pow(n%10,2);
		n/=10;
	}
	//cout<<ans<<endl;
	count++;
	return happiness(ans);

}

int main()
{
	ll n;
	cin>>n;
	
	cout<<happiness(n)<<endl;
}