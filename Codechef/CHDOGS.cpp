#include<stdio.h>
int main()
{
	int t;
	long long int s,v;
	double res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&s,&v);
		res=(2.0*s)/(3.0*v);
		printf("%lf\n",res);
	}
	return 0;
}