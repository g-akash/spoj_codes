#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	int n,m;
	cin>>n>>m;
	if(m<n)
	{
		cout<<"-1 -1"<<endl;
		continue;
	}
	if(n==m)
	{
		for(int i=1;i<n;i++)
			cout<<i<<" "<<i+1<<endl;
		cout<<n<<" "<<1<<endl;
	}
	if(n<m)
	{
		cout<<"-1 -1"<<endl;
		continue;
	}
	}
}