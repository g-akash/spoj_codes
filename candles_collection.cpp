#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<int> vec;
	vec.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>vec[i];
	}
	vector<int> ans;
	ans.resize(n+1);
	ans[1]=0;
	for(int i=1;i<=n;i++)
	{
		int var=ans[i]+vec[i];
		ans[i]=var;
		for(int j=2*i;j<=n;j+=i)
		{
			if(var>ans[j])ans[j]=var;
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;

}