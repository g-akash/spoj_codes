#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		cin>>s;
		int r2=0,r5=0;
		for(int j=0;j<s.length();j++)
		{
			r2=(r2*10+int(s[j])-48)%252;
			r5=(r5*10+int(s[j])-48)%525;
		}
		if(r2==0)cout<<"Yes ";
		else cout<<"No ";
		if(r5==0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}