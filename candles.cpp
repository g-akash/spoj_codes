#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		unsigned long long int a,b,l,r;
		cin>>a>>b;
		l=sqrt(a);r=sqrt(b);
		while(r*r>b)r-=1;
		while((r+1)*(r+1)<=b)r+=1;
		while(l*l>=a)l-=1;
		while((l+1)*(l+1)<a)l+=1;
		r=r-l;
		cout<<r<<endl;
	}
}
