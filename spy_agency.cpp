#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
		int n;
		cin>>n;
		vector<int> v,v1,v2;
		v.resize(n);
		int q,a,b,i;
		cin>>q;
		v1.resize(q);
		v2.resize(q);
		for(i=0;i<q;i++)cin>>v1[i]>>v2[i];
		for(i=0;i<q;i++)
		{
			a=v1[i];b=v2[i];
			if(v[a]==1){cout<<"Scenario #"<<k+1<<": spied"<<endl;break;}
			if(v[b]==2){cout<<"Scenario #"<<k+1<<": spied"<<endl;break;}
			v[a]=2;
			v[b]=1;	
		}
		if(i<q)continue;
		cout<<"Scenario #"<<k+1<<": spying"<<endl;
	}
}