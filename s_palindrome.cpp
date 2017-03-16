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
	umm(char,char) um;
	um['A']='A';
	um['H']='H';
	um['I']='I';
	um['M']='M';
	um['O']='O';
	um['T']='T';
	um['U']='U';
	um['V']='V';
	um['W']='W';
	um['X']='X';
	um['Y']='Y';
	um['b']='d';
	um['d']='b';
	um['o']='o';
	um['p']='q';
	um['q']='p';
	//um['u']='u';
	um['v']='v';
	um['w']='w';
	um['x']='x';
	string s;
	cin>>s;
	int mid;
	if(s.length()%2==0)mid=s.length()/2;
	else mid = s.length()/2+2;
	bool ispalin=true;
	for(int i=0;i<s.length();i++)
	{
		if(um.find(s[i])==um.end())
		{
			ispalin=false;
			break;
		}
		else if(um[s[i]]!=s[s.length()-1-i])
		{
			ispalin=false;
			break;
		}
	}
	if(ispalin)cout<<"TAK"<<endl;
	else cout<<"NIE"<<endl;
}