#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<iterator>

using namespace std;

bool equls(char c1, char c2)
{
	int a1= int(c1);
	int a2=int(c2);
	if(a1>=97&&a2>=97)
	{
		if(a1==a2)return true;
	}
	else if(a1>=97&&a2>=65)
	{
		if(a1-32==a2)return true;
	}
	else if(a1>=65&&a2>=97)
	{
		if(a1==a2-32)return true;
	}
	else if(a1==a2)return true;
	return false;
}

int main()
{
	string s;
	getline(cin,s);
	while(s!="*")
	{
		istringstream iss(s);
		vector<string> tokens{istream_iterator<string>{iss},istream_iterator<string>{}};
		bool ans=true;
		char ch = tokens[0][0];
		for(int i=1;i<tokens.size();i++)if(!equls(ch,tokens[i][0]))ans=false;
		if(ans)cout<<"Y"<<endl;
		else cout<<"N"<<endl;
		getline(cin,s);
	}
}