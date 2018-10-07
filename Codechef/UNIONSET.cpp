#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,k,i,j,tem,z,cnt,c,ans,arr[2500][2500],s[2500],size[2500];
    cin>>t;
    while(t--)
    {
    	int a[2500][2500]={0};
    	cin>>n>>k;
    	ans=0;
    	for (i = 0; i < n; ++i)
    	{
    		cin>>size[i];
    		for (j = 0; j < size[i]; ++j)
    		{
    			cin>>arr[i][j];
    			a[i][arr[i][j]-1]=1;
    		}
    		//a[i][j]=-1;
    	}
    	for (i = 0; i < n; ++i)
    	{
    	    if (size[i]==k)
    		{
    			ans+=n-1-i;
    			continue;
    		}
    		cnt=0;
    		for (j = 0; j<k ; ++j)
    		{
    			if (a[i][j]==0)
    			{
    				s[cnt++]=j;
    			}
    		}
    		
	    	for(j=i+1; j < n;j++)
	    	{
	    	    if((size[i]+size[j])<k)
	    	        continue;
	    		c=0;	
	    		
	    		for (z = 0; z < cnt ; ++z)
	    		{
	    			if (a[j][s[z]]==1)
	    			{
	    				c++;
	    			}
	    		}
	    		if (c==cnt)
	    		{
	    			ans++;
	    		}
	    	}
    	}
    	cout<<ans<<"\n";
    }
    return 0;
}

