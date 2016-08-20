	#include<iostream>
	#include<vector>
	#include<queue>
	#include<string>
	#include<algorithm>
	#include<unordered_map>
	#include<utility>

	using namespace std;


	class par
	{
	public:
		int a, b,vec;
	};

	int gcd(int a, int b)
	{
		if(a==b||a <= 0)return b;
		if(b<=0)return a;
		int A=max(a,b),B=min(a,b);
		return gcd(B,A%B);

	}
	bool something(par p, unordered_map<int,int> &m)
	{
		int ans=0,a,b;
		a=p.a;b=p.b;
		ans=(a+b)*(a+b+1)+b+1;
		if(m[ans]==0){m[ans]=1;return false;}
		return true;
	}

	int main()
	{
		int t;
		cin>>t;
		//cout<<m[2]<<endl;
		for(int i=0;i<t;i++)
		{
			int a,b,c;
			
			unordered_map<int,int> m;
			m[1]=1;
			
			cin>>a>>b>>c;
			if(c>a&&c>b){cout<<-1<<endl;continue;}
			int gd=gcd(a,b);
			//cout<<gd<<endl;
			if(c%gd!=0){cout<<-1<<endl;continue;}

			queue<par> q;
			par p,pa;
			p.a=0;p.b=0;p.vec=0;
			q.push(p);
			while(!q.empty()&&q.front().a!=c&&q.front().b!=c)
			{
				//cout<<q.front().a<<" "<<q.front().b<<" "<<q.front().vec<<endl;
				pa=q.front();
				q.pop();
				p.a=a;p.b=pa.b;p.vec=pa.vec+1;
				if(!something(p,m))q.push(p);
				//cout<<p.a<<" "<<p.b<<" hello"<<endl;
				p.a=0;p.b=pa.b;p.vec=pa.vec+1;
				if(!something(p,m))q.push(p);
				//cout<<p.a<<" "<<p.b<<" hello"<<endl;
				p.a=pa.a;p.b=b;p.vec=pa.vec+1;
				if(!something(p,m))q.push(p);
				//cout<<p.a<<" "<<p.b<<" hello"<<endl;
				p.a=pa.a;p.b=0;p.vec=pa.vec+1;
				if(!something(p,m))q.push(p);
				//cout<<p.a<<" "<<p.b<<" hello"<<endl;
				p.a=min(a,pa.a+pa.b);p.b=max(0,pa.a+pa.b-a);p.vec=pa.vec+1;
				if(!something(p,m))q.push(p);
				//cout<<p.a<<" "<<p.b<<" hello"<<endl;
				p.a=max(0,pa.a+pa.b-b);p.b=min(b,pa.a+pa.b);p.vec=pa.vec+1;
				if(!something(p,m))q.push(p);
				//cout<<p.a<<" "<<p.b<<" hello"<<endl;
			}
			if(q.empty())cout<<-1<<endl;
			else cout<<q.front().vec<<endl;
		}
	}