#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int decipher(int n)
{
	if(n>=6||n==4||n==3||n==0)return -4;
	if(n==5||n==1)return -3;
	if(n==2)return -2;
	else return n;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		for(int j=0;j<n;j++)
		{
			int var;
			cin>>var;
			cout<<decipher(var)<<" ";
		}
		cout<<endl;
	}
}