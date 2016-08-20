#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;
vector<unsigned long long int> vals;
map<string,unsigned long long int> m;

unsigned long long int ma(string s)
{
	//cout<<s<<" ohyes"<<endl;
	unsigned long long int ans=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='.')ans+=1;
		if(s[i]=='-')ans+=5;
	}
	//cout<<ans<<" hello"<<endl;
	return ans;
}

unsigned long long int ans(vector<string> v)	
{
	unsigned long long int ans=0,val=1;

	for(int i=0;i<v.size();i++)
	{
		ans+=(ma(v[i])*vals[v.size()-i-1]);
	}
	return ans;
}


int main()
{
	//m["S"]=0;
	//m["."]=1;
	//m[".."]=2;m["..."]=3;m["...."]=4;m["-"]=5;m[". -"]=6;m[".. -"]=7;m["... -"]=8;m[".... -"]=9;
	//m["- -"]=10;m[". - -"]=11;m[".. - -"]=12;m["... - -"]=13;m[".... - -"]=14;m["- - -"]=15;m[""]=16;m[]=17;
	//m[]=18;m[]=19
	vals.resize(8);
	vals[0]=1;
	vals[1]=20;
	vals[2]=360;
	for(int i=3;i<8;i++)vals[i]=vals[i-1]*20;

	int n;
	cin>>n;
	char ch;
	cin.get(ch);
	while(n!=0)
	{
		
		vector<string> v;
		v.resize(n);
		for(int i=0;i<n;i++){getline(cin,v[i]);}
		cout<<ans(v)<<endl;
			
		cin>>n;
	cin.get(ch);
		
	}
}