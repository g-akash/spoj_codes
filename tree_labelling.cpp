#include<iostream>

using namespace std;

int main()
{
	int var,c=1;
	cin>>var;
	while(var!=0)
	{
		int ans=1;
		for(int i=0;i<var-2;i++)ans*=var;
	//cout<<ans<<endl;
	cout<<"Case "<<c<<", N = "<<var<<", # of different labelings = "<<ans<<endl;
	c++;
	cin>>var;
	}
}