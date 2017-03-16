#include<iostream>

using namespace std;

int main()
{
	long long int n;
	cin>>n;
	while(n!=-1)
	{
		long long int ans=0,var;
		while(n!=0)
		{
			var=n&0x1;
			n=n>>1;
			ans=ans*2+var;
		}
		cout<<ans<<endl;
		cin>>n;
	}
}
