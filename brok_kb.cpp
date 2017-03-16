#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;


int main()
{
	int m;
	string s;
	cin>>m;
	char ch;
	while(m!=0)
	{
		cin.get(ch);
		getline(cin,s);
		unordered_map<char,int> mp;
		int ans=0,begin=0,currsize=0;
		for(int i=0;i<s.length();i++)
		{
			mp[s[i]]++;
			currsize++;
			//cout<<s[i]<<" "<<mp.size()<<endl;
			if(mp.size()>m)
			{
				while(mp.size()>m)
				{
					mp[s[begin]]-=1;
					currsize--;
					if(mp[s[begin]]==0)mp.erase(mp.find(s[begin]));
					begin++;
				}
			}
			ans=max(ans,currsize);

		}
		cout<<ans<<endl;
		cin>>m;
	}
}