#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<set>
#include<sstream>
#include <iterator>

using namespace std;

map<string,vector<string> > m;
unordered_map<string,int> installed;
unordered_map<string,int> inqueue;
unordered_map<string,int> allpackages;

bool install(string package)
{
	//cout<<package<<endl;
	if(allpackages.find(package)==allpackages.end())return false;
	if(installed.find(package)!=installed.end())return true;
	if(inqueue.find(package)!=inqueue.end())return false;
	vector<string> depend=m[package];
	inqueue[package]=1;
	bool doit=true;
	for(int i=0;i<depend.size();i++)
	{
		doit=doit&install(depend[i]);
	}
	if(doit)installed[package]=1;
	//inqueue.erase(inqueue.find(package));
	return doit;
}

int main()
{
	string s;
	while(getline(cin,s))
	{
		istringstream iss(s);
		vector<string> tokens{istream_iterator<string>{iss},istream_iterator<string>{}};
		allpackages[tokens[0]]=1;
		vector<string> fin(tokens.begin()+1,tokens.end()-1);
		m[tokens[0]]=fin;
	}
	unordered_map<string,int>::iterator it = allpackages.begin();
	while(it !=allpackages.end())
	{
		install(it->first);
		it++;
	}
	cout<<installed.size()<<endl;

}