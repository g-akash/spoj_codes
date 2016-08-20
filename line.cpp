#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if(a%b==0)return b;
	return gcd(b,a%b);
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a,b;
		cin>>a>>b;
		int var=gcd(a,b);
		//cout<<var<<endl;
		cout<<b/var<<" "<<a/var<<endl;
	}
}