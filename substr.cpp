#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>


using namespace std;
string s;

bool repets(int var)
{
	unordered_map<string,int> m;
	for(int i=0;i<s.length()+1-var;i++)
	{
		string a=s.substr(i,var);
		//cout<<a<<endl;
		if(m[a]>0)return true;
		m[a]=1;
	}
	return false;


}

int main()
{
	
	cin>>s;
	int x=0,y=s.length()-1;
	int len=0;
	while(y-x>1)
	{
		//cout<<x<<" "<<y<<endl;
		int var=(x+y)/2;
		bool find=repets(var);
		if(find)
		{
			x=var;
		}
		else
			y=var;
		
		//cout<<x<<" "<<y<<endl;
	}
	if(repets(y))cout<<y<<endl;
	else cout<<x<<endl;
}