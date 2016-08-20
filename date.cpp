#include<iostream>
#include<string>
#include <sstream>
#include <algorithm>
#include <iterator>


using namespace std;

bool isnumric(string s)
{
	for(int i=0;i<s.length();i++)if(!isdigit(s[i]))return false;
	return true;
}

int main()
{
	int t,var;
	char ch;
	vector<int> v;
	v.resize(31);
	cin>>t;
	cin.get(ch);
	for(int i=0;i<t;i++)
	{
		string s;
		getline(cin,s);
		istringstream iss(s);
		vector<string> tokens{istream_iterator<string>{iss},istream_iterator<string>{}};
		for(int j=0;j<tokens.size();j++)
		{
			if(isnumric(tokens[j])){var=stoi(tokens[j]);if(tokens[0]=="G:"){v[var]+=2;}else{v[var]+=1;}}
		}
		
		
}
int maxx=0,maxxdate=0;
		for(int i=0;i<=30;i++)
		{
				  if(v[i]>maxx){maxxdate=i;maxx=v[i];}
		}
		int count=0;
		for(int i=0;i<=30;i++)if(v[i]==maxx)count++;
		if(count==1&&(maxxdate==19||maxxdate==20))cout<<"Date"<<endl;
		else cout<<"No Date"<<endl;
}
