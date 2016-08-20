#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int ss(int a)
{
	int ans=0;
	while(a>0){ans+=a%10;a/=10;}
	return ans;
}

int prim_sum(vector<int> vec,int a,int b)
{
	int ans=0;
	for(int i=0;i<vec.size();i++)
	{

		if(vec[i]==0&&i+a<=b&&i+a!=1){ans+=ss(i+a);}
	}
	return ans;
}

int main()
{
	vector<int> v,prim;
	v.resize(100005);
	v[2]=0;
	for(int i=2;i<100005;i++)
	{
		if(v[i]==1){continue;}
		if(v[i]==0)prim.push_back(i);
		for(int j=2*i;j<100005;j+=i)v[j]=1;
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		vector<int> vec;
		vec.resize(b+5-a);
		for(int i=0;i<prim.size();i++)
		{
			int l;
			if(prim[i]>b+5)break;
			//cout<<prim[i]<<endl;
			l=a/prim[i];
			l*=prim[i];
			while(l>a)l-=prim[i];
			while(l<a)l+=prim[i];
			if(l==prim[i])l*=2;
			for(int j=l;j<b+5;j+=prim[i])
			{
				vec[j-a]=1;
			}
		}
		cout<<prim_sum(vec,a,b)<<endl;
	}
}
