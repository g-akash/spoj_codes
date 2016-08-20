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
		int n;
		cin>>n;
		vector<vector<char> > vec;
		vec.resize(n);
		for(int i=0;i<n;i++)
		{
			vec[i].resize(n);
		}
		int start=0,end=n-1,ts,te;
		for(int i=0;i<n;i++)
		{
			//cout<<i<<endl;
			//cout<<start<<" "<<end<<endl;
			if(i%4==0)
			{
				for(int j=start;j<=end;j++)
				{
					vec[i/2][j]='*';
				}
				ts=i/2;
				te=-1;
				for(int j=i/2+1;j<n;j++)
				{
					if(vec[j][end]=='*'){te=j;break;}
				}
				if(te==-1)te=n-1;
				else te-=2;
				start=ts;
				end=te;
			}
			else if(i%4==1)
			{
				for(int j=start;j<=end;j++)
				{
					vec[j][n-1-(i/4)*2]='*';
				}
				ts=n-1-(i/4)*2;
				te=-1;
				for(int j=n-1-(i/4)*2-1;j>=0;j--)
				{
					if(vec[end][j]=='*'){te=j;break;}
				}
				if(te==-1)te=0;
				else te+=2;
				start=ts;
				end=te;
			}
			else if(i%4==2)
			{
				for(int j=start;j>=end;j--)
				{
					vec[n-1-(i/4)*2][j]='*';
				}
				ts = n-1-(i/4)*2;
				te=-1;
				for(int j=n-1-(i/4)*2-1;j>=0;j--)
				{
					if(vec[j][end]=='*')
					{
						te=j;break;
					}
				}
				if(te==-1)te=0;
				else te+=2;
				start=ts;
				end=te;

			}
			else if(i%4==3)
			{
				for(int j=start;j>=end;j--)
				{
					vec[j][(i/4)*2]='*';
				}
				ts=(i/4)*2;
				te=-1;
				for(int j=(i/4)*2+1;j<n;j++)
				{
					if(vec[end][j]=='*')
					{
						te=j;
						break;
					}
				}
				if(te==-1)te=n-1;
				else te-=2;
				start=ts;
				end=te;

			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)if(vec[j][i]=='*')cout<<vec[j][i];else cout<<".";cout<<endl;
		}
	cout<<endl;
	}
}