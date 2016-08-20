#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

unordered_map<string,string> m;

string ls(string a, string b)
{
	if(a=="")return "";
	if(b=="")return "";
	if(m.find(a+b)!=m.end())return m[a+b];
	if(a[0]==b[0])
	{
		string ans=ls(a.substr(1),b.substr(1));
		m[a+b]=a.substr(0,1)+ans;
		return a.substr(0,1)+ans;
	}
	else
	{
		string s1=ls(a,b.substr(1)),s2=ls(a.substr(1),b);
		if(s1.length()>s2.length()){m[a+b]=s1;return s1;}
			else {m[a+b]=s2;return s2;}
	}
	return "";
}

int main()
{
	
	string a,b;
	cin>>a>>b;
	cout<<ls(a,b)<<endl;
}