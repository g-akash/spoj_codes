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

bool to_bool(char ch)
{
	return ch=='T';
}

char to_char(bool b)
{
	if(b)return 'T';
	else return 'F';
}

char do_op(char v1, char v2, int op)
{
	bool b1 = to_bool(v1), b2 = to_bool(v2);
	if(op)b1 = b1||b2;
	else b1 = b1&&b2;
	return to_char(b1);
}

int main()
{
	int t=1;
	string s;
	while(cin>>s)
	{
		if(s=="()")break;
		int op = 0;
		stack<char> st;
		int count = 0, mxcount = 0;
		foi(s.length())
		{
			if(s[i]=='(')
			{
				count+=1;
				mxcount=max(mxcount,count);
			}
			else if(s[i]==')')
			{
				count-=1;
			}
		}
		if(mxcount%2==0)
		{
			op=0;
		}
		else
		{
			op=1;
		}
		foi(s.length())
		{
			if(s[i]==')')
			{
				char val = st.top();
				st.pop();
				while(true)
				{
					if(st.top()=='(')
					{
						st.pop();
						st.push(val);
						op = (op+1)%2;
						break;
					}
					else
					{
						val = do_op(val,st.top(),op);
						st.pop();
					}

				}
			}
			else if(s[i]=='(')
			{
				st.push(s[i]);
				op = (op+1)%2;
			}
			else
			{
				st.push(s[i]);
			}
		}
		cout<<t<<". ";
		t++;
		if(st.top()=='T')cout<<"true"<<endl;
		else cout<<"false"<<endl;

	}
}