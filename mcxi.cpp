#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string cback(int n)
{
	string ans="";
	int var=0;
	
	if(n>=1000)
	{
		var=n/1000;
		n%=1000;
		if(var==1)ans=ans+"m";
	else ans=ans+to_string(var)+"m";
	}
	
	
	if(n>=100)
	{
		var=n/100;
		n%=100;
		if(var==1)ans=ans+"c";
	else ans=ans+to_string(var)+"c";
	}
	
	
	if(n>=10)
	{
		var=n/10;
		n%=10;
		if(var==1)ans=ans+"x";
	else ans=ans+to_string(var)+"x";
	}
	
	
	if(n>=1)
	{
		var=n/1;
		n%=1;
		if(var==1)ans=ans+"i";
	else ans=ans+to_string(var)+"i";
	}
	
	
	return ans;

}

int c(string s)
{
	int ans=0;
	string var,x;
	//cout<<s<<endl;
	while(s!="")
	{
		if(int(s[0])-48<=9)
		{
			x=s.substr(0,2);
			s=s.substr(2);
			//cout<<x<<"    "<<s<<endl;
			if(x[1]=='m'){ans+=(int(x[0])-48)*1000;}
			if(x[1]=='c'){ans+=(int(x[0])-48)*100;}
			if(x[1]=='x'){ans+=(int(x[0])-48)*10;}
			if(x[1]=='i'){ans+=(int(x[0])-48)*1;}

		}
		else
		{
			x=s.substr(0,1);
			s=s.substr(1);
			//cout<<x<<"    "<<s<<endl;
			x="1"+x;
			if(x[1]=='m'){ans+=(int(x[0])-48)*1000;}
			if(x[1]=='c'){ans+=(int(x[0])-48)*100;}
			if(x[1]=='x'){ans+=(int(x[0])-48)*10;}
			if(x[1]=='i'){ans+=(int(x[0])-48)*1;}

		}
	}
	return ans;
}


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		//cout<<c(s1)<<" "<<c(s2)<<endl;
		cout<<cback(c(s1)+c(s2))<<endl;
	}
}