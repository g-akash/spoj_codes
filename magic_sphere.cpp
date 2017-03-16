#include<iostream>

using namespace std;

int main()
{
	int a,b,c,x,y,z;
	cin>>a>>b>>c>>x>>y>>z;
	int pos=0,neg=0;
	if(a>x)pos+=(((a-x)/2)*2);else neg+=(x-a);
	if(b>y)pos+=(((b-y)/2)*2);else neg+=(y-b);
	if(c>z)pos+=(((c-z)/2)*2);else neg+=(z-c);
	if(neg*2<=pos)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}