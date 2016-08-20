#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<unsigned long long int> v;
	v.resize(10005);
	v[1]=2;
	v[2]=3;
	for(int i=3;i<10005;i++)
		v[i]=v[i-1]+v[i-2];
	int n;
	cin>>n;
	cout<<v[n]<<endl;
}