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
		long long int n,k;
		cin>>n;
		k=n;
		n-=2;
		if(n%2==0)n--;
		cout<<(((n+1)*(n+1))/4)%k<<endl;
	}
}