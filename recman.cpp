#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v;
	v.resize(10000000);
	vector<int> ans;
	ans.resize(500001);
	ans[0]=0;
	v[0]=1;
	for(int i=1;i<=500000;i++)
	{
		
		if(ans[i-1]-i>0&&v[ans[i-1]-i]==0)
		{
			ans[i]=ans[i-1]-i;
			v[ans[i]]=1;
		}
		else
		{
			ans[i]=ans[i-1]+i;
			v[ans[i]]=1;
		}
		//cout<<ans[i]<<" "<<i<<endl;
	}
	int k;
	cin>>k;
	while(k!=-1)
	{
		cout<<ans[k]<<endl;
		cin>>k;
	}
}