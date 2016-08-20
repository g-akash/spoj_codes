#include<math.h>
#include<stdio.h>

using namespace std;



int main()
{
	
	int t;
	scanf("%d",&t);
	float h,p,a,f;
	//cin>>t;
	for(int i=0;i<t;i++)
	{
		
		scanf("%f",&h);
		scanf("%f",&p);
		scanf("%f",&a);
		//cin>>h>>p>>a;//cin>>h>>p>>a;
		//float b,c,d,e,f,g;
		f=((-1.0*(3.0*p-2.0*a))+sqrt(((3.0*p-2.0*a)*(3.0*p-2.0*a))-(8.0*(p-h)*p)))/(2.0*p);
		if(float(floor(f))==f)printf("%d\n",int(2*(floor(f))+1));
		else printf("%d\n",int(2*(floor(f)+1)+1));
	}
}
