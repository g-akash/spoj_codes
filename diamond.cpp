#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int test=0;test<t;test++)
	{
		int n,m,k;
		cin>>n>>m>>k;
		vector<vector<char> > vec;
		vec.resize(2*k);
		for(int i=0;i<2*k;i++)vec[i].resize(2*k);
		for(int i=0;i<2*k;i++)
		{
			int a=i,b,c,d;
			if(i>=k)a=2*k-i-1;
			for(int j=0;j<2*k;j++)
			{
				//cout<<j<<" "<<k-a-1<<endl;
				if(j==(k-a-1)){if(i<k)vec[i][j]='/';else vec[i][j]='\\';}
				else if(j==k+a){if(i<k)vec[i][j]='\\';else vec[i][j]='/';}
				else if(j>k-a-1&&j<k+a)vec[i][j]='.';
				else vec[i][j]='.';
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<vec.size();k++){
			for(int j=0;j<m;j++)
			{
				for(int l=0;l<vec[0].size();l++)cout<<vec[k][l];
				
			}cout<<endl;
	}
		}cout<<endl;
	}
}