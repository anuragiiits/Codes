#include <bits/stdc++.h>
using namespace std;
int main()
{
	int max,pos,s,tmax,pos1,n,k,p,t,z,i,l,*arr,*a;
	char str[100000];
	cin>>n>>k>>p;
	if (k>n)
		k=n;
	l=n+p;
	arr=new int[n];
	a=new int[l];
	//str=new char[p];
	max,pos=z,s=0,tmax,pos1;
	for (i = 0; i < k; ++i)
	{
		cin>>arr[i];
		s+=arr[i];
	}
	//t=n-k;
	t=z=l-1-(n-k);
	a[z]=max=s;
//cout<<z<<" "<<i<<endl;
	for (; i < n; ++i)
	{
		cin>>arr[i];
		s=s+arr[i]-arr[i-k];
		a[++z]=s;
		//cout<<z<<" "<<i<<endl;
		if (s>max)
		{
			pos=z;
			max=s;
		}
	}
	/*for (i = t; i <= z ; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<"\n"<<z<<endl;*/
	cin>>str;
	
	int t1=t,end=k-1,ind=0,tem,t2;
	for (i = 0; i < p; ++i)
	{
		if (str[i]=='!')
		{
			ind--;
			//cnt++;
			if (ind==-1)
			{
				ind=n-1;
			}
			s=a[t1--]+arr[ind]-arr[end--];
			if (end==-1)
			{
				end=n-1;
			}
			a[--t]=s;
			if (s>=max)
			{
				max=s;
				pos=t;
			}
			else if (s<max && pos == z)
			{
				max=s;
				pos=t;
				for (int j = t+1; j < z; ++j)
				{
					if (a[j]>max)
					{
						max=a[j];
						pos=j;
					}
				}
			}
			z--;
			/*for (int j = t; j <= z; ++j)
			{
				cout<<a[j]<<" "<<j<<endl;
			}
			cout<<" max = "<<max<<endl;*/
		}
		else
		{
			cout<<max<<endl;	
		}
	}
	return 0;
}