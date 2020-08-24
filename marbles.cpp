#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

int ncr(int n,int k){
	int ans = k+1;
	for(int i=2;i<=n-k;i++){
		ans *= (k+i)/i;
	}
	return ans;
}

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int t; cin>>t; while(t--)
	{
		int i,j,n,k,ans=0;
		cin>>n>>k;
		cout<<ncr(n-1,k-1)<<"\n";
	}
	return 0;
}