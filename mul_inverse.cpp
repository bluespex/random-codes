#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll mod_expo(ll a, ll b){
	ll ans=1;
	
	while(b){
		if(b&1){
			ans = (ans*a)%mod;
		}
		a = (a*a)%mod;
		b = b/2;
	}
	return ans%mod;
}

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		ll i,j,k,n,ans=0;
		cin>>n;
		cout<<mod_expo(n,mod-2)%mod;

	}
	return 0;
}