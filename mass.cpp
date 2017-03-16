#include<iostream>
#include<vector>
#include<math.h>
#include<string>

using namespace std;


int mass(string s)
{
	//<<s<<endl;
	int massi,mass2;
	if(s.length()==0)return 0;
	if(s.length()==1)
	{
		if(s=="C")return 12;
		if(s=="O")return 16;
		if(s=="H")return 1;
		return 0;
	}
	if(s[0]!='('&&(int(s[1])>57||int(s[1])<48))
		{
			massi=mass(s.substr(1));
			if(s[0]=='C')massi+=12;
			if(s[0]=='O')massi+=16;
			if(s[0]=='H')massi+=1;
			//cout<<massi<<" ohkay"<<endl;
			return massi;
		}
	if(s[0]!='('&&int(s[1])>=48)
	{
		massi=mass(s.substr(2));
		//cout<<stoi(s.substr(1,1))<<" ok"<<endl;
		if(s[0]=='C')massi+=(12*stoi(s.substr(1,1)));
		if(s[0]=='O')massi+=(16*stoi(s.substr(1,1)));
		if(s[0]=='H')massi+=(1*stoi(s.substr(1,1)));
		//cout<<massi<<endl;
		return massi;
	}
	if(s[0]=='(')
	{
		int count=1,i=1;

		while(count!=0)
		{
			if(s[i]=='(')count++;
				else if(s[i]==')')count--;
			i++;	
		}
		string rem1=s.substr(1,i-2),rem2=s.substr(i);
		mass2=mass(rem1);
		if(rem2=="")return mass2;
		if(rem2[0]!='('&&(int(rem2[0])<=57&&int(rem2[0]>=48)))
			{mass2*=stoi(rem2.substr(0,1));
			rem2=rem2.substr(1);}
			massi=mass(rem2);
			return massi+mass2;
	}
return massi;
}
int main()
{
	string s;
	cin>>s;
	cout<<mass(s)<<endl;
}
