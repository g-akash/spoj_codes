#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		vector<int> v;
		v.resize(n);
		int a,b,var,ans=1;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			var=i+b;
			if(var<0||var>=n){ans=0;}
			else if(v[var]>0){ans=0;}
			v[var]=a;
		}
		if(ans)
		{
			for(int i=0;i<n;i++)cout<<v[i]<<" ";
				cout<<endl;
		}
		else cout<<-1<<endl;
		cin>>n;
	}
}