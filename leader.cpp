#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class leader_name
{
public:
	string name;
	int diff_char;
};



bool comp(leader_name p, leader_name q)
{
	if(p.diff_char<q.diff_char)return true;
	if(p.diff_char==q.diff_char&&p.name>=q.name)return true;
	return false;
}

int diff_chars(string s)
{
	int chars[26];
	for(int i=0;i<26;i++)chars[i]=0;
	for(int i=0;i<s.length();i++)
	{
		if(int(s[i])>=65)
		{
			chars[int(s[i])-65]++;
		}
	}
	int ans=0;
	for(int i=0;i<26;i++)if(chars[i]>0)ans++;
	return ans;
}

int main()
{
	int t;
	cin>>t;
	for(int ko=0;ko<t;ko++)
	{
		vector<leader_name> vec;
		int n;
		cin>>n;
		char ch;
		cin.get(ch);
		vec.resize(n);
		for(int i=0;i<n;i++)
		{
			getline(cin,vec[i].name);
			vec[i].diff_char=diff_chars(vec[i].name);
			//cout<<vec[i].name<<endl;
		}
		sort(vec.begin(),vec.end(),comp);
		cout<<"Case #"<<ko+1<<": "<<vec[n-1].name<<endl;
		//for(int i=0;i<n;i++)cout<<vec[i].name<<" "<<vec[i].diff_char<<endl;
	}

}