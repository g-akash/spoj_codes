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
		vector<int> v;
		v.resize(n);
		for(int j=0;j<n;j++)
		{
			cin>>v[j];
		}
		vector<int> vec;
		vec.resize(n);bool ans=false;
		for(int j=0;j<n;j++)
		{
			if(v[j]<n&&v[j]>=0)vec[j]++;
			else ans=true;
		}
		
		for(int j=0;j<n;j++)
		{
			if(vec[j]+vec[n-j-1]!=2)ans=true;
		}
		if(ans)
		{
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;


	}
}