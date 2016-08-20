#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define ull unsigned long long int

vector<ull> dig;

ull calli(string s)
{
	if(s=="")return 1;
	int i=0;
	for(i=0;i<s.length();i++){if(s[i]!=s[0])break;}
	//if(i>=s.length())return dig[i];
	return dig[i]*calli(s.substr(i));
}

int main()
{
	dig.resize(31);
	dig[1]=1;
	dig[2]=2;
	for(int i=3;i<=30;i++)
	{
		for(int j=1;j<i;j++)dig[i]+=dig[j];
			dig[i]++;
	}
	//cout<<dig[4]<<endl;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		cin>>s;
		cout<<calli(s)<<endl;
	}

}