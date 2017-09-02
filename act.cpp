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


int n;
string s;
vi curr_points;
vi games_won;
vi sets_won;
vi matches_won;

int get_int(char ch)
{
	return (int)ch-65;
}

void match_won(int x)
{
	if(sets_won[x]>=3)
	{
		matches_won[x]+=1;
	}
	return;
}

void set_won(int x)
{
	bool winning = true;
	int win_sets=2;
	foi(n)
	{
		curr_points[i]=0;
	}
	if(games_won[x]<6)
	{
		winning=false;
		return;
	}
	foi(n)
	{
		if(i!=x)
		{
			if(games_won[i]>games_won[x]-2)winning=false;
			if(games_won[i]!=0)
				{
					//cout<<"this guy won non zero games "<<i<<endl;
					win_sets=1;
				}
		}
	}
	
	//cout<<games_won[x]<<" "<<winning<<" "<<win_sets<<endl;
	if(winning)
	{
		sets_won[x]+=win_sets;

		foi(n)
		{
			games_won[i]=0;
		}
		match_won(x);
	}
}


void game_won(int x)
{
	bool rule1 = true, rule2 = true, rule3 = false;
	if(curr_points[x]!=3)rule1 = false;
	if(curr_points[x]!=4) rule2 = false;
	vi r3;
	foi(n)
	{
		if(i!=x)
		{
			if(curr_points[i]>2)rule1 = false;
			if(curr_points[i]==4)
			{
				rule3 = true;
				r3.pb(i);
			}
		}
	}
	//cout<<curr_points[x]<<" "<<rule1<<" "<<rule2<<" "<<rule3<<endl;
	if(rule1)
	{
		games_won[x]+=1;
		set_won(x);

	}
	else if(rule2)
	{
		games_won[x]+=1;
		set_won(x);
	}
	else if(rule3)
	{
		foi(r3.size())
		{
			curr_points[r3[i]]-=1;
		}
		curr_points[x]+=1;
		game_won(x);
	}
	return;
}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n>>s;
		// cout<<s[s.length()-1]<<endl;
		curr_points.resize(n);
		games_won.resize(n);
		sets_won.resize(n);
		matches_won.resize(n);
		foi(n)
		{
			curr_points[i] = 0;
			games_won[i] = 0;
			sets_won[i] = 0;
			matches_won[i]=0;
		}
		//cout<<get_int('B')<<endl;
		for(int i=0;i<s.length();i++)
		{
			curr_points[get_int(s[i])]+=1;
			game_won(get_int(s[i]));
			//cout<<curr_points[get_int(s[i])];
			//cout<<matches_won[get_int(s[i])];
			if(matches_won[get_int(s[i])]!=0)
			{
				cout<<s[i]<<endl;
				break;
			}
			else if(i==s.length()-1)
			{
				cout<<s[i]<<endl;
				break;
			}

		}

	}
}