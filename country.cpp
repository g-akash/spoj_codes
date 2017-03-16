#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		cin>>s;
		unordered_map<string,int> m;
		for(int j=0;j<s.length()-1;j++)
		{
			m[s.substr(j,2)]=1;
		}
		int ans=0;
		unordered_map<string,int>::iterator it=m.begin();
		while(it!=m.end())
		{
			ans++;
			it++;
		}
		cout<<ans<<endl;

	}
}