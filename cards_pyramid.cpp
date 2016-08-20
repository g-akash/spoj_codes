#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


#define ulli unsigned long long int

int main()
{
	vector<ulli> v;
	v.resize(1000001);
	v[0]=0;
	for(int i=1;i<1000001;i++)
	{
		v[i]=(v[i-1]+(i-1)+i*2)%1000007;
	}
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int var;
		cin>>var;
		cout<<v[var]<<endl;
	}
}