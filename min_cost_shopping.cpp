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
		int a,b,c;
		vector<int> va,vb,vc;
		int n;
		cin>>n;
		va.resize(n);
		vb.resize(n);
		vc.resize(n);
		cin>>va[0]>>vb[0]>>vc[0];
		for(int i=1;i<n;i++)
		{
			cin>>a>>b>>c;
			va[i]=a+min(vb[i-1],vc[i-1]);
			vb[i]=b+min(va[i-1],vc[i-1]);
			vc[i]=c+min(vb[i-1],va[i-1]);
		}
		if(va[n-1]<=vb[n-1]&&va[n-1]<=vc[n-1])cout<<va[n-1]<<endl;
		else if(vb[n-1]<=vc[n-1])cout<<vb[n-1]<<endl;
		else cout<<vc[n-1]<<endl;
	}
}
		
