#include<bits/stdc++.h>

using namespace std;


int main()
{
	int t;
	cin>>t;
	char ch;
	cin.get(ch);
	for(int i=0;i<t;i++)
	{
		string s="";
		while(s=="")
		getline(cin,s);
		vector<string> v;
		vector<int> vec;
		istringstream iss(s);
		copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(v));
		vec.resize(v.size());
		for(int j=0;j<v.size();j++)
		{
			vec[j]=v[j].length();
		}

		int ans=1,curr=1;
		for(int j=1;j<v.size();j++)
		{
			if(vec[j]==vec[j-1])curr++;
			else curr=1;
			ans=max(ans,curr);
		}
		cout<<ans<<endl;
	}
}