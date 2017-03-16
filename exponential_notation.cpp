#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()


int main()
{
	string s,base;
	cin>>s;
	int strt,end,expo;
	if(s.find(".")>=0&&s.find(".")<s.length())
	{
		strt=0;
		while(s[strt]=='0'||s[strt]=='.')
			strt++;
		int x = s.find(".");
		if(strt>x)
		{
			expo=x-strt;
			s=s.substr(strt);
			base = s.substr(0,1)+"."+s.substr(1);
			end=base.length()-1;
			while(base[end]=='0')end--;
			base=base.substr(0,end+1);
			if(base[base.length()-1]=='.')base=base.substr(0,base.length()-1);
			if(expo==0)
			{
				cout<<base<<endl;
			}
			else
			{
				cout<<base<<"E"<<expo<<endl;
			}
		}
		else
		{
			expo=x-strt-1;
			s=s.substr(strt);
			base = s.substr(0,1)+"."+s.substr(1,x-strt-1)+s.substr(x-strt+1);
			end=base.length()-1;
			while(base[end]=='0')end--;
			base=base.substr(0,end+1);
			if(base[base.length()-1]=='.')base=base.substr(0,base.length()-1);
			if(expo==0)
			{
				cout<<base<<endl;
			}
			else
			{
				cout<<base<<"E"<<expo<<endl;
			}

		}

	}	
	else
	{
		strt=0;
		while(s[strt]=='0')
			strt++;
		s=s.substr(strt);
		expo = s.length()-1;
		base = s.substr(0,1)+"."+s.substr(1);
		end=base.length()-1;
		while(base[end]=='0')end--;
		base=base.substr(0,end+1);
		if(base[base.length()-1]=='.')base=base.substr(0,base.length()-1);
		if(expo==0)
		{
			cout<<base<<endl;
		}
		else
		{
			cout<<base<<"E"<<expo<<endl;
		}
	}
}