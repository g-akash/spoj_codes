#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>


using namespace std;

#define ull unsigned long long int

vector<vector<int> > likes;
int n;
unordered_map<string,ull> um;

ull assigns(int id,string rem)
{
	if(id>=n)return 1;
	string s;
	s=to_string(id)+"00000000";
	//sort(v.begin(),v.end());
	//for(int i=0;i<n;i++)s+=to_string(v[i]);
	s+=rem;
	if(um.find(s)!=um.end())return um[s];
	ull ans=0;
	for(int i=0;i<n;i++)
	{
		if(rem[i]=='0')continue;
		if(likes[id][i]==1)
		{
			string st;
			
			st=rem;
			st[i]='0';
			//vector<int> vec;
			//for(int j=0;j<v.size();j++)if(j!=i)vec.push_back(v[j]);
			ans+=assigns(id+1,st);
		}
	}
	um[s]=ans;
	return ans;
}



int main()
{
	int t;
	cin>>t;
	for(int ko=0;ko<t;ko++)
	{
		
		cin>>n;
		likes.resize(n);
		um.clear();
		for(int i=0;i<n;i++)likes[i].resize(n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)cin>>likes[i][j];
		}
		string s;
		for(int i=0;i<n;i++)s+="1";
		//for(int i=0;i<n;i++)v.push_back(i);
		cout<<assigns(0,s)<<endl;
	}
}
	
