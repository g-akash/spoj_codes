#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class step
{
	public:
	int stair,numstep;
	int prevstair;
};

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		vector<int> min_step;
		min_step.resize(2*n+1);
		for(int i=0;i<2*n+1;i++)min_step[i]=10000000;
		queue<step> q;
		step start,var,nex;
		start.stair=0;
		start.numstep=0;
		start.prevstair=1;
		q.push(start);
		while(q.front().stair!=n)
		{
			//cout<<q.front().stair<<endl;
			var=q.front();
			q.pop();
			if(var.numstep+1<min_step[var.stair+var.prevstair])
			{
				nex.prevstair=var.prevstair;
				nex.stair=var.stair+var.prevstair;
				nex.numstep=var.numstep+1;
				q.push(nex);
				min_step[var.stair+var.prevstair]=var.numstep+1;
			}
			if(var.numstep+1<min_step[var.stair+var.prevstair+1])
			{
				nex.prevstair=var.prevstair+1;
				nex.stair=var.stair+var.prevstair+1;
				nex.numstep=var.numstep+1;
				q.push(nex);
				min_step[var.stair+var.prevstair+1]=var.numstep+1;
			}
		}
		cout<<q.front().numstep<<endl;
	}
}
			
			
			
