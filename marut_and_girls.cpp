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
#include <sstream>
#include <iterator>

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


int main()
{
	int m,n;
	string var;
	scanf("%d",&m);
	umm(string,int) vec;
	foi(m)
	{
		cin>>var;
		vec[var]=1;
	}
	scanf("%d",&n);
	char ch;
	cin.get(ch);
	char sh[6000];
	string s;
	int ans=0;
	foi(n)
	{
		scanf(" %[^\n]",sh);
		int curr=0;
		int count=0;
		s = string(sh);
		for(int i=0;i<6000;i++)
		{
			if(s[i]==' '||s[i]=='\0')
			{
				if(vec.find(s.substr(curr,i-curr))!=vec.end())count++;
				curr = i+1;
			}
			if(s[i]=='\0')break;
		}
		//if(s[s.length()-1]!=' '&&vec.find(s.substr(curr))!=vec.end())count++;
		//cout<<s<<" "<<count<<endl;
        if(count>=m)ans++;
	}
	printf("%d\n",ans);
}