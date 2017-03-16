#include<iostream>
#include<string>

using namespace std;


int main()
{
	int t;
	cin>>t;
	for(int count=0;count<t;count++)
	{
		string s1,s2,s3;
		cin>>s1;
		cin>>s2;
		cin>>s2;
		cin>>s3;
		cin>>s3;
		if(s1.find("machula")>=0&&s1.find("machula")<s1.length()){cout<<stoll(s3)-stoll(s2)<<" + "<<s2<<" = "<<s3<<endl;}
		else if(s2.find("machula")>=0&&s2.find("machula")<s2.length()){cout<<s1<<" + "<<stoll(s3)-stoll(s1)<<" = "<<s3<<endl;}
		else {cout<<s1<<" + "<<s2<<" = "<<stoll(s1)+stoll(s2)<<endl;}
	}
}