#include<iostream>
#include<algorithm>
#include<vector>
#include<string>


using namespace std;
int m,n,k;
vector<string> vec;
vector<vector<int> > var,myvar;

bool winner(char ch)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			var[i][j]=0;
			if(vec[i][j]==ch)var[i][j]=1;
			//if(vec[i][j]==ch){cout<<i<<" pnt "<<j<<endl;}
		}
	}
	myvar=var;
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(var[i][j]!=0)myvar[i][j]=myvar[i][j-1]+var[i][j];
			else myvar[i][j]=0;
			if(myvar[i][j]==k)return true;
		}
	}
	//cout<<"2dom"<<endl;
	myvar[0]=var[0];
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(var[i][j]!=0)if(var[i][j]!=0)myvar[i][j]=myvar[i-1][j]+var[i][j];
			else myvar[i][j]=0;
			if(myvar[i][j]==k){return true;}
		}
	}
	//cout<<"2dom"<<endl;
	myvar[0]=var[0];
	for(int i=0;i<m;i++)
	{
		myvar[i][0]=var[i][0];
	}
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(var[i][j]!=0)myvar[i][j]=myvar[i-1][j-1]+var[i][j];
			else myvar[i][j]=0;
			if(myvar[i][j]==k)return true;
		}
	}

	for(int i=0;i<m;i++)
	{
		myvar[i][0]=var[i][0];
	}
	for(int j=0;j<n;j++)
	{
		myvar[m-1][j]=var[m-1][j];
	}
	for(int i=m-2;i>=0;i--)
	{
		for(int j=1;j<n;j++)
		{
			if(var[i][j]!=0)myvar[i][j]=myvar[i+1][j-1]+var[i][j];
			else myvar[i][j]=0;
			if(myvar[i][j]==k)return true;
		}
	}

	return false;

}

string doit()
{
	
	var.resize(m);
	for(int i=0;i<m;i++)
	{
		var[i].resize(n);
	}
	if(winner('x'))return "h";
	else if(winner('o'))return "g";
	return "none";

}


int main()
{
	int wh=0,wg=0;
	int l;
	cin>>l;
	for(int i=0;i<l;i++)
	{
		cin>>n>>m>>k;
		vec.resize(m);
		for(int j=0;j<m;j++)
		{
			cin>>vec[j];
		}
		string gem = doit();
		if(gem=="h"){wh++;}
		else if(gem=="g")wg++;
	}
	cout<<wh<<":"<<wg<<endl;
}