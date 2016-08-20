#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool is_subsequence(string s1, string s2)
{
	int x=0,y=0;
	while(x<s1.length()&&y<s2.length())
	{
		if(s1[x]==s2[y]){x++;y++;}
		else x++;
	}
	if(y>=s2.length())return true;
	return false;
}

string make_string(string s, int n)
{
	string ans="";
	string temp;
	for(int i=0; i<s.length(); i++)
	{
		temp = s.substr(i,1);
		for(int j=0;j<n;j++)ans+=temp;
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	char ch;
	cin.get(ch);
	for(int i=0;i<t;i++)
	{
		string s1,s2,temp;
		//cin>>s2>>s1;
		getline(cin,s2);
		getline(cin,s1);
		if(s2.length()<=0){cout<<0<<endl;continue;}
		int x=0,y=s1.length()/s2.length()+1;
		while(y-x>1)
		{
			int mid = (x+y)/2;
			temp = make_string(s2,mid);
			if(is_subsequence(s1,temp))x=mid;
			else y=mid;

		}
		cout<<x<<endl;
	}
}