#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
vector<int> v;
class inti
{
public:
	int a,cost;
};

void fac()
{
	v[0]=1;
	v[1]=1;
	
	for(int i=2;i<10005;i++)
	{
		
		for(int j=2*i;j<10005;j+=i)v[j]=1;
	}
return;
}



int main()
{
	v.resize(10005);
	
	
	fac();
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a,b,v1,v2,c;
		cin>>a>>b;
		vector<int> vx;
		vx.resize(10005);
		queue<inti> q;
		inti x;
		x.a=a;x.cost=0;
		q.push(x);
		while(!q.empty()&&q.front().a!=b)
		{
			v1=q.front().a;

			vx[v1]=1;
			c=q.front().cost;
			c++;
			q.pop();
	//		cout<<v1<<endl;
			for(int j=1;j<=9;j++)
			{
				v2=j*1000+v1%1000;
				if(!v[v2]&&!vx[v2]){x.a=v2;x.cost=c;q.push(x);}
				v2=j*100+(v1/1000)*1000+v1%100;
				if(!v[v2]&&!vx[v2]){x.a=v2;x.cost=c;q.push(x);}
				v2=j*10+(v1/100)*100+v1%10;
				if(!v[v2]&&!vx[v2]){x.a=v2;x.cost=c;q.push(x);}
				v2=j+(v1/10)*10;
				if(!v[v2]&&!vx[v2]){x.a=v2;x.cost=c;q.push(x);}
			}
		v2=(v1/1000)*1000+v1%100;
				if(!v[v2]&&!vx[v2]){x.a=v2;x.cost=c;q.push(x);}
				v2=(v1/100)*100+v1%10;
				if(!v[v2]&&!vx[v2]){x.a=v2;x.cost=c;q.push(x);}
				v2=(v1/10)*10;
				if(!v[v2]&&!vx[v2]){x.a=v2;x.cost=c;q.push(x);}
			
			//do something
		}
		if(q.empty()){cout<<"Impossible"<<endl;}
		else cout<<q.front().cost<<endl;
	}

}