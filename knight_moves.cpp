#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<string>




using namespace std;
//string s[9]={0,a,b,c,d,e,f};


bool chk(int x, int y)
{
	if(x>0&&x<9&&y>0&&y<9)return true;
	return false;
}

int conv(string s)
{
	int ans=0;
	if(s[0]=='a')ans+=10;
	else if(s[0]=='b')ans+=20;
	else if(s[0]=='c')ans+=30;
	else if(s[0]=='d')ans+=40;
	else if(s[0]=='e')ans+=50;
	else if(s[0]=='f')ans+=60;
	else if(s[0]=='g')ans+=70;
	else if(s[0]=='h')ans+=80;
	ans+=stoi(s.substr(1,1));
	//cout<<ans<<endl;
	return ans;
}

int	 main()
{
	int t;
	cin>>t;
	for(int xo=0;xo<t;xo++)
	{
		string s1,s2;
		cin>>s1>>s2;
		int strt=conv(s1),endi=conv(s2),var,x,y,mov;
		queue<int> q;
		q.push(strt);
		unordered_map<int,int> m;
		m[strt]=0;
		while(q.front()!=endi)
		{
			var=q.front();
			q.pop();
			x=var/10;
			y=var%10;
			mov=m[var];
			if(chk(x+2,y+1)&&(m.find(var+21)==m.end()||m[var+21]>mov+1)){q.push(var+21);m[var+21]=mov+1;}
			if(chk(x+2,y-1)&&(m.find(var+19)==m.end()||m[var+19]>mov+1)){q.push(var+19);m[var+19]=mov+1;}
			if(chk(x-2,y-1)&&(m.find(var-21)==m.end()||m[var-21]>mov+1)){q.push(var-21);m[var-21]=mov+1;}
			if(chk(x-2,y+1)&&(m.find(var-19)==m.end()||m[var-19]>mov+1)){q.push(var-19);m[var-19]=mov+1;}
			if(chk(x+1,y+2)&&(m.find(var+12)==m.end()||m[var+12]>mov+1)){q.push(var+12);m[var+12]=mov+1;}
			if(chk(x+1,y-2)&&(m.find(var+8)==m.end()||m[var+8]>mov+1)){q.push(var+8);m[var+8]=mov+1;}
			if(chk(x-1,y-2)&&(m.find(var-12)==m.end()||m[var-12]>mov+1)){q.push(var-12);m[var-12]=mov+1;}
			if(chk(x-1,y+2)&&(m.find(var-8)==m.end()||m[var-8]>mov+1)){q.push(var-8);m[var-8]=mov+1;}
		}
		cout<<m[endi]<<endl;

	}
}