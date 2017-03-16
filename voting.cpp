#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

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

list<char> l;
list<char>::iterator it,d,r;
int tc=0,cr=0,cd=0;

void move_r(bool doit)
{
	if(doit)*r='0';
	if(cr==0)return;
	r++;
	while(*r!='R')
	{
		r++;
		if(r==l.end()){r=l.begin();}
	}
	return;
}

void move_d(bool doit)
{
	if(doit)*d='0';
	if(cd==0)return;
	d++;
	while(*d!='D')
	{
		d++;
		if(d==l.end())d=l.begin();
	}
	return;
}

void move_it()
{
	if(r==it)move_r(false);
	if(d==it)move_d(false);
	it++;
	if(it==l.end())it=l.begin();
	while(*it=='0')
	{
		it++;
		if(it==l.end())it=l.begin();
	}
	// r=it;
	// d=it;
	// if(r==it)move_r(false);
	// if(d==it)move_d(false);
}

int main()
{
	int n;
	string s;
	cin>>n>>s;
	
	foi(n)
	{
		tc++;
		l.pb(s[i]);
		if(s[i]=='R')cr++;
		else cd++;
	}
	
	it=l.begin();
	while(it!=l.end())
	{
		if(*it=='D')
		{
			d=it;
			break;
		}
		it++;
	}
	it = l.begin();
	while(it!=l.end())
	{
		if(*it=='R')
		{
			r=it;
			break;
		}
		it++;
	}
	it = l.begin();
	while(tc!=1&&cr!=0&&cd!=0)
	{
		//cout<<cr<<" "<<cd<<" "<<tc<<endl;
		//cout<<*it<<endl;
		if(*it=='D')
		{
			cr--;
			move_r(true);
		}
		else if(*it=='R')
		{
			cd--;
			move_d(true);
		}
		//cout<<"movingit"<<endl;
		move_it();
		tc--;
		//list<char>::iterator prnt=l.begin();
		//while(prnt!=l.end()){cout<<*prnt<<" ";prnt++;}cout<<endl;
	}
	if(cr==0)
	{
		cout<<"D"<<endl;
	}
	else cout<<"R"<<endl;



}

