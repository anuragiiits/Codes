/* Anurag Gupta
Indian Institute of Information Technology
anurag.iiits@gmail.com */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[1000000];
int c[1000000];
 int flag[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    ll diff,max;
    ll sum;
    
    cin>>t;
    while(t--)
    {
       
        
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>w[i];
        }
        sum=0;
        int l=0;
        max=0;
        memset(flag, 0, (n+1)*sizeof(flag[0]));
       
       
        for(int i=0;i<n;i++)
        {
            if(flag[c[i]]==0)
            {
                
                flag[c[i]]=1;
                sum+=w[i];
                
            }
            else
            {
                if(sum>max)
                    max=sum;
                
                while(c[l]!=c[i])
                {
                    sum-=w[l];
                    flag[c[l]]=0;
                    l++;
                }
                
                sum-=w[l];
                l++;
                
                sum+=w[i];
            }
        }
        
        if(sum>max)
            max=sum;
        cout<<max<<"\n";
        
    }
    
	return 0;
}
