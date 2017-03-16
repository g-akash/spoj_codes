#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		vector<unsigned int> v;
		v.resize(100005);
		v[0]=1;
		unsigned int var;
		for(int j=0;j<n;j++)
		{
			cin>>var;
			for(int k=100004-var;k>=0;k--)if(v[k]==1)v[k+var]=1;
		} 
	unsigned int ans=0;
	for(int i=0;i<100005;i++)if(v[i]==1)ans+=i;
		cout<<ans<<endl;
	}
}