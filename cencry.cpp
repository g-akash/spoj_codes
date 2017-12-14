#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

string str1 = "aeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiouaeiou";
string str2 = "bcdfghjklmnpqrstvwxyzbcdfghjklmnpqrstvwxyzbcdfghjklmnpqrstvwxyzbcdfghjklmnpqrstvwxyzbcdfghjklmnpqrstvwxyz";

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		vi vec(26),diff(26);
		vec[0]=0;diff[0]=5;
		vec[4]=1;diff[4]=5;
		vec[8]=2;diff[8]=5;
		vec[14]=3;diff[14]=5;
		vec[20]=4;diff[20]=5;
		int curr=0;
		foi1(25)
		{
			if(vec[i]>0)continue;
			vec[i]=curr;
			curr++;
			diff[i]=21;
		}
		foi(str.length())
		{
			int pos = (int)str[i]-97;
			if(diff[pos]==5)
			{
				cout<<str2[vec[pos]];
				vec[pos]+=5;
				vec[pos]%=105;
			}
			else
			{
				cout<<str1[vec[pos]];
				vec[pos]+=21;
				vec[pos]%=105;
			}
		}
		cout<<endl;

	}
}