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
		long long int n,h;
		cin>>n>>h;
		vector<int> blocks;
		blocks.resize(n+1);
		long long  int li,hi;
		for(int j=0;j<n;j++)
		{
			cin>>li>>hi;
			blocks[li]++;
			blocks[hi+1]--;
		}
		vector<long long int> v;
		v.resize(n+1);
		long long  int ans=n;
		for(int j=0;j<n;j++)
		{
			ans-=blocks[j];
			v[j]=ans;
		}
		long long  int fin_ans=0;
		long long  int curr=0;
		for(int j=0;j<h;j++){fin_ans+=v[j];curr+=v[j];}
		//cout<<"akash"<<endl;
		for(int j=h;j<n;j++)
		{
			curr+=v[j];
			curr-=v[j-h];
			fin_ans=min(fin_ans,curr);
		}
		cout<<fin_ans<<endl;
	}
}
