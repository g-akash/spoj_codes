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



string str(char ch)
{
	string s(1,ch);
	return s;
}

int main()
{
	string s;
	char ch,prev='\n';
	string non_rep="";
	int curr=0;
	while(cin.get(ch))
	{	
		//s=s+"~&";
		if(ch=='\n')
		{
			if(prev=='\n')
			{
				cout<<ch;
				continue;
			}
			if(non_rep=="")
			{
			if(curr>1)cout<<curr<<prev;
			else 
			{
				if(prev=='1')cout<<"1111";
				else
				{
					cout<<"1"<<prev<<"1";
				}
			}
			}
			else
			{
				if(curr>1)
				{
					cout<<non_rep+"1"<<curr<<prev;
				}
				else
				{
					if(prev=='1')cout<<non_rep<<"111";
					else	cout<<non_rep<<prev<<"1";
				}
			}
			cout<<endl;
			prev = ch;
			non_rep="";
			curr=0;
			continue;
		}
		if(prev=='\n')
		{
			prev = ch;
			curr=1;
			continue;
		}
		
		
		
		{
			if(ch!=prev||curr==9)
			{
				//cout<<s[i]<<i<<endl;
				if(curr>1)
				{
					//cout<<s[i]<<" ss "<<i<<endl;
					if(non_rep=="")
					{
						cout<<curr<<prev;
					}
					else
					{
						cout<<non_rep<<"1"<<curr<<prev;
						non_rep="";

					}
				}
				else
				{
					if(non_rep=="")
					{
						non_rep="1";
						if(prev=='1')non_rep+="11";
						else non_rep+=str(prev);
					}
					else
					{
						if(prev=='1')non_rep+="11";
						else non_rep+=str(prev);
					}
				}
				curr=1;
			}
			else
			{
				curr+=1;
			}
			prev=ch;
		}
		//cout<<curr<<s[s.length()-1];
		
		//cout<<endl;
	}
}