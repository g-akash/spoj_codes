#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
	int t,b,m,var,ng,x,y,nx,curr;
	vector<int> mxxx;
	mxxx.resize(10000);
	scanf("%d",&t);
	bool ans;
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&b,&m);
		ans=true;
		vector<vector<int> > v;
		v.resize(b+1);
		vector<int> visited,gender;
		visited.resize(b+1);
		gender.resize(b+1);	
		
		for(int j=0;j<m;j++)
		{
			scanf("%d%d",&x,&y);
			v[x].push_back(y);	
			v[y].push_back(x);
		}
		gender[1]=1;
		for(int j=1;j<=b&&ans;j++)
		{
			if(visited[j]==1)continue;
			curr=0;
			mxxx[curr]=j;
			curr++;
			while(curr!=0)
			{
				var=mxxx[curr-1];
				curr--;
				if(gender[var]==1)ng=2;
				else ng=1;
				
				visited[var]=1;
				int sz=v[var].size();
				for(int k=0;k<sz;k++)
				{
					nx=v[var][k];
					if(gender[nx]!=ng&&gender[nx]!=0){ans=false;}
					gender[nx]=ng;
					if(visited[nx]!=1){mxxx[curr]=nx;curr++;}
				}

			}
		}
		printf("Scenario #%d:\n",i+1);
		//cout<<"Scenario #"<<i+1<<":"<<endl;
		if(ans)printf("No suspicious bugs found!\n");//cout<<""<<endl;
		else printf("Suspicious bugs found!\n");//cout<<""<<endl;
	}
}