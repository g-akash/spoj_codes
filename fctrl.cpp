#include<iostream>
#include<algorithm>

using namespace std;

int z(int n)
{
	int ans=0;
	while(n!=0)
	{
		n=n/5;
		ans+=n;
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		cout<<z(n)<<endl;
	}
}