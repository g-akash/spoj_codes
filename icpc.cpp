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
		int n,p;
		cin>>n>>p;
		int var;
		vector<int> te,pr;
		te.resize(n);
		pr.resize(p);
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<p;k++)
			{
				cin>>var;
				te[j]+=var;
				pr[k]+=var;
			}
		}
		int a=1,b=1,c=1;
		for(int j=0;j<p;j++)if(pr[j]==0)a=0;
		for(int j=0;j<n;j++){if(te[j]<=0)b=0;if(te[j]>=p)c=0;}
		cout<<"Case "<<i+1<<": "<<a*4+b*2+c<<endl;
	}
}