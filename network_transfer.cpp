#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>

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


vvi visited;
vector<string> vec;
int n,m;

class pos
{
public:
	int a,b;

	bool operator ==(pos const y)const
	{
		if(a==y.a&&b==y.b)return true;
		return false;
	}
};

pos st,ed;

string visit(pos curr)
{
	//cout<<curr.a<<" "<<curr.b<<endl;
	if(curr==ed)return "";
	//cout<<curr.a<<" "<<curr.b<<" "<<ed.a<<" "<<ed.b<<endl;
	int a=curr.a,b=curr.b;
	pos nex;
	string res1="",res2="",res3="",res4="";
	visited[a][b]=1;
	if(curr.a<ed.a){
		if(a-1>=0)
		{
			if(visited[a-1][b]!=1&&vec[a-1][b]!='#')
			{
				nex.a=a-1,nex.b=b;
				res2="U"+visit(nex);
			}
		}

		
		if(b+1<m)
		{
			if(visited[a][b+1]!=1&&vec[a][b+1]!='#')
			{
				nex.a=a,nex.b=b+1;
				res3="R"+visit(nex);
			}
		}
		if(b-1>=0)
		{
			if(visited[a][b-1]!=1&&vec[a][b-1]!='#')
			{
				nex.a=a,nex.b=b-1;
				res4="L"+visit(nex);
			}
		}
		if(a+1<n)
		{
			if(visited[a+1][b]!=1&&vec[a+1][b]!='#')
			{
				nex.a=a+1,nex.b=b;
				res1="D"+visit(nex);
	
			}
		}
	}
	else
	{
		if(a+1<n)
		{
			if(visited[a+1][b]!=1&&vec[a+1][b]!='#')
			{
				nex.a=a+1,nex.b=b;
				res1="D"+visit(nex);
	
			}
		}
		if(b+1<m)
		{
			if(visited[a][b+1]!=1&&vec[a][b+1]!='#')
			{
				nex.a=a,nex.b=b+1;
				res3="R"+visit(nex);
			}
		}
		if(b-1>=0)
		{
			if(visited[a][b-1]!=1&&vec[a][b-1]!='#')
			{
				nex.a=a,nex.b=b-1;
				res4="L"+visit(nex);
			}
		}
		if(a-1>=0)
		{
			if(visited[a-1][b]!=1&&vec[a-1][b]!='#')
			{
				nex.a=a-1,nex.b=b;
				res2="U"+visit(nex);
			}
		}
		
	}
	//visited[a][b]=0;
	int l1=res1.length(),l2=res2.length(),l3=res3.length(),l4=res4.length();
	if(res1=="DNOPE")l1=0;
	if(res2=="UNOPE")l2=0;
	if(res3=="RNOPE")l3=0;
	if(res4=="LNOPE")l4=0;
	if(l1==0&&l2==0&&l3==0&&l4==0)return "NOPE";
	if(l1>=max(l2,max(l3,l4)))return res1;
	if(l2>=max(l1,max(l3,l4)))return res2;
	if(l3>=max(l2,max(l1,l4)))return res3;
	return res4;

	return "";
}

string get_res()
{
	int a=st.a,b=st.b;
	pos curr;
	string res1,res2,res3,res4;
	if(a+1<n)
	{
		if(vec[a+1][b]!='#')
			{
				foi(n){foj(m)visited[i][j]=0;}
				curr.a=a+1;curr.b=b;
				visited[a][b]=1;
				res1="D"+visit(curr);
			}

	}
	if(a-1>=0)
	{
		if(vec[a-1][b]!='#')
			{
				foi(n){foj(m)visited[i][j]=0;}
				curr.a=a-1;curr.b=b;
				visited[a][b]=1;
				res2="U"+visit(curr);
			}
	}
	if(b+1<m)
	{
		if(vec[a][b+1]!='#')
			{
				foi(n){foj(m)visited[i][j]=0;}
				curr.a=a;curr.b=b+1;
				visited[a][b]=1;
				res3="R"+visit(curr);
			}
	}
	if(b-1>=0)
	{
		if(vec[a][b-1]!='#')
			{
				foi(n){foj(m)visited[i][j]=0;}
				curr.a=a;curr.b=b-1;
				visited[a][b]=1;
				res4="L"+visit(curr);
			}
	}
	int l1=res1.length(),l2=res2.length(),l3=res3.length(),l4=res4.length();
	//cout<<res1<<" "<<res2<<" "<<res3<<" "<<res4<<endl;
	if(res1=="DNOPE")l1=0;
	if(res2=="UNOPE")l2=0;
	if(res3=="RNOPE")l3=0;
	if(res4=="LNOPE")l4=0;
	if(l1==0&&l2==0&&l3==0&&l4==0)return "NOPE";
	if(l1>=max(l2,max(l3,l4)))return res1;
	if(l2>=max(l1,max(l3,l4)))return res2;
	if(l3>=max(l2,max(l1,l4)))return res3;
	return res4;
}

int main()
{
	cin>>n>>m;
	visited.resize(n);
	foi(n)visited[i].resize(m);
	vec.resize(n);
	foi(n)cin>>vec[i];
	foi(n)
	{
		foj(m)
		{
			if(vec[i][j]=='S'){st.a=i;st.b=j;}
			else if(vec[i][j]=='F'){ed.a=i;ed.b=j;}
		}
	}
	cout<<get_res()<<endl;
}