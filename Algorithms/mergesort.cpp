#include<stdio.h>

void merge(int arr[],int l, int h, int mid)
{
	int p=l,m=l,i;
	int n=mid+1;
	int t[100];
	while(m<=mid || n<=h)
	{
		if (m<=mid && n<=h && arr[m]<=arr[n])
		{
			t[p-l]=arr[m++];
			p++;
		}
		else if (m<=mid && n<=h && arr[m]>arr[n])
		{
			t[p-l]=arr[n++];
			p++;
		}
		else if(m>mid)
		{
			t[p-l]=arr[n++];
			p++;
		}
		else if(n>h)
		{
			t[p-l]=arr[m++];
			p++;	
		}
	}
	p=0;
	for (i = l; i <=h; ++i)
	{
		arr[i]=t[p++];
	}
}
void sort(int arr[],int l,int h)
{
	int mid=(l+h)/2;
	if(l<h){
	sort(arr,l,mid);
	sort(arr,mid+1,h);
	merge(arr,l,h,mid);
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