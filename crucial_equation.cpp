#include<iostream>
#include<vector>

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
		int a,b,c;
		cin>>a>>b>>c;
		int x,y,z,ans=0;
		z=gcd(a,b);
		if(c%z==0)cout<<"Case "<<i+1<<": Yes"<<endl;
		else cout<<"Case "<<i+1<<": No"<<endl;
	}
}
		
