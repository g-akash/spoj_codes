#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

string s="";

char st1[1000000],st2[1000000];
string s1,s2;

string comp()
{
	if(s1.length()>s2.length())s2=s.substr(0,s1.length()-s2.length())+s2;
	if(s1.length()<s2.length())s1=s.substr(0,s2.length()-s1.length())+s1;
	string ans="=";
	if(s1<s2)return "<";
	else if(s2<s1)return ">";
	return ans;
}

int main()
{
	for(int i=0;i<100006;i++)s="0"+s;
	
	scanf("%s",st1);
	scanf("%s",st2);
	s1=string(st1);
	s2=string(st2);
	while(!(s1=="*"&&s2=="*"))
	{
		printf("%s\n",(comp()).c_str());
		scanf("%s",st1);
		scanf("%s",st2);
		s1=string(st1);
		s2=string(st2);

	}
}