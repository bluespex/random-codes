#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second



int ncr(int n,int k){
	if(n==k)
		return 1;
	if(k==0)
		return 1;
	if(k==1)
		return n;
	if(k>(n-k))
		k = n-k;
	int ans = 1;
	for(int i=0;i<k;i++){
		ans = ans*(n-i)/(i+1);
	}
	return ans;
}

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,ans=0;
		cin>>n>>k;
		cout<<ncr(n-1,k-1)<<"\n";
		


	}
	return 0;
}