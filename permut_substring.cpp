#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
	string a,b;
	while(cin>>a)
	{
	cin>>b;
	string x="";
	vector<int> va,vb;
	va.resize(26);
	vb.resize(26);
	for(int i=0;i<a.length();i++)
	{
		va[int(a[i])-97]++;
	}
	for(int i=0;i<b.length();i++)
	{
		vb[int(b[i])-97]++;
	}
	int var;
	for(int i=0;i<26;i++)
	{
		var=min(va[i],vb[i]);
		for(int j=0;j<var;j++)
			x+=char(i+97);
	}

	cout<<x<<endl;

	}
}