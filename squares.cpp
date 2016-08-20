#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		cout<<(n*(n+1)*(2*n+1))/6<<endl;
		cin>>n;
	}
}