#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int K,L,n;
	cin>>K>>L>>n;
	int l=max(K,L),k=min(K,L);
	vector<int> v1,v2;
	v1.resize(1000010);
	v2.resize(1000010);
	v1[1]=0;v2[1]=1;
	v1[0]=1;v2[0]=0;
	int w1=0,w2=1;
	for(int i=2;i<k;i++)
	{
		w1=(w1+1)%2;
		w2=(w2+1)%2;
		v1[i]=w1;
		v2[i]=w2;
	}
	for(int i=k;i<l;i++)
	{
		if(v2[i-1]==0||v2[i-k]==0)v1[i]=0;
		else v1[i]=1;
		if(v1[i-1]==1||v1[i-k]==1)v2[i]=1;
		else v2[i]=0;
	}
	for(int i=l;i<1000010;i++)
	{
		if(v2[i-1]==0||v2[i-k]==0||v2[i-l]==0)v1[i]=0;
		else v1[i]=1;
		if(v1[i-1]==1||v1[i-k]==1||v1[i-l]==1)v2[i]=1;
		else v2[i]=0;
	}
	int var;
	for(int i=0;i<n;i++){cin>>var;if(v1[var]==0)cout<<"A";else cout<<"B";}
}