#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
	double l;
	cin>>l;
	while(l!=0)
	{
		double ans=(l*l)/(2.0*3.1415926);
		ans*=10000;
		int ansi=int(ans);
		if(ansi%100>=50){float ansii=float(ansi/100);ansii+=1;ansii/=100.0;cout<<ansii<<endl;}
		else{float ansii=float(ansi/100);ansii/=100.0;cout<<ansii<<endl;}
		cin>>l;
	}
}