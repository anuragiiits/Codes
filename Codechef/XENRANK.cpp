#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
 	int t;
 	ll u,v,diff;
 	cin>>t;
 	while(t--)
 	{
 		cin>>u>>v;
 		ll i=(u+1)*(u+2)/2;
 		diff=(u+v)*(u+1+v)/2 - (u+1)*u/2;
 		cout<<diff+i<<endl;
	}
	return 0;
}