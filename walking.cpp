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
		int n;
		cin>>n;
		vector<int> a,b,c,ansa,ansb,ansc;
		a.resize(n);
		b.resize(n);
		c.resize(n);
		ansa.resize(n);
		ansb.resize(n);
		ansc.resize(n);
		for(int j=0;j<n;j++)
		{
			cin>>a[j]>>b[j]>>c[j];
		}
		ansa[0]=a[0];
		ansb[0]=b[0];
		ansc[0]=c[0];
		for(int j=1;j<n;j++)
		{
			ansa[j]=a[j]+min(ansb[j-1],ansc[j-1]);
			ansb[j]=b[j]+min(ansa[j-1],ansc[j-1]);
			ansc[j]=c[j]+min(ansa[j-1],ansb[j-1]);
		}
		cout<<min(ansa[n-1],min(ansb[n-1],ansc[n-1]))<<endl;
	}
}