#include<iostream>
#include<math.h>
#include<iomanip>


using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		double x;
		cin>>x;
		cout<<fixed<<setprecision(4)<<8.0*(2.0-sqrt(2))*pow(x,3)<<endl;
	}
}