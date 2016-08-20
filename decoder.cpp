#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define ull unsigned long long int

int main()
{
	string s;
	cin>>s;
	while(s!="0")
	{
		vector<ull> v;
		v.resize(s.length()+1);
		v[0]=1;
		v[1]=1;
		for(int i=1;i<s.length();i++)
		{
			if(stoll(s.substr(i-1,2))<=26&&s[i-1]!='0'&&s[i]!='0'){v[i+1]=v[i-1]+v[i];}
			else if(s[i-1]=='0'){v[i+1]=v[i];}
			else if(s[i]=='0'){v[i+1]=v[i-1];}
			else{v[i+1]=v[i];}
			//cout<<v[i+1]<<endl;
		}
		cout<<v[s.length()]<<endl;
		cin>>s;

	}
}