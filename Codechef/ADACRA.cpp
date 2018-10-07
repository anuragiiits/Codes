#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,c1,c2;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int l=s.length();
        c1=c2=0;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='U')
            {
                for(;i<l;i++)
                    if(s[i]!='U')
                        break;
                c1++;
                i--;
            }
            else
            {
                for(;i<l;i++)
                    if(s[i]!='D')
                        break;
                c2++;
                i--;
            }
        }
        if(c1<c2)
            cout<<c1<<"\n";
        else
            cout<<c2<<"\n";
    }
        return 0;    
    
}