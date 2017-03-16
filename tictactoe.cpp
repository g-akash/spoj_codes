#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

unordered_map<string,int> m;
stack<string> st;
bool win(string s)
{
	if(s[0]==s[1]&&s[1]==s[2]&&s[0]=='X')return true;
	if(s[3]==s[4]&&s[4]==s[5]&&s[3]=='X')return true;
	if(s[6]==s[7]&&s[7]==s[8]&&s[6]=='X')return true;
	if(s[0]==s[3]&&s[3]==s[6]&&s[0]=='X')return true;
	if(s[1]==s[4]&&s[4]==s[7]&&s[1]=='X')return true;
	if(s[2]==s[5]&&s[5]==s[8]&&s[2]=='X')return true;
	if(s[0]==s[4]&&s[4]==s[8]&&s[0]=='X')return true;
	if(s[2]==s[4]&&s[4]==s[6]&&s[2]=='X')return true;
	if(s[0]==s[1]&&s[1]==s[2]&&s[0]=='O')return true;
	if(s[3]==s[4]&&s[4]==s[5]&&s[3]=='O')return true;
	if(s[6]==s[7]&&s[7]==s[8]&&s[6]=='O')return true;
	if(s[0]==s[3]&&s[3]==s[6]&&s[0]=='O')return true;
	if(s[1]==s[4]&&s[4]==s[7]&&s[1]=='O')return true;
	if(s[2]==s[5]&&s[5]==s[8]&&s[2]=='O')return true;
	if(s[0]==s[4]&&s[4]==s[8]&&s[0]=='O')return true;
	if(s[2]==s[4]&&s[4]==s[6]&&s[2]=='O')return true;
	int cd=0;
	for(int i=0;i<9;i++)if(s[i]=='.')cd++;
	if(cd==0)return true;
	return false;
}

void doit(string s)
{
	int cx=0,cy=0;
	for(int i=0;i<9;i++)if(s[i]=='X')cx++;
	else if(s[i]=='O')cy++;
	
	for(int i=0;i<9;i++)
	{
		if(s[i]=='.')
		{
			if(cx==cy){s[i]='X';st.push(s);s[i]='.';}
			else if(cx>cy){s[i]='O';st.push(s);s[i]='.';}
			//s[i]='.';
			}
	}
	return;
}

bool cntx(string s)
{
	int cx=0,cy=0;
	for(int i=0;i<9;i++)
	{
		if(s[i]=='X')cx++;
		else if(s[i]=='O')cy++;
	}
	if(cx+cy==9)return true;
	return false;
}

int main()
{
	
	string strt=".........",var;
	for(int i=0;i<9;i++)
	{
		strt[i]='X';st.push(strt);
		strt[i]='.';
	}
	//m["........."]=1;
	//st.push(strt);
	while(!st.empty())
	{
		var=st.top();
		st.pop();
		//if(var=="XX.X.OOO.")cout<<var<<endl;
		if(m.find(var)!=m.end())continue;
		if(!win(var))doit(var);
		else
		{
			 m[var]=1;
		 }
		//if(cntx(var))m[var]=1;
		//m[var]=1;
	}
	string s;
	cin>>s;
	while(s!="end")
	{
		
		if(m.find(s)!=m.end())cout<<"valid"<<endl;
		else cout<<"invalid"<<endl;
		cin>>s;
	}
}

