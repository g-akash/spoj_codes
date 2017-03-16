#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		double n;
		cin>>n;
		double sq=sqrt(n);
		int sqr=int(sq);
		sq=sq-double(sqr);
		int ans=0;
		for(int i=0;i<10;i++)
		{
			sq*=10;
			sqr=int(sq);
			ans+=sqr;
			sq-=double(sqr);
		}
		cout<<ans<<endl;
		
	}
}