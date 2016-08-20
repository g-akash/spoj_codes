#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<vector<double> > ans;
	ans.resize(2);
	ans[0].resize(6);
	ans[1].resize(6);
	ans[0][0]=0.05;
	ans[1][0]=0.2;
	vector<vector<double> > trans;
	trans.resize(2);
	trans[0].resize(2);
	trans[1].resize(2);
	trans[0][0]=0.8;
	trans[0][1]=0.2;
	trans[1][0]=0.2;
	trans[1][1]=0.8;
	vector<vector<double> >emit;
	emit.resize(2);
	emit[0].resize(4);
	emit[1].resize(4);
	emit[0][0]=0.4;
	emit[0][1]=0.1;
	emit[0][2]=0.4;
	emit[0][3]=0.1;
	emit[1][0]=0.1;
	emit[1][1]=0.4;
	emit[1][2]=0.1;
	emit[1][3]=0.4;
	string s="CGTCAG";
	for(int i=1;i<6;i++)
	{
		for(int j=0;j<2;j++)
		{
			if(s[i]=='A'){ans[j][i]=max(ans[j][i-1]*trans[j][j]*emit[j][0],ans[(j+1)%2][i-1]*trans[(j+1)%2][j]*emit[j][0]);}
			else if(s[i]=='C'){ans[j][i]=max(ans[j][i-1]*trans[j][j]*emit[j][1],ans[(j+1)%2][i-1]*trans[(j+1)%2][j]*emit[j][1]);}
			else if(s[i]=='G'){ans[j][i]=max(ans[j][i-1]*trans[j][j]*emit[j][2],ans[(j+1)%2][i-1]*trans[(j+1)%2][j]*emit[j][2]);}
			else {ans[j][i]=max(ans[j][i-1]*trans[j][j]*emit[j][3],ans[(j+1)%2][i-1]*trans[(j+1)%2][j]*emit[j][3]);}
		}
	}
	for(int i=0;i<2;i++){for(int j=0;j<6;j++)cout<<ans[i][j]<<" ";cout<<endl;
	}
}
