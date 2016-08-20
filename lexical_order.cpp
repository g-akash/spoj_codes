#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s,ans;
		int fin=1;
		cin>>s;
		ans=s;
		for(int i=0;i<s.length();i++)
		{
			s=s.substr(1)+s.substr(0,1);
			if(s<ans){ans=s;fin=i+2;}
		}
		cout<<fin<<endl;
	}
}
		
