#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std;

#define pi 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define ex 2.718281828459


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		double n;
		cin>>n;
		if(n!=0&&n!=1)
		cout<<setprecision(15)<<ceil((log(2.0*pi)-2.0*n+log(n)*(1.0+2.0*n))/(2.0*log(10)))<<endl;
	else cout<<1<<endl;}
}