#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

class data
{
	public:
	string num;
	int rem;
};

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		queue<data> q;
		data d,var;
		d.num="1";
		d.rem=1;
		q.push(d);
		vector<int> rems;
		rems.resize(n);
		rems[1]=1;
		while(!q.empty())
		{
			d=q.front();
			q.pop();
			rems[d.rem]=1;
			if(d.rem==0){cout<<d.num<<endl;break;}
			var.num=d.num+"0";
			var.rem=(d.rem*10)%n;
			if(!rems[var.rem])q.push(var);
			var.num=d.num+"1";
			var.rem=(d.rem*10+1)%n;
			if(!rems[var.rem])q.push(var);
		}
	}
}
