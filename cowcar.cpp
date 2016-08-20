#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<ctime>
using namespace std;

#define ll long long int


int*  srt(int a[], int n)
{
	if(n==0)return a;
	int x[n],y[n],z[n];
	int i=0,j=0,k=0;
	for(int b=0;b<n;b++)
	{
		if(a[b]==a[0]){z[k]=a[b];k++;}
		else if(a[b]<a[0]){x[i]=a[b];i++;}
		else if(a[b]>a[0]){y[j]=a[b];j++;}
	}
	int *x1,*y1,*z1;
	if(i>0)x1=srt(x,i);
	if(j>0)y1=srt(y,j);
	int vex=0;
	for(int ver=0;ver<i;ver++)
	{
		a[vex]=x1[ver];
		vex++;
	}
	for(int ver=0;ver<k;ver++)
	{
		a[vex]=z[ver];
		vex++;
	}
	for(int ver=0;ver<j;ver++)
	{
		a[vex]=y1[ver];
		vex++;
	}
	return a;
}

int main()
{
	int a[10];
	srand(time(NULL));
	for(int i=0;i<10;i++)a[i]=rand()%100;
	int *a1;
	a1=srt(a,10);
	for(int i=0;i<10;i++)cout<<a1[i]<<endl;
}
	
