#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	int n,k;
	cin>>n;
	vector<int> v;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	map<int,int> s;
	cin>>k;
	map<int,int>::iterator it;
	for(int i=0;i<k;i++)s[v[i]]+=1;
	for(int i=k;i<n;i++)
	{
		it=s.end();it--;
		cout<<it->first<<" ";
		s[v[i-k]]-=1;
		if(s[v[i-k]]==0)s.erase(v[i-k]);
		s[v[i]]=s[v[i]]+1;
	}
	it=s.end();it--;
		cout<<it->first<<" ";
}