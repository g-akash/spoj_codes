#include <bits/stdc++.h>

using namespace std;


int main()
{
	int t;
	cin>>t;
	for(int test=0;test<t;test++)
	{
		int n,x,y,z;
		cin>>n>>x>>y>>z;
		vector<int> s2,s3,s5,s7,others;
		s2.resize(n);
		s3.resize(n);
		s5.resize(n);
		s7.resize(n);
		others.resize(n);
		bool can_she=true;
		int var;
		for(int i=0;i<n;i++)
		{
			cin>>var;
			while(var%2==0){var=var/2;s2[i]++;}
			while(var%3==0){var=var/3;s3[i]++;}
			while(var%5==0){var=var/5;s5[i]++;}
			while(var%7==0){var=var/7;s7[i]++;}
				//can_she=false;
				others[i]=var;
		}
		for(int i=1;i<n;i++)
		{
			//cout<<others[i]<<" "<<others[i-1]<<endl;
			if(others[i]!=others[i-1])
			{
				can_she=false;
				break;
			}
		}
		
		if(x!=2&&y!=2&&z!=2)
		{
			others=s2;
			for(int i=1;i<n;i++)
			{
				if(others[i]!=others[i-1])
				{
				can_she=false;
				break;
				}
			}

		}
		if(x!=3&&y!=3&&z!=3)
		{
			others=s3;
			for(int i=1;i<n;i++)
			{
				if(others[i]!=others[i-1])
				{
				can_she=false;
				break;
				}
			}

		}
		if(x!=5&&y!=5&&z!=5)
		{
			others=s5;
			for(int i=1;i<n;i++)
			{
				if(others[i]!=others[i-1])
				{
				can_she=false;
				break;
				}
			}

		}
		if(x!=7&&y!=7&&z!=7)
		{
			others=s7;
			for(int i=1;i<n;i++)
			{
				if(others[i]!=others[i-1])
				{
				can_she=false;
				break;
				}
			}

		}
		if(can_she)cout<<"She can"<<endl;
		else cout<<"She can't"<<endl;
	}
}