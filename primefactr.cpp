#include<iostream>
#include<vector>

using namespace std;
vector<int> v;


void fac()
{
	for(int i=2;i<10001;i++)
	{
		if(v[i]==1)continue;
		for(int j=2*i;j<10001;j+=i)
			v[j]=1;
	}
}


int main()
{
	int n;
	
	v.resize(10001);
	fac();
	vector<int> prms;
	for(int i=2;i<10001;i++)
		if(v[i]==0)prms.push_back(i);
	for(int i=0;i<10001;i++)v[i]=0;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int var=i;
		for(int j=0;j<prms.size()&&prms[j]<=i;j++)
			while(var%prms[j]==0){v[prms[j]]++;var/=prms[j];}
	}
	vector<int> v1,v2;
	for(int i=0;i<prms.size();i++)if(v[prms[i]]!=0){v1.push_back(prms[i]);v2.push_back(v[prms[i]]);}
	for(int i=0;i<v1.size()-1;i++)
	cout<<v1[i]<<"^"<<v2[i]<<" * ";
	cout<<v1[v1.size()-1]<<"^"<<v2[v2.size()-1]<<endl;	
}