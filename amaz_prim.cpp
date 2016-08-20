#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v;
	v.resize(1000000);
	for(int i=2;i<1000000;i++)
	{
		if(v[i]>=1)continue;
		for(int j=2*i;j<1000000;j+=i)
		{
			v[j]+=1;
		}
	}
	vector<int> ans;
	for(int i=0;i<1000000;i++)
	{
		if(v[i]>=3)ans.push_back(i);
	}
	//cout<<ans.size()<<endl;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int var;
		cin>>var;
		cout<<ans[var-1]<<endl;
	}
}