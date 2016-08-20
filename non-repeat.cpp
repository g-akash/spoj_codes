#include<iostream>
#include<string>
#include<vector>
#include <sstream>


using namespace std;

int main()
{
	
	string s;
	string charac;
	cin>>s;
	vector<int>v;//v is count of characters to be named properly later.
	v.resize(26);
	for(int i=0;i<26;i++)v[i]=0;
	int str_length=s.length();
	for(int i=0;i<str_length;i++)
	{
		v[int(s[i])-97]++;
		//cout<<int(s[i])-97<<endl;
	}
	string unique="";
	for(int i=0;i<26;i++)
	if(v[i]==1)
	{
		stringstream ss;
		ss << char(i+97);
		ss >> charac;unique=unique+charac;
		}
		//cout<<unique<<endl;
	for(int i=0;i<str_length;i++)
	if(unique.find(s.substr(i,1))>=0&&unique.find(s.substr(i,1))<str_length){cout<<s.substr(i,1)<<endl;return 0;}
	cout<<"All charaters repeat in this string"<<endl;
}
	
