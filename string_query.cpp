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

string s;
int bit[26][200006];
int strr[200006];


void insert(int num, int pos, int val)
{
	while(pos<200006)
	{
		bit[num][pos]+=val;
		pos+=(pos&-pos);
	}
	return;
}

int get_sum(int num, int pos)
{
	int ans = 0;
	while(pos>0)
	{
		ans+=bit[num][pos];
		pos-=(pos&-pos);
	}
	return ans;
}

void remove(int num, int k)
{
	int x = 0, y = 200005;
	while(y-x>1)
	{
		int mid = (x+y)/2;
		if(get_sum(num,mid)>=k)y=mid;
		else x = mid;
	}
	
	insert(num,y,-1);
	//cout<<char(num+97)<<" "<<k<<" "<<y<<endl;
	strr[y]=-1;
}

void print_string()
{
	for(int i=1;i<=s.length();i++)
	{
		if(strr[i]!=-1)
		{
			cout<<char(strr[i]+97);
		}
	}
	cout<<endl;
}



int main()
{
	
	cin>>s;
	foi(s.length())
	{
		insert((int)s[i]-97,i+1,1);
		strr[i+1]=(int)s[i]-97;
	}
	//print_string();
	int q;
	cin>>q;
	while(q--)
	{
		int k;
		char ch;
		cin>>k>>ch;
		remove((int)ch-97,k);
		//print_string();
	}

	print_string();
}