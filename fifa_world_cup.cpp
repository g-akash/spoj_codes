#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long int

int main()
{
	ll g,t,a,d;
	cin>>g>>t>>a>>d;
	while(!(g==-1&&t==-1&&a==-1&&d==-1))
	{
		ll games=0;
		games= (t*(t-1))/2;
		games*=g;
		ll tems=a*g+d;
		ll var=1;
		while(var<tems)var*=2;
		ll temsadded=var-tems;
		games+=var-1;
		cout<<g<<"*"<<a<<"/"<<t<<"+"<<d<<"="<<games<<"+"<<temsadded<<endl;
		cin>>g>>t>>a>>d;
	}
}