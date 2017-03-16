#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <algorithm>


using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >


int main()
{
	string s,a1,a2,b1,b2,b3;
	cin>>s;
	a1=s.substr(0,s.find("e"));
	a2=s.substr(s.find("e")+1);
	b1=a1.substr(0,a1.find("."));
	b2=a1.substr(a1.find(".")+1);
	while(b2.length()!=0)
	{
		if(b2[b2.length()-1]!='0')break;
		b2=b2.substr(0,b2.length()-1);
	}
	b3=a2;
	int x = stoi(b3);
	if(x<b2.length())
	{
		cout<<b1<<b2.substr(0,x)<<"."<<b2.substr(x)<<endl;
	}
	else
	{
		x-=b2.length();
		cout<<b1<<b2;
		foi(x)cout<<"0";cout<<endl;
	}
}