#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,maxn=-100000000;
	cin>>n;
	vector<int> v;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		maxn=max(maxn,v[i]);
	}
	vector<int> ans;
	ans.resize(maxn+1);
	ans[0]=1;
	ans[1]=1;
	ans[2]=5;
	for(int i=3;i<=maxn;i++)
	{
		int var=0;
		for(int j=1;j<=i;j++)
		{
			if(j==1)var+=ans[i-j];
			else if(j==2)var+=4*ans[i-j];
			else if(j%2==0)var+=3*ans[i-j];
			else var+=2*ans[i-j];
		}
		ans[i]=var;
		//ans[i]+=2;
	}
	//for(int i=1;i<ans.size();i++)cout<<ans[i]<<" ";cout<<endl;
	for(int i=0;i<v.size();i++)cout<<i+1<<" "<<ans[v[i]]<<endl;
}
