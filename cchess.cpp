#include<iostream>
#include<vector>

using namespace std;

class box
{
	public:
	int cst,don;
	box()
	{
		don=0;
		cst=1000000;
	}
};

int main()
{
	int a,b,c,d;
	while(cin>>a)
	{
		cin>>b>>c>>d;
		vector<vector<box> > v;
		v.resize(8);
		for(int i=0;i<8;i++)
		{
			v[i].resize(8);
		}
		v[a][b].cst=0;
		for(int i=0;i<64&&v[c][d].don==0;i++)
		{
			int mnc=10000000,x,y;
			for(int j=0;j<8;j++)
			{
				for(int k=0;k<8;k++)
				{
					if(v[j][k].don==0&&v[j][k].cst<mnc){mnc=v[j][k].cst;x=j;y=k;}
				}
			}
			//cout<<x<<" "<<y<<" "<<v[x][y].cst<<endl;
			v[x][y].don=1;
			int v1,v2;
			v1=x+2;v2=y+1;
			if(v1>=0&&v1<8&&v2>=0&&v2<8){if(v[v1][v2].cst>v[x][y].cst+x*v1+y*v2){v[v1][v2].cst=v[x][y].cst+x*v1+y*v2;}}
			v1=x+2;v2=y-1;
			if(v1>=0&&v1<8&&v2>=0&&v2<8){if(v[v1][v2].cst>v[x][y].cst+x*v1+y*v2)v[v1][v2].cst=v[x][y].cst+x*v1+y*v2;}
			v1=x-2;v2=y+1;
			if(v1>=0&&v1<8&&v2>=0&&v2<8){if(v[v1][v2].cst>v[x][y].cst+x*v1+y*v2)v[v1][v2].cst=v[x][y].cst+x*v1+y*v2;}
			v1=x-2;v2=y-1;
			if(v1>=0&&v1<8&&v2>=0&&v2<8){if(v[v1][v2].cst>v[x][y].cst+x*v1+y*v2)v[v1][v2].cst=v[x][y].cst+x*v1+y*v2;}
			v1=x+1;v2=y+2;
			if(v1>=0&&v1<8&&v2>=0&&v2<8){if(v[v1][v2].cst>v[x][y].cst+x*v1+y*v2)v[v1][v2].cst=v[x][y].cst+x*v1+y*v2;}
			v1=x+1;v2=y-2;
			if(v1>=0&&v1<8&&v2>=0&&v2<8){if(v[v1][v2].cst>v[x][y].cst+x*v1+y*v2)v[v1][v2].cst=v[x][y].cst+x*v1+y*v2;}
			v1=x-1;v2=y+2;
			if(v1>=0&&v1<8&&v2>=0&&v2<8){if(v[v1][v2].cst>v[x][y].cst+x*v1+y*v2)v[v1][v2].cst=v[x][y].cst+x*v1+y*v2;}
			v1=x-1;v2=y+-2;
			if(v1>=0&&v1<8&&v2>=0&&v2<8){if(v[v1][v2].cst>v[x][y].cst+x*v1+y*v2)v[v1][v2].cst=v[x][y].cst+x*v1+y*v2;}
		}
		if(v[c][d].cst>=1000000)cout<<-1<<endl;
		else cout<<v[c][d].cst<<endl;
	}
}	
			
	
