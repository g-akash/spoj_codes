#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define ull unsigned long long

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ull n,k;
		cin>>n>>k;
		vector<ull> v,p;
		v.resize(k);
		p.resize(k);
		for(int j=0;j<k;j++)cin>>v[j];
		p[0]=v[0];
		for(int j=1;j<k;j++)p[j]=2*p[j-1]+v[j];
		vector<int> ans;
		for(int j=k-1;j>=0;j--)
		{
			if(n>=p[j]){n-=p[j];ans.push_back(j+1);}
		}
		if(n!=0)cout<<-1<<endl;
		else 
		{
			for(int j=ans.size()-1;j>=0;j--)cout<<ans[j]<<" ";cout<<endl;
		}
	}
}
		
	
