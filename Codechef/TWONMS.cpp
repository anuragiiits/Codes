/* Anurag Gupta
Indian Institute of Information Technology
anurag.iiits@gmail.com */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    ll a,b,n,res;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        if(n%2==1)
            a=a*2;
        res=(max(a,b)/min(a,b));
        
            
        cout<<res<<"\n";
    }
    
	return 0;
}
