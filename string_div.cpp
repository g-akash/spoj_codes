#include<iostream>
#include<string>
#include<vector>

using namespace std;


bool divi(string s)
{
	string s1,s2,s3,s4;
	for(int i=1;i<s.length()-2;i++)
	{
		for(int j=i+1;j<s.length()-1;j++)
		{
			for(int k=j+1;k<s.length();k++)
			{
				s1=s.substr(0,i);
				s2=s.substr(i,j-i);
				s3=s.substr(j,k-j);
				s4=s.substr(k);
				//cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
				if(s1!=s2&&s2!=s3&&s3!=s4&&s1!=s3&&s1!=s4&&s2!=s4)return true;
			}
		}
	}
	return false;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		cin>>s;
		if(s.length()>=10)
		{
			cout<<"YES"<<endl;
		}
		else if(s.length()<4)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			if(divi(s))
			{
				cout<<"YES"<<endl;
			}
			else
				cout<<"NO"<<endl;
		}
	}
}