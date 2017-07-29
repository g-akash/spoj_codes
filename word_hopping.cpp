#include <iostream>
#include <vector>
//#include <unordered_map>
#include <string>
#include <math.h>
//#include <map>
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
vector<string> words;
vvi hop;

bool del(string s1, string s2)
{
	if(s1.length()<=s2.length())return false;
	int x=0,y=0;
	int diff=0;
	while(x<s1.length()&&y<s2.length())
	{
		if(s1[x]==s2[y])
		{
			x++;
			y++;
		}
		else
		{
			x++;
			diff++;
		}
	}
	if(diff<1&&x==s1.length()-1){x++;diff++;}
	if(diff>1||x<s1.length()||y<s2.length())return false;
	return true;
}

bool repl(string s1, string s2)
{
	if(s1.length()!=s2.length())
	{
		return false;
	}
	vi chrs(256);
	int count=0;
	for(int i=s1.length()-1;i>=0;i--)
	{
		if(s1[i]==s2[i])
		{
			chrs[int(s1[i])]=1;
			continue;
		}
		if(chrs[int(s2[i])]==1&&count==0&&int(s2[i])>int(s1[i]))
		{
			count++;
			chrs[int(s1[i])]=1;
			continue;
		}
		return false;
	}
	return true;
}

int get_max_path(int x)
{
	int ans=0;
	for(int i=0;i<hop[x].size();i++)
	{
		ans=max(ans,get_max_path(hop[x][i]));
	}
	ans+=1;
	return ans;
}



int main()
{
	//cout<<"kk"<<endl;
	//cout<<del("abacd","abcd")<<endl;
	cin>>n;
	words.resize(n);
	foi(n)
	{
		cin>>words[i];
	}
	hop.resize(n);
	foi(n)
	{
		foj(n)
		{
			if(i==j)continue;
			if(del(words[i],words[j])||repl(words[i],words[j]))
			{
				hop[i].pb(j);
			}
		}
	}
	int ans=0;
	
	foi(n)
	{
		ans=max(ans,get_max_path(i));
	}
	cout<<ans<<endl;

}