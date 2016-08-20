#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	unsigned long long int n,t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		cin>>n;
		unsigned long long int tot=0,cnt=0;
		vector<unsigned long long int> v;
		v.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			tot+=v[i];
			cnt+=tot/n;
			tot=tot%n;
		}
		unsigned long long int pp=tot/n,ans=0;
		if(pp*n!=tot)
		{
			cout<<"NO"<<endl;
		}
		else 
		{
		cout<<"YES"<<endl;
	}
		


	}
}