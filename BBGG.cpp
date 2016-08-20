#include<iostream>
#include<vector>
#include<string>


using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		int n;
		cin>>n>>s;
		int eb=0,eg=0,ob=0,og=0;
		for(int j=0;j<s.length();j++)
		{
			if(j%2==0){if(s[j]=='B')eb++;else eg++;}
			else{if(s[j]=='B')ob++;else og++;}
		}
		if(eb<=ob)cout<<eb<<endl;
		else cout<<ob<<endl;
	}
}
