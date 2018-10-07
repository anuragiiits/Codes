/* Anurag Gupta
Indian Institute of Information Technology
anurag.iiits@gmail.com */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000000000000000000


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll arr[1000],p=2,k,diff;
    int i,len=0,t,pos,cnt;
    bool flag;
    
    while(p*2<=MAX)
    {
        p*=2;
        arr[len++]=p;
    }
    
    cin>>t;
    while(t--){
        cin>>k;
        if(k<=2)
        {
            cout<<"a\n";
            continue;
        }
        else if(k==3)
        {
            cout<<"c\n";
            continue;
        }
        if(!(k&(k-1)))
        {
            cout<<"a\n";
            continue;
        }
        
        cnt=0;
        flag=false;
        while(k>3){
            cnt++;
            pos=upper_bound(arr,arr+len,k)-arr-1;
            diff=k-arr[pos];
            k=arr[pos]-diff;
            if(!(k&(k-1)))
            {
                flag=true;
                break;
            }
        }
        if(flag==true || k<=2)
        {
            if(cnt%2==0)
                cout<<"a\n";
            else
                cout<<"c\n";
        }
        else
        {
            if(cnt%2==0)
                cout<<"c\n";
            else
                cout<<"a\n";
            
        }
        
    }
    
	return 0;
}
