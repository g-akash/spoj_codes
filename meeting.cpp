#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int a, int b)
{
	if(a<=0||b<=0)return 1;
	if(a%b==0)return b;
	return gcd(b,a%b);
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;

		bool yes=false;
		if(a==0||b==0){cout<<1<<endl; continue;}
		else if(a<0&&b<0){a=-1*a;b=-1*b;}
		else if(a>0&&b>0){}
		else if(a<0){a=-1*a;yes=true;}
		else if(b<0){b=-1*b;yes=true;}
		int gd=gcd(a,b);
		int var;
		if(yes){if(a>b){var=a;a=b;b=var;}a=a*a+a*b;b*=b;gd=gcd(a,b); a/=gd;b/=gd;cout<<a<<endl;}
		else {if(a>b){var=a;a=b;b=var;}a/=gd;b/=gd;cout<<a*b-1<<endl;}
	}
}		