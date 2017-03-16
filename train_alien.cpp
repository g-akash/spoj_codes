#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a,b;
		cin>>a>>b;
		int currp=0,currl=0,maxp=0,maxl=0,prev=0;
		vector<int> v;
		v.resize(a);
		for(int i=0;i<a;i++){scanf("%d",&v[i]);currl+=1;
			currp+=v[i];
			while(currp>b){currl--;currp-=v[prev];prev++;}
			if(currl>maxl){maxl=currl;maxp=currp;}
			else if(currl==maxl&&currp<maxp){maxp=currp;}
		}
		
		cout<<maxp<<" "<<maxl<<endl;
	}
}