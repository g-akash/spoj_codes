#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()
vector<vector<string> > comm;
vector<string> tokens;
vi commas;
int nxt=0;


void get_comments( int pos)
{
	//cout<<nxt<<endl;
	//cout<<s<<endl;
	
	string text = tokens[nxt];
	nxt++;
	//s=s.substr(commas[nxt]+1);
	//nxt++;
	comm[pos].pb(text);
	if(nxt>=tokens.size())
	{
		return ;
	}
	int num = stoi(tokens[nxt]);
	nxt++;
	foi(num)
	{
		get_comments(pos+1);
	}
	return ;
}




int main()
{
	string s;
	cin>>s;
	int prev=0;
	s=s+",";
	foi(s.length())
	{
		if(s[i]==',')
		{
			tokens.pb(s.substr(prev,i-prev));
			commas.pb(i-prev);
			prev=i+1;

		}
	}
	//foi(tokens.size())cout<<tokens[i]<<endl;
	s=s.substr(0,s.length()-1);
	//cout<<s<<endl;
	comm.resize(1000000);
	int curr=0;
	//cout<<commas.size()<<endl;
	//foi(commas.size())cout<<commas[i]<<endl;

	while(nxt<tokens.size())
	{get_comments(curr);}
	
	int count=0;
	foi(1000000)
	{
		if(comm[i].size()!=0)count++;
		else break;
	}
	cout<<count<<endl;
	foi(count)
	{
		foj(comm[i].size())cout<<comm[i][j]<<" ";
		cout<<endl;
	}
}