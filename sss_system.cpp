#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()


int val(char ch)
{
	if(int(ch)>=65)return int(ch)-65+10;
	else return int(ch)-48;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		char ch='0';
		foi(s.length())if(int(s[i])>int(ch))ch=s[i];
		int minbase=0;
		if(int(ch)>=65)
		{
			minbase=int(ch)-65+11;
		}
		else minbase=int(ch)-47;
		minbase=max(minbase,2);
		//cout<<minbase<<endl;
		bool sol=false;
		for(int i=minbase;i<=36;i++)
		{
			int rem=0,curr=0;
			foj(s.length())
			{
				//cout<<curr<<endl;
				curr=curr*i+val(s[j]);
				curr=curr%(i-1);
			}
			if(curr==0)
			{
				cout<<i<<endl;
				sol=true;
				break;
			}
		}
		if(!sol)cout<<"No solution."<<endl;
	}
}