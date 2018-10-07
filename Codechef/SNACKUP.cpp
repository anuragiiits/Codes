#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n,p;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<n<<"\n";
        
        for(int i=1;i<=n;i++)
        {
            cout<<n<<"\n";
            p=i;
            for(int j=1;j<=n;j++)
            {
                cout<<j<<" "<<p<<" ";
                p++;
                if(p==n+1)
                    p=1;
                cout<<p<<"\n";
            }
            
        }
    }
    return 0;
}