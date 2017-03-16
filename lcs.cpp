#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

string s1,s2;

vector<vector<int> > ans;

int finans(int m, int n)
{
	if(m==0)return n*30;
	else if(n==0)return m*15;
	else if(ans[m][n]>=0)return ans[m][n];
	else
	{
		int a,b,c;
		if(s1[m-1]==s2[n-1]){ans[m][n]=finans(m-1,n-1);return ans[m][n];}
		else
		{
			b=finans(m-1,n);
			c=finans(m,n-1);
			if(b+15<=c+30){ans[m][n]=b+15;return ans[m][n];}
			else{ans[m][n]=c+30;return ans[m][n];}
		}
	}
}

int main()
{
	cin>>s1;
	while(s1[0]!='#')
	{
		cin>>s2;
		ans.resize(s1.length()+1);
		for(int i=0;i<=s1.length();i++)ans[i].resize(s2.length()+1);
		for(int i=0;i<=s1.length();i++)
		{
			for(int j=0;j<=s2.length();j++)ans[i][j]=-1;
		}

		cout<<finans(s1.length(),s2.length())<<endl;
		cin>>s1;
	}
}