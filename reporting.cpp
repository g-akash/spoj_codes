#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <math.h>


using namespace std;


#define ll long long int
#define ull unsigned long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()
#define MOD 1000000007


class opr{
public:
	int r,t;
};

int main(){
	int n,m;
	cin>>n>>m;
	vi vec(n),mx(m+2);
	vector<opr> op(m+2);
	foi(n){
		cin>>vec[i];
	}
	foi(m){
		cin>>op[i+1].t>>op[i+1].r;
	}
	op[0].t=1;
	op[0].r=0;
	op[m+1].t=1;
	op[m+1].r=0;
	int mxx=0,pos=m+1;
	for(int i=m;i>=0;i--){
		if(op[i+1].r>mxx){
			mxx=op[i+1].r;
			pos=i+1;
		}
		mx[i]=pos;

	}
	vi srt(vec.begin(),vec.begin()+mxx),ans(mxx);
	sort(srt.begin(),srt.end());
	int x=0,y=srt.size()-1,ps=srt.size()-1;
	int nx=0,a,b,c;
	while(x<=y){
		nx=mx[nx];
		a=mx[nx];
		b=op[nx].r-op[a].r;
		if(op[nx].t==1){
			while(b>0){
				ans[ps]=srt[y];
				ps--;
				y--;
				b--;
			}
		}
		else{
			while(b>0){
				ans[ps]=srt[x];
				ps--;
				x++;
				b--;
			}
		}
	}
	for(int i=0;i<srt.size();i++)cout<<ans[i]<<" ";for(int i=ans.size();i<vec.size();i++)cout<<vec[i]<<" ";cout<<endl;

}