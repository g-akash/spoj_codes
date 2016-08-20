#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<string>

using namespace std;

#define ll long long int

vector<vector<string> > ans;


string addi(string s1, string s2)
{
	string var="";
	if(s1.length()<s2.length())
	{
		for(int i=0;i<s2.length()-s1.length();i++)var+="0";
			s1=var+s1;
	}
	else if(s2.length()<s1.length())
	{
		for(int i=0;i<s1.length()-s2.length();i++)var+="0";
			s2=var+s2;
	}
	var="0";
	int a,b;
	string res="";
	for(int i=s1.length()-1;i>=0;i--)
	{	
		a=(int(s1[i])-48)+(int(s2[i])-48)+stof(var);
		res=to_string(a%10)+res;
		var=to_string(a/10);
	}
	if(var!="0")
	{
		res=var+res;
	}
	return res;
}

void doit(int x, int y)
{
	if(y==0){ans[x][y]="0";return ;}
	if(ans[x][y]!="-1")return;
	if(x==0)
	{
		doit(1,y-1);
		doit(0,y-1);
		ans[x][y]=addi(ans[1][y-1],ans[0][y-1]);
	}
	else if(x==1)
	{
		doit(0,y-1);
		doit(1,y-1);
		ans[x][y]=addi(ans[0][y-1],ans[1][y-1]);
		if((y-1)%2==1)ans[x][y]=addi(ans[x][y],"1");
	}
	return;

}

int main()
{
	ans.resize(2);
	ans[0].resize(1000);
	ans[1].resize(1000);
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<1000;j++)
		{
			ans[i][j]="-1";
		}
	}
	doit(1,999);
	ll n;
	while(cin>>n)
	{
		printf("%s\n",ans[1][n].c_str());
	}
}