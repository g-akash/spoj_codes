#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n,m,var;
		cin>>n>>m;
		string s[n];
		for(int j=0;j<n;j++)cin>>s[j];
		for(int a=0;a<n;a++)
		{
			for(int b=0;b<m;b++)
			{
				var=10000;
				int k=0;
				bool fnd=false;
				for(int k=0;k<max(m,n)&&!fnd;k++)
				{
					for(int c=max(0,a-k);c<=a&&b+k+c-a>=0;c++){if(s[c][b+k+c-a]=='1'){var=k;fnd=true;break;}}
					for(int c=max(0,b+k);c<=b&&a+k+b-c<m;c++){if(s[a+k+b-c][c]=='1'){var=k;fnd=true;break;}}
					for(int c=min(m-1,a+k)&&b-k-a+c<n;c>=a;c--){if(s[c][b-k-a+c]=='1'){var=k;fnd=true;break;}}
					for(int c=min(n-1,b-k)&&a+b-k-c>=0;c>=b;c--){if(s[a+b-k-c][c]=='1'){var=k;fnd=true;break;}}
				}
				cout<<var<<" ";
			}
			cout<<endl;
		}
	}
}
