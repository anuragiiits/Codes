# include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int l, int h, int mid)
{
	int p=l,m=l,i;
	int n=mid+1;
	int t[100000];
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
void sortn(int arr[],int l,int h)
{
	int mid=(l+h)/2;
	if(l<h){
	sortn(arr,l,mid);
	sortn(arr,mid+1,h);
	merge(arr,l,h,mid);
	}
}
int main()
{
	int t,n;
	int arr[100000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
			
		}
		sortn(arr,0,n-1);
		
		for (int i = 0; i < n-1; ++i)
		{
			if (arr[i]!=arr[i+1]-1)
			{
				if (i==n-2)
				{
					cout<<arr[i+1]<<endl;
					break;
				}
				cout<<arr[i]<<endl;
				break;
			}
		}
	}
	return 0;
}