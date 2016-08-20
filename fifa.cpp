#include<iostream>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		map<string,int> m;
		string s1,s2;
		int a1,a2;
		for(int j=0;j<16;j++)
		{
			cin>>s1>>s2>>a1>>a2;
			if(a1<a2){m[s1]=-1;if(m[s2]!=-1)m[s2]=1;}
			else {m[s2]=-1;if(m[s1]!=-1)m[s1]=1;}

		}
		map<string,int>::iterator it;
		it=m.begin();
		while(it->second==-1&&it!=m.end())it++;
		cout<<it->first<<endl;

	}
}