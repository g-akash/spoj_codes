#include<iostream>
#include<math.h>
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
		int var,a1=0,a2=0,minn=10000000;
		for(int j=0;j<n;j++)
		{
			cin>>var;
			a2+=(var-1);
			minn=min(minn,var);
			a1=minn-1;

		}

		cout<<a1<<" "<<a2<<endl;
	}
}