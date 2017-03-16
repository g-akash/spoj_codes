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
#define si size()

int main()
{
	string s;
	cin>>s;
	int x=0,y=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='L')x--;
		if(s[i]=='U')y++;
		if(s[i]=='D')y--;
		if(s[i]=='R')x++;
	}
	x=abs(x);
	y=abs(y);
	if((x+y)%2!=0)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		cout<<(x+y)/2<<endl;
	}
}