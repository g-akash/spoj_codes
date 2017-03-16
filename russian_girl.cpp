#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int sv=0,tr=0,tr1=0;
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i]=='0'&&s[i+1]=='0')sv++;
		else if(s[i]=='0'&&s[i+1]=='1')tr++;
		if(s[i]=='0')tr1++;
	}
	if(s[s.length()-1]=='0'&&s[0]=='0')sv++;
	if(s[s.length()-1]=='0'&&s[0]=='1')tr++;
	if(s[s.length()-1]=='0')tr1++;
	if(sv*(s.length()-tr1)==tr*tr1)cout<<"EQUAL"<<endl;
	else if(sv*(s.length()-tr1)>tr*tr1)cout<<"SHOOT"<<endl;
	else cout<<"ROTATE"<<endl;
}
