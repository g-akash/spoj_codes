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
		string s,s1;
		cin>>s;
		s1=s;
		int a=0,b=0;
		while(s1.find("SUVO")>=0&&s1.find("SUVO")<=s1.length()-4&&s1.find("SUVO")<1000000)
		{
			//cout<<s1<<" holo"<<endl;
			
			if(s1.find("SUVO")==s1.find("SUVOJIT")){s1=s1.substr(s1.find("SUVOJIT")+7);continue;}
			a++;
			s1=s1.substr(s1.find("SUVO")+4);
		}
		s1=s;
		//cout<<s1<<endl;
		while(s1.find("SUVOJIT")>=0&&s1.find("SUVOJIT")<=int(s1.length()-7)&&s1.find("SUVOJIT")<1000000)
		{
			//cout<<s1.find("SUVOJIT")<<endl;
			//cout<<s1<<endl;
			b++;
			s1=s1.substr(s1.find("SUVOJIT")+7);
			//cout<<s1<<endl;
		}
		cout<<"SUVO = "<<a<<", SUVOJIT = "<<b<<endl;
	}
}
