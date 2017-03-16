#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define ull unsigned long long 

int main()
{
	ull int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ull int n;
		cin>>n;
		ull int var,ans=1;
		cin>>var;
		for(ull int j=0;j<9;j++)
		{
			var++;
			ans*=var;
		}
		for(ull int j=1;j<=9;j++)ans/=j;
			cout<<i+1<<" "<<ans<<endl;
	}
}