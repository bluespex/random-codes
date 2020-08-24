#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	int i,j,k,n,ans=0;
	cin>>n;
	vector <int> v(n);
	for (i = 0; i < n; ++i)
	{
		cin>>v[i];
	}

	
	j=0;
	for(i=0;i<n;i++){
		if(v[i]!=0){
			swap(v[j++],v[i]);
		}
	}
	// while(j!=n){
	// 	v[j++] = 0;
	// }

	for (i = 0; i < n; ++i)
	{
		cout<<v[i]<<" ";
	}
	
	return 0;
}