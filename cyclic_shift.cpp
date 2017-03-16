#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;


int main()
{
	string s;
	cin>>s;
	vector<string> str;
	str.resize(s.length());
	for(int i=0;i<s.length();i++)
	{
		str[i]=s;
		s=s.substr(s.length()-1,1)+s.substr(0,s.length()-1);
	}
	sort(str.begin(),str.end());
	int count=1;
	for(int i=1;i<s.length();i++)
	{
		if(str[i]!=str[i-1])count++;
	}
	cout<<count<<endl;		
}