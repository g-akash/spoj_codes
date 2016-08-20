#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int n;
	string s,a="",b="";
	cin>>n;
	cin>>s;
	int i=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='w')a+="vv";
		else a+=s.substr(i,1);
	}
	i=0;
	while(i<a.length()-1)
	{
		if(a[i]!='v'){b+=a.substr(i,1);i+=1;}
		else if(a[i]=='v'&&a[i+1]=='v'){b+="w";i+=2;}
		else if(a[i]=='v'&&a[i+1]!='v'){b+="v";i+=1;}
	}
	if(i==a.length()-1)b+=a.substr(i,1);
	cout<<b.length()<<" "<<a.length()<<endl;
}
