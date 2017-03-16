#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<unsigned long long int> v;
	v.resize(1000005);
	v[1]=1;
	for(unsigned long long int i=2;i<1000001;i++)
	{
		unsigned long long int var;
		var=(i*(i+1))/2;
		if(i%2==1)var+=(((i-1)/2)*((i-1)/2+1));
		else var+=(i*i/4);
		v[i]=v[i-1]+var;
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int ver;
		cin>>ver;
		cout<<v[ver]<<endl;
	}
}
