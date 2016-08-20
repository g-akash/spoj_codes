#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,a1=0,a2=0;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
			if(i==j)a1+=a[i][j];
			if(abs(i+j)==n-1)a2+=a[i][j];
		}
	}
	cout<<abs(a1-a2)<<endl;
}