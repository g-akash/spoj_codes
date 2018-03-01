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


vll sum;


int get_sum(int a, int b)
{
	if(a==0)return sum[b];
	else return sum[b]-sum[a-1];
}

umm(int,int) um;


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		um.clear();
		sum.resize(n);
		sum[0]=(ll)(int(s[0]));
		for(int i=1;i<n;i++)
		{
			sum[i]=sum[i-1]+(ll)(int(s[i]));
		}
		foi(q)
		{
			int p,k;
			cin>>p>>k;
			int val = p*1000000+k;
			if(um.find(val)!=um.end())
			{
				cout<<um[val]<<endl;
				continue;
			}
			//string tmp = s.substr(0,p);
			string ans = "";
			int var = 0;
			for(int i=1;i<=p;i++)
			{
				if(get_sum(0,i-1)!=get_sum(p-i,p-1))continue;
				string s1 = s.substr(0,i);
				string s2 = s.substr(p-i,i);
				if(s1==s2)
				{
					var+=1;
					int ver = p*1000000+var;
					um[ver]=s1.length();
					
				}
			}
			if(um.find(val)!=um.end())cout<<um[val]<<endl;
			else cout<<-1<<endl;
			
		}
	}
}
