#include<bits/stdc++.h>

using namespace std;

class nod
{
public:
	long long int a, b,c;
	nod()
	{
		a=1;b=1;
		c=0;
	}
};

int main()
{
	vector<nod> v;
	v.resize(1000004);
	for(long long int i=2;i<1000004;i++)
	{
		if(v[i].c>0)continue;
		for(long long int j=i;j<1000004;j+=i)
		{
			v[j].a*=(i-1);
			v[j].b*=i;
			v[j].c+=1;
		}
	}
	long long int t;
	cin>>t;
	for(long long int i=0;i<t;i++)
	{
		long long int var;
		cin>>var;
		cout<<(var*v[var].a)/v[var].b<<endl;
	}
}