#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<unsigned long long int> v;
	v.resize(1000005);
	v[0]=1;
	v[1]=1;
	for(unsigned long long int i=2;i<1000003;i++)
	{
		v[i]=(v[i-1]+(i-1)*v[i-2])%1000000007;
	}
	unsigned long long int n;
	cin>>n;
	for(unsigned long long int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		cout<<v[a]<<endl;
	}
}
