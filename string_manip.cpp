#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int manip(string s)
{
	vector<int> v1,v2;
	v1.resize(s.length());
	v2.resize(s.length());
	if(int(s[0])>=97){v1[0]=0;v2[0]=1;}
	else {v1[0]=1;v2[0]=0;}
	for(int i=1;i<s.length();i++)
	{
		if(int(s[i])>=97){v1[i]=v2[i-1];v2[i]=v1[i-1]+1;}
			else{v2[i]=v1[i-1];v1[i]=v2[i-1]+1;}
	}
	return min(v1[s.length()-1],v2[s.length()-1]);
}


int main()
{
	string s;
	while(cin>>s)
	{
		cout<<manip(s)<<endl;
	}
}