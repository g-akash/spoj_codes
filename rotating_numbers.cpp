#include<iostream>
#include<vector>
#include<algorithm>
#include<unistd.h>

using namespace std;


bool smll(vector<int> a, vector<int> b)
{
	int x,y;
	x=a.size()-1;
	while(x>=0&&a[x]==0)x--;
	y=b.size()-1;
	while(y>=0&&b[y]==0)y--;
	if(x<y)return true;
	if(x==y)
	{
		while(x>=0)
		{
			if(a[x]<b[y])return true;
			else if(a[x]>b[y])return false;
			x--;
			y--;
		}
	}
	return false;
}

vector<int> smllst(vector<vector<int> > rns)
{
	vector<int> ans;
	ans=rns[1];
	for(int i=1;i<rns.size();i++)
	{
		if(smll(rns[i],ans))ans=rns[i];
	}
	return ans;
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int b;
		cin>>b;
		vector<vector<int> > rns;
		rns.resize(b);
		for(int i=1;i<b;i++)
		{
			//cout<<i<<endl;
			int next,carry,var,comp;
			carry=0;
			next=i;
			comp=-1;
			while(2*next+carry!=comp)
			{
				//cout<<next+carry<<" "<<i<<endl;
				//sleep(1);
				//var=next+carry;
				rns[i].push_back(next);
				comp=rns[i][0];
				//cout<<comp<<endl;
				var=(2*next+carry)%b;
				carry=(2*next+carry)/b;
				next=var;
				//cout<<next<<" "<<carry<<endl;
				//next=(2*(var%b))%b+var/b;
				//carry=(2*(var%b))/b;
			}
			rns[i].push_back(next);
		}
		vector<int> ans = smllst(rns);
		for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
			cout<<endl;
	}
}