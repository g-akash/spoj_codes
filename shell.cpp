#include<iostream>
#include<string>
 
using namespace std;
 
int main()
{
	int n;
	string pos,s1,s2;
	cin>>pos;
	cin>>n;
	if(n==10)
	{
		//cout<<"other"<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
	cin>>s1>>s2;
	if(pos==s1){pos=s2;if(s2!="left"&&s2!="right"&&s2!="center")pos="";}
	else if(pos==s2){pos=s1;if(s1!="left"&&s1!="right"&&s1!="center")pos="";}
	}
	cout<<pos<<endl;
} 