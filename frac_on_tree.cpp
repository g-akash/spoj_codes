#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


#define ll long long int

int main()
{
	ll n;
	cin>>n;
	while(n!=0)
	{
		vector<ll> pos;
		ll var;
		var=n;
		while(var!=0)
		{
			pos.push_back(var);
			var/=2;
		}
		int a=1,b=1;
		for(int i=pos.size()-1;i>=1;i--)
		{
			if(pos[i]*2==pos[i-1]){b+=a;}
			else a+=b;
		}
		cout<<a<<"/"<<b<<endl;
		cin>>n;
	}
}