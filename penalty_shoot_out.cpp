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


int main()
{
	string s;
	while(cin>>s)
	{
		string s1,s2;
		s1 = s.substr(0,10);
		s2 = s.substr(10);
		int al=5,bl=5,curr=0;
		string win="";
		int score = 0;
		foi(10)
		{
			if(i%2==0)
			{
				if(s1[i]=='1')curr+=1;
				al-=1;
			}
			else
			{
				if(s1[i]=='1')curr-=1;
				bl-=1;
			}
			if(curr>bl)
			{
				win="TEAM-A";
				score=i+1;
				break;
			}
			else if(curr<=0&abs(curr)>al)
			{
				win="TEAM-B";
				score=i+1;
				break;
			}

		}
		if(win=="")
		{
			foi(10)
			{
				if(i%2==0)
				{
					if(s2[i]=='1')curr+=1;

				}
				else
				{
					if(s2[i]=='1')curr-=1;
					if(curr>0)
					{
						win="TEAM-A";
						score=i+1+10;
						break;
					}
					else if(curr<0)
					{
						win="TEAM-B";
						score=i+1+10;
						break;
					}
				}

			}
		}
		if(win=="")
		{
			cout<<"TIE"<<endl;
		}
		else cout<<win<<" "<<score<<endl;
	}
}