#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool check_palin(string s, int pr, int nx)
{
	while(nx<s.length())
	{
		if(s[nx]!=s[pr])return false;
		nx++;
		pr--;
	}
	return true;
}

int main()
{
	int t;
	cin>>t;
	string s;
	int pr,nx;
	for(int i=0;i<t;i++)
	{
		cin>>s;
		int pos;
		bool od;
		if(s.length()%2==0){pos=(s.length()/2);od=false;nx=pos;pr=nx-1;}
		else{ pos=s.length()/2+1;od=true; nx=pos;pr=pos-2;}

		bool ans=check_palin(s,pr,nx);
		while(!ans)
		{
			if(!od)
			{
				pos++;
				od=true;
				nx=pos;
				ans=check_palin(s,pr,nx);
			}
			else
			{
				od=false;
				pr++;
				ans=check_palin(s,pr,nx);
			}

		}
		if(od)cout<<(2*pos)-1<<endl;
		else cout<<2*pos<<endl;
	}
}