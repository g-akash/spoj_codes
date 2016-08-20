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
		vector<int> vec;
		vec.resize(10);
		int var,n;
		cin>>var;
		n=var;
		for(int j=9;j>1;j--)
		{
			while(var%j==0&&var>0){var/=j;vec[j]++;}
		}
		if(var>1){cout<<-1<<endl;}
		else if(n==0){cout<<10<<endl;}
		else if(n==1){cout<<1<<endl;}
		else 
		{
			for(int j=2;j<=9;j++)
			{
				for(int k=0;k<vec[j];k++)cout<<j;
			}
			cout<<endl;
		}
		
	}
}