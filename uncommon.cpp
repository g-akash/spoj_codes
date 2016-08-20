#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

int main()
{
	int n,m;
	vector<int> s,q;
	cin>>n;
	s.resize(n);
	for(int i=0;i<n;i++)cin>>s[i];
	cin>>m;
	q.resize(m);
	for(int i=0;i<m;i++)cin>>q[i];
	int j=0,k=0;
	while(j<n&&k<m)
	{
		if(s[j]==q[k]){s[j]=-200;j++;}
		else if(s[j]<q[k])j++;
		else if(s[j]>q[k])k++;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]!=-200)cout<<s[i]<<" ";
	}
	cout<<endl;
}
