#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main()
{
	int n,k,nk;
	cin>>n>>k;
	nk=n/k;
	vector<int> va,vb,vc;
	va.resize(k);
	vb.resize(k);
	vc.resize(k);
	char ch;
	for(int i=0;i<nk;i++)
	{
		for(int i=0;i<k;i++)
		{cin>>ch;
		if(ch=='a')va[i]++;
		if(ch=='b')vb[i]++;
		if(ch=='c')vc[i]++;
	}
	}
	string ans="";
	for(int i=0;i<k;i++)
	{
		if(va[i]>=vb[i]&&va[i]>=vc[i])ans+="a";
		else if(vb[i]>va[i]&&vb[i]>=vc[i])ans+="b";
		else ans+="c";
	}
	cout<<ans<<endl;
}
	
