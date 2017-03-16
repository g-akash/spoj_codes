#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

#define ll long long int


class grps
{
public:
	ll ts;
	int cnt;

	bool operator <(const grps& q)
	{
		if(ts<q.ts)return true;
		if(ts==q.ts&&cnt<q.cnt)return true;
		return false;
	}
};

bool comp(grps p, grps q)
{
	if(p.ts<q.ts)return true;
	if(p.ts==q.ts&&p.cnt<=q.cnt)return true;
	return false;
}

vector<grps> frst,scnd;

vector<ll> f,s;
ll sz;
int n;

void doit()
{
	ll a,b,c;
	grps mv;
	ll siz =(ll)pow(2,n/2);
	frst.resize(siz);
	scnd.resize(siz);
	ll var1=0,var2=0;
	int pcnt;
	for(int i=0;i<siz;i++)
	{
		pcnt=0;
		a=i;
		var1=0;
		var2=0;
		for(int j=0;j<n/2;j++)
		{
			b=a&0x1;
			a=a>>1;
			pcnt+=b;
			var1+=b*f[j];
			var2+=b*s[j];
		}
		mv.ts = var1;
		mv.cnt=pcnt;
		frst[i]=mv;
		mv.ts = var2;
		scnd[i]=mv;
	}
	return;
}

int main()
{
	ll t;
	cin>>t;
	for(int ko=0;ko<t;ko++)
	{
		
		cin>>n;
		f.resize(n/2);
		s.resize(n-n/2);
		sz=0;
		for(int i=0;i<n/2;i++){cin>>f[i];sz+=f[i];}
		for(int i=0;i<n-n/2;i++){cin>>s[i];sz+=s[i];}
		//for(int i=0;i<f.size();i++)cout<<f[i]<<" ";cout<<endl;
		//for(int i=0;i<s.size();i++)cout<<s[i]<<" ";cout<<endl;
		if(n%2==1||sz%2==1){cout<<"Case "<<ko+1<<": No"<<endl; continue;}
		sz/=2;
		doit();
		//sort(frst.begin(),frst.end(),comp);
		sort(scnd.begin(),scnd.end(),comp);
		//for(int i=0;i<frst.size();i++)cout<<frst[i].ts<<" "<<frst[i].cnt<<" ";cout<<endl;
		//for(int i=0;i<scnd.size();i++)cout<<scnd[i].ts<<" "<<scnd[i].cnt<<" ";cout<<endl;
		ll x=0,y=scnd.size()-2;
		int pcnt = n/2;
		grps vr1,vr2;
		for(int i=0;i<frst.size();i++)
		{
			vr1=frst[i];
			vr2.ts= sz-frst[i].ts;
			vr2.cnt = n/2 - vr1.cnt;
			//cout<<vr1.ts<<" hh "<<vr1.cnt<<endl;
			//cout<<vr2.ts<<" bb "<<vr2.cnt<<endl;
			vr2 = *(lower_bound(scnd.begin(),scnd.end(),vr2));
			//cout<<vr1.ts<<" hh "<<vr1.cnt<<endl;
			////cout<<vr2.ts<<" bb "<<vr2.cnt<<endl;
			//cout<<vr1.ts+vr2.ts<<" "<<vr1.cnt+vr2.cnt<<endl;
			if(vr1.ts+vr2.ts==sz&&vr1.cnt+vr2.cnt==n/2)break;
		}
		if(vr1.ts+vr2.ts==sz&&vr1.cnt+vr2.cnt==n/2)
		{
			cout<<"Case "<<ko+1<<": Yes"<<endl;
		}
		else
			cout<<"Case "<<ko+1<<": No"<<endl;

	}

}