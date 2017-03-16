#include<iostream>
#include<algorithm>

using namespace std;
#define ull unsigned long long int

ull revese(ull a)
{
	ull ans=0;
	while(a!=0)
	{
		ans=ans*10+a%10;
		a/=10;
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		ull a,b;
		cin>>a>>b;
		a=revese(a);
		b=revese(b);
		a+=b;
		cout<<revese(a)<<endl;
	}
	
}