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
		unsigned long long int n,k,m;
		cin>>n>>k>>m;
		int count=0;
		if(n>m){cout<<"0"<<endl;continue;}
		while(m>=n)
		{
			m/=k;
			count++;
		}
		cout<<count-1<<endl;
	}
}