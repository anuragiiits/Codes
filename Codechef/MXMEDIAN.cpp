#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n,i,m,med,size;
	int *arr,*res;
	cin>>t;
	while(t--){
		cin>>n;
		size=n*2;
		arr = new int[size+1];
		for (i = 1; i <= size; ++i){
			cin>>arr[i];
		}
		sort(arr+1,arr+size+1);
		m=size-n/2;
		med=arr[m];
		res=new int[size+1];
		for (i = n; i <= size; i+=2){
			res[i]=arr[m++];
		}
		m=1;
		for (i = n+1; i <= size; i+=2){
			res[i]=arr[m++];
		}
		for (i = 1; i < n ; ++i){
			res[i]=arr[m++];
		}
		cout<<med<<endl;
		for (i = 1; i <= size; ++i){
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}