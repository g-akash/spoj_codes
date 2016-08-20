#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int ko=0;ko<t;ko++)
	{
		int n,m;
		cin>>n>>m;
		string s;
		vector<vector<char> > v;
		vector<vector<int> > visited;
		v.resize(n);
		visited.resize(n);
		for(int i=0;i<n;i++)
		{
			v[i].resize(m);
			visited[i].resize(m);
			cin>>s;
			for(int j=0;j<s.length();j++)
			{
				v[i][j]=s[j];
			}
		}
		
		vector<int> x,y;
		int corn=0;
		for(int i=0;i<m;i++)if(v[0][i]=='.'){corn++;x.push_back(0);y.push_back(i);}
		if(n>1)for(int i=0;i<m;i++)if(v[n-1][i]=='.'){corn++;x.push_back(n-1);y.push_back(i);}
		for(int i=1;i<n-1;i++)if(v[i][0]=='.'){corn++;x.push_back(i);y.push_back(0);}
		if(m>1)for(int i=1;i<n-1;i++)if(v[i][n-1]=='.'){corn++;x.push_back(i);y.push_back(n-1);}
		if(corn!=2)
		{
			cout<<"invalid"<<endl;
			continue;
		}
		//cout<<corn<<endl;
		bool ans=false;
		int sx=x[0],sy=y[0],ex=x[1],ey=y[1],vx,vy;
		//cout<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<endl;
		stack<int> hx,hy;
		hx.push(sx);hy.push(sy);
		while(!hx.empty())
		{
			sx=hx.top();
			sy=hy.top();
			//cout<<sx<<" "<<sy<<endl;
			visited[sx][sy]=1;
			hx.pop();
			hy.pop();
			if(sx==ex&&sy==ey){ans=true; break;}
			if(sx!=0){vx=sx-1;vy=sy;if(!visited[vx][vy]&&v[vx][vy]!='#'){hx.push(vx);hy.push(vy);}}
			if(sx!=n-1){vx=sx+1;vy=sy;if(!visited[vx][vy]&&v[vx][vy]!='#'){hx.push(vx);hy.push(vy);}}
			if(sy!=0){vx=sx;vy=sy-1;if(!visited[vx][vy]&&v[vx][vy]!='#'){hx.push(vx);hy.push(vy);}}
			if(sy!=m-1){vx=sx;vy=sy+1;if(!visited[vx][vy]&&v[vx][vy]!='#'){hx.push(vx);hy.push(vy);}}
		}
		if(ans)
		{
			cout<<"valid"<<endl;
		}
		else cout<<"invalid"<<endl;
		
		
	}
}
