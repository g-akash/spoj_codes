#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()
#define gll(x) scanf("%d",&x)
#define sll(x) printf("%d ",x)


int main()
{
	int n,q,t,x;
	//cin>>n>>q;
	gll(n);
	gll(q);
	int p1=1,p2=2;
	for(int i=0;i<q;i++)
	{
		//cin>>t;
		gll(t);
		if(t==1)
		{
			//cin>>x;
			gll(x);
			p1--;
			p1+=x;
			p1+=n;
			p1+=n;
			p1%=n;
			p1++;
			p2--;
			p2+=x;
			p2+=n;
			p2+=n;
			p2%=n;
			p2++;
		}
		else
		{
			if(p1%2==1)p1++;
			else p1--;
			if(p2%2==1)p2++;
			else p2--;
			p1--;
			p1+=n;
			p1+=n;
			p1%=n;
			p1++;
			p2--;
			p2+=n;
			p2+=n;
			p2%=n;
			p2++;
		}
	}
	vi vec(n);
	p1--;
	p2--;
	t=1;
	x=2;
	foi(n/2)
	{
		vec[p1]=t;
		vec[p2]=x;
		t+=2;
		x+=2;
		p1=(p1+2)%n;
		p2=(p2+2)%n;
	}
	foi(n)//cout<<vec[i]<<" ";cout<<endl;
	sll(vec[i]);
	printf("\n");
}