#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		vector<int> v;
		int n,i,var,k;
		cin>>n;
		v.resize(n);
		for(i=0;i<n;i++)cin>>v[i];
		for(i=v.size()-1;i>0;i--)
		{
			if(v[i-1]<v[i])break;
		}
		if(i<=0)
		{
			cout<<-1<<endl;
		}
		else
		{
			for(k=v.size()-1;k>=i;k--)
				if(v[k]>v[i-1])break;
			var=v[k];
			v[k]=v[i-1];
			v[i-1]=var;
			sort(v.begin()+i,v.end());
			for(i=0;i<n;i++)cout<<v[i];
			cout<<endl;

		}
	}
}