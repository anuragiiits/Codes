#include<stdio.h>
int main()
{
	int t,d1,cnt,i;
	long long int m,n,c;

	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld %lld",&n,&m,&c);
		cnt=0;
		if(c<=(n*m))
		{
			for(i=1;i<=c/2&&i<=n;i++)
			{
				if(c%i==0)
				{
					d1=c/i;
					if(d1<=m)
					cnt++;
				}
			}
			if(c<=n&&m>=1)
				cnt++;
			}
		printf("%d\n",cnt);
	}
	return 0;
}