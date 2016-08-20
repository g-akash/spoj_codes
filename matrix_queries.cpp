#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> r1,r2,c1,c2;

void R(int x, int y)
{
	int a,b,c;
	a=r1[x];
	b=r1[y];
	c=r1[x];
	r1[x]=r1[y];
	r1[y]=c;
	r2[a]=y;
	r2[b]=x;
}
void C(int x, int y)
{
	int a,b,c;
	a=c1[x];
	b=c1[y];
	c=c1[x];
	c1[x]=c1[y];
	c1[y]=c;
	c2[a]=y;
	c2[b]=x;

}
void Q(int x, int y)
{
	int a,b;

	a=r1[x];
	b=c1[y];
	//cout<<a<<" "<<b<<endl;
	cout<<(a-1)*5678+b<<endl;;
}
void W(int z)
{
	int a,b;
	if(z%5678==0)
	{
		a=z/5678;
		b=5678;
	}
	else
	{
		a=z/5678+1;
		b=z%5678;
	}
	cout<<r2[a]<<" "<<c2[b]<<endl;

}

int main()
{
	r1.resize(1235);
	r2.resize(1235);
	c1.resize(5679);
	c2.resize(5679);

for(int i=0;i<=1234;i++)
{
	r1[i]=i;r2[i]=i;
	//c1[i]=i;c2[i]=i;
}
for(int i=0;i<=5678;i++)
{
	//r1[i]=i;r2[i]=i;
	c1[i]=i;c2[i]=i;
}
	char ch;
	int x,y,z;
	while(cin>>ch)
	{
		if(ch=='W'){
			cin>>z;
			W(z);
		}
		else {
			cin>>x>>y;
			if(ch=='R')R(x,y);
			else if(ch=='C')C(x,y);
			else if(ch=='Q')Q(x,y);
		}

	}

}