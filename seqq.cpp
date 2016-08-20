#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n,m;
	cin>>n;
	vector<int> s;
	s.resize(n);
	for(int i=0;i<n;i++)cin>>s[i];
	cin>>m;
	vector<int> q;
	q.resize(m);
	for(int i=0;i<m;i++)
	{
		cin>>q[i];
	}
	for(int i=0;i<min(m,n);i++)
	{
		if(s[i]==q[i])cout<<i+1<<" ";
	}
	cout<<endl;
}