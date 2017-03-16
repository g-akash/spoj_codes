#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

#define ll long long int

string gender(ll n, ll k)
{
	if(n==0)return "Male";
	ll var;
	var=k/2;
	string gen=gender(n-1,var);
	if(gen=="Male"){if(k==2*var)return "Male"; else return "Female";}
	else if(gen=="Female"){if(k==2*var)return "Female"; else return "Male";}
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ll n,k;
		cin>>n>>k;
		cout<<gender(n-1,k-1)<<endl;
	}
}
	
