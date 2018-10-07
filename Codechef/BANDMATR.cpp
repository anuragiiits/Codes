# include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,sum;
	int arr[500][500];
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>arr[i][j];
				if (arr[i][j]==1)
					sum+=1;
			}
		}
		int p=n;
		int ans=0;
		if (sum<=p)
		{
			cout<<ans<<endl;
			continue;
		}
		n--;
		while(n>=1)
		{
			p=p+2*(n--);
			ans++;
			if (sum<=p)
			{
				cout<<ans<<endl;
				break;
			}
		}
	}
	return 0;
}