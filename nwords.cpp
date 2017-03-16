#include<iostream>
#include<vector>

using namespace std;

#define ll long long int

int main()
{
	vector<ll> a0,a1,a2;
	a0.resize(24);
	a1.resize(24);
	a2.resize(24);
	a0[1]=1;
	a1[1]=1;
	a2[1]=1;
	for(int i=2;i<24;i++)
	{
		a0[i]=a1[i-1]+a0[i-1];
		a1[i]=a0[i-1]+a2[i-1]+a1[i-1];
		a2[i]=a1[i-1]+a2[i-1];
	}
	int n;
	cin>>n;
	cout<<a0[n]+a1[n]+a2[n]<<endl;
}