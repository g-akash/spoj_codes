#include <bits/stdc++.h>

using namespace std;

vector<int> powers,rems;
string s;

void pre_calc()
{
	powers[0]=1;
	int var=1;
	for(int i=1;i<powers.size();i++)
	{
		var*=10;
		var=var%7;
		powers[i]=var;
	}
	var=0;
	rems[0]=0;
	for(int i=0;i<s.size();i++)
	{
		var=var*10+stoi(s.substr(i,1));
		var=var%7;
		rems[i+1]=var;
	}
}

int main()
{
	powers.resize(100005);
	rems.resize(100005);
	cin>>s;
	pre_calc();
	//for(int i=0;i<=s.size();i++)cout<<rems[i]<<endl;
	int q;
	cin>>q;
	int l,r;
	for(int i=0;i<q;i++)
	{
		cin>>l>>r;
		int var=rems[r]-rems[l-1]*powers[r+1-l];
		//cout<<rems[r]<<" "<<rems[l-1]*powers[r+1-l]<<endl;
		var=var%7;
		//cout<<var<<endl;
		if(var==0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}