#include<iostream>
#include<math.h>

using namespace std;

#define ull unsigned long long int

int main()
{
	ull a[20],b[23];
	a[1]=1;
	a[3]=4;
	a[5]=9;
	a[7]=16;
	a[9]=25;
	a[11]=36;
	a[13]=49;
	a[15]=64;
	a[17]=81;
	a[1]=1;
	b[1]=0;
	b[3]=3;
	b[5]=8;
	b[7]=15;
	b[9]=24;
	b[11]=35;
	b[13]=48;
	b[15]=63;
	b[17]=80;
	b[18]=81;
	ull var;
	while(cin>>var)
	{
		ull ans=0;
		var=2*var-1;
		if(var<19)
		{
			cout<<a[var]<<endl;
			continue;
		}
		if(var>=19)
		{
			ans+=37+45;
			var-=18;
			ans+=(var/18)*b[18];
			ans+=b[var%18];
			cout<<ans<<endl;
			continue;
		}
	}
}