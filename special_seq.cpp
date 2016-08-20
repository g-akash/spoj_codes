#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
bool poss;

void doit(int start, int pval, int res)
{
	//cout<<start<<" "<<pval<<" "<<res<<endl;
	int a,b,c,d,e,f;
	a=v.size()-start;
	if(a==1)
	{
		if(res!=pval+1&&res!=pval-1){poss=false;return;}
		v[start]=res;
		return;
	}
	b=(a*(2*(pval+1)+(a-1)*1))/2;
	c=(a*(2*(pval-1)-(a-1)))/2;
	if(res>b||res<c)
	{
		//cout<<"okay"<<endl;
		poss=false;
		return;
		}
	start++;
	a=v.size()-start;
	d=pval;
	pval++;
	b=(a*(2*(pval+1)+(a-1)*1))/2;
	c=(a*(2*(pval-1)-(a-1)))/2;
	if(res-pval<=b&&res-pval>=c)
	{
		v[start-1]=pval;
		doit(start,pval,res-pval);
		return;
	}
	pval-=2;
	b=(a*(2*(pval+1)+(a-1)*1))/2;
	c=(a*(2*(pval-1)-(a-1)))/2;
	if(res-pval<=b&&res-pval>=c)
	{
		v[start-1]=pval;
		doit(start,pval,res-pval);
		return;
	}
	poss=false;
	return;
}
	

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		poss=true;
		int n,s;
		cin>>n>>s;
		v.resize(n);
		v[0]=0;
		doit(1,0,s);
		if(poss){
		for(int i=0;i<n;i++)
		{
			cout<<v[i]<<endl;
		}
		cout<<endl;}
		else cout<<"NO"<<endl<<endl;
	}
}
		
