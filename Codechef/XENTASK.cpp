# include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,sum,sum1;
	int arr[2*10000];
	int arr1[2*10000];
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0,sum1=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
			if (i%2==0)
			sum+=arr[i];
			else
			sum1+=arr[i];
			
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>arr1[i];
			if (i%2==0)
			sum1+=arr1[i];
			else
			sum+=arr1[i];
		}
		if (sum<=sum1)
			cout<<sum<<endl;
		else
			cout<<sum1<<endl;
	}
	return 0;
}