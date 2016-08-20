#include<iostream>

using namespace std;

int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(b==a)cout<<"YES"<<endl;
	else if(c!=0&&(b-a)/c>=0&&(b-a)%c==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
