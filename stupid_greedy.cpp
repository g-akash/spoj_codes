#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int sum=0,var;
		for(int j=0;j<n;j++)
		{
			cin>>var;
			sum+=var;
		}
		if(sum%2==0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
