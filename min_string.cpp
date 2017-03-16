#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define vi vector<ll>


int main()
{
	string s;
	cin>>s;
	vector<char> vec;
	vec.resize(s.length());
	int strt=-1,end=s.length();
	foi(s.length())
	{
		if(s[i]=='a')continue;
		strt=i;
		break;
	}
	for(int i=strt+1;i<s.length();i++)
	{
		if(s[i]=='a')
		{
			end=i;
			break;
		}
	}
	if(strt==-1)
	{
		strt=s.length()-1;
		end=s.length();
	}
	foi(s.length())
	{
		vec[i]=s[i];
	}
	for(int i=strt;i<end;i++)
	{
		int x=int(s[i]);
		x-=97;
		x+=25;
		x%=26;
		x+=97;
		vec[i]=char(x);
	}
	foi(vec.size())
	{
		cout<<vec[i];
	}
	cout<<endl;
}