    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    int main()
    {
    	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t,n,i,cnt,j,p;
        cin>>t;
        ll a[100005],s[100005],tot,ans,sum;
        s[0]=0;
        while(t--)
        {
        	cin>>n;
        	cnt=0,sum=0;
        	for (i = 0; i < n; ++i)
        	{
        		cin>>a[i];
        		if (a[i]>=0)
        		{
        			cnt++;
        			sum+=a[i];
        		}
        	}
     
        	sort(a,a+n);
        	for (i = 0; i < n-cnt; ++i)
        	{
        		s[i+1]=s[i]+a[i];
        	}
        	if (sum==0)
        	{
        		cout<<s[i]<<endl;
        		continue;
        	}
        	p=0;
        	tot=sum*cnt+s[i];
        	j=n-cnt;
        	for (i = n-cnt-1; i >=0 ; --i)
        	{
        		ans=(sum+s[j]-s[i])*(cnt+ ++p) + s[i];
        		if (ans<tot)
        		{
        			break;
        		}
        		tot=ans;
        	}
        	cout<<tot<<endl;
        }
        return 0;
    } 