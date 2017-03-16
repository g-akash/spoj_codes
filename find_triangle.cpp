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
		vector<int> v;
		int n;
		cin>>n;
		v.resize(n);
		for(int j=0;j<n;j++)
		{
			cin>>v[j];
		}
		sort(v.begin(),v.end());
		bool ans=false;
		for(int j=n-1;j>=2;j--)
		{
			if(v[j]<v[j-1]+v[j-2]){cout<<v[j-2]<<" "<<v[j-1]<<" "<<v[j]<<endl;ans=true;break;}
		}
		if(!ans)cout<<-1<<endl;
	}
}