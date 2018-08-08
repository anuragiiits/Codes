#include<stdio.h>
void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[],int low, int high)
{
	int p=arr[high];
	int i,c=low;
	for (i = low; i < high; ++i)
	{
		if (arr[i]<=p)
		{
			swap(&arr[i],&arr[c]);
			c++;
		}
	}
	swap(&arr[c],&arr[high]);
	return c;
}
void sort(int arr[],int low,int high)
{
	if (low<high)
	{
		int p=partition(arr,low,high);
		sort(arr,low,p-1);
		sort(arr,p+1,high);
	}
}
int main()
{
	int n,i,arr[100];
	scanf("%d",&n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,0,n-1);
	for (i = 0; i < n; ++i)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}