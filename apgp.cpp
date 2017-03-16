#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	long int a,c,b;
	cin>>a>>b>>c;
	while(!(a==0&&b==0&&c==0))
	{
		if(c-b==b-a){cout<<"AP "<<c+(b-a)<<endl;}
			else{cout<<"GP "<<c*(b/a)<<endl;}
	cin>>a>>b>>c;
	}


}