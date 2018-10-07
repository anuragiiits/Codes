    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    	int t,p,q,r,ind1,ind2,i,j1,j2;
    	ll sum1,sum2,a[100001],b[100001],c[100001],ans;
    	cin>>t;
    	while(t--)
    	{
    	    cin>>p>>q>>r;
    	    for(i=0;i<p;i++)
    	        cin>>a[i];
    	    for(i=0;i<q;i++)
    	        cin>>b[i];
    	    for(i=0;i<r;i++)
    	        cin>>c[i];
            sort(a,a+p);
            sort(b,b+q);
            sort(c,c+r);
            
            sum1=sum2=ans=0;
            j1=j2=0;
            for(i=0;i<q;i++)
            {
                for(;j1<p;j1++)
                {
                    if(a[j1]>b[i])
                        break;
                    sum1=sum1+a[j1];
                    
                }
                    
                
                for(;j2<r;j2++)
                {
                    if(c[j2]>b[i])
                        break;
                    sum2=sum2+c[j2];
                }
                ans=(ans+((sum1+b[i]*j1)%1000000007)*((sum2+b[i]*j2)%1000000007))%1000000007;
            }
    	     cout<<ans<<endl;  
    	}
     	return 0;
    } 