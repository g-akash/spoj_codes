#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class node
{
public:
	bool var;
	node* a[10];
	node()
	{
		var=false;
		for(int i=0;i<10;i++)a[i]=0;
	}
};

bool insrt(node &hed,string s)
{
	if(hed.var==true){return true;}
	if(s.length()==0)
		{
			hed.var=true;
			
			for(int i=0;i<10;i++)if(hed.a[i]!=0)return true;
			return false;	
		}
	int nx=int(s[0])-48;
	//cout<<nx<<endl;
	if(hed.a[nx]==0)
	{
		node* nex=new node();
		//node nexx=*nex;
		hed.a[nx]=nex;
		
		return insrt(*hed.a[nx],s.substr(1));
	}
		else
		{
			//node nex=*hed.a[nx];
			return insrt(*hed.a[nx],s.substr(1));
		}
}


int main()
{

	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		node hed;

		hed.var=false;
		int n;
		cin>>n;
		bool ans=false,ansi;
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			ansi=insrt(hed,s);
			ans=ans||ansi;
		}
		if(ans)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}

}