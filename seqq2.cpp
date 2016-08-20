#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> s,q;
	s.resize(n);
	q.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>q[i];
	}
	for(int i=0;i<n;i++)
	{
		bool ans=false;
		for(int j=max(0,i-k);j<=min(i+k,n-1);j++)if(s[i]==q[j])ans=true;
			if(ans)cout<<i+1<<" ";
	}
	cout<<endl;
}