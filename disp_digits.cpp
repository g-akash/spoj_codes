#include<iostream>
#include<vector>
#include<string>

using namespace std;


int str_dig(string s)
{
	if(s=="063")return 0;
	else if(s=="010")return 1;
	else if(s=="093")return 2;
	else if(s=="079")return 3;
	else if(s=="106")return 4;
	else if(s=="103")return 5;
	else if(s=="119")return 6;
	else if(s=="011")return 7;
	else if(s=="127")return 8;
	else if(s=="107")return 9;
}
string dig_to_int(int n)
{
	if(n==0)return "063";
	else if(n==1)return "010";
	else if(n==2)return "093";
	else if(n==3)return "079";
	else if(n==4)return "106";
	else if(n==5)return "103";
	else if(n==6)return "119";
	else if(n==7)return "011";
	else if(n==8)return "127";
	else if(n==9)return "107";
}

int main()
{
	string s;
	cin>>s;
	while(s!="BYE")
	{
		string s1,s2;
		s1=s.substr(0,s.find("+"));
		s2=s.substr(s.find("+")+1,s.find("=")-s.find("+")-1);
		int a1=0,a2=0;
		while(s1!="")
		{
			a1=a1*10+str_dig(s1.substr(0,3));
			s1=s1.substr(3);
		}
		while(s2!="")
		{
			a2=a2*10+str_dig(s2.substr(0,3));
			s2=s2.substr(3);
		}
		a1+=a2;
		string ans="";
		while(a1!=0)
		{
			ans=dig_to_int(a1%10)+ans;
			a1/=10;
		}
		cout<<s+ans<<endl;
		cin>>s;
	}
}