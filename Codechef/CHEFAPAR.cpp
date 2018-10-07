#include<stdio.h>
int main() {
	
	int t,n,i,sum,A[100000];
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		scanf("%d",&n);
		sum=0;
		for (i=0;i<n;i++) {
			scanf("%d",&A[i]);
		if (A[i]==0) {
				sum+=1100;
			}
			else if(i>0&&A[i-1]==0)
			{
				sum+=100;
				A[i]=0;
			}
		}
		printf("%d\n",sum);
	}	
	
}