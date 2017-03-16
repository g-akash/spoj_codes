#include<bits/stdc++.h>

using namespace std;

class request
{
public:
	int start_time,end_time,profit;
};

vector<request> requests;
vector<int> profits;

int calculate_profit(int n)
{
	if(n>=requests.size())return 0;
	if(profits[n]>=0)return profits[n];
	int profit1=calculate_profit(n+1);
	int next_req=requests.size();
	for(int i=n+1;i<requests.size();i++)
	{
		if(requests[i].start_time>=requests[n].end_time)
		{
			next_req=i;
			break;
		}
	}
	//cout<<next_req<<" "<<n<<endl;
	int profit2=calculate_profit(next_req)+requests[n].profit;
	profits[n]=max(profit1,profit2);
	return profits[n];
}

bool comp(request p, request q)
{
	if(p.start_time<q.start_time)return true;
	return false;
}


int main()
{
	int t;
	cin>>t;
	for(int test=0;test<t;test++)
	{
		int n;
		cin>>n;
		requests.resize(n);
		profits.resize(n);
		int duration;
		for(int i=0;i<n;i++)
		{
			cin>>requests[i].start_time>>duration>>requests[i].profit;
			requests[i].end_time=requests[i].start_time+duration;
			profits[i]=-1;
		}
		sort(requests.begin(),requests.end(),comp);
		for(int i=0;i<n;i++)
		{
			//cout<<requests[i].start_time<<" "<<requests[i].end_time<<" "<<requests[i].profit<<endl;
		}
		cout<<calculate_profit(0)<<endl;
	}
}