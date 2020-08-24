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
		ll i,r,n;
		cin>>n>>r;
		ll nfact = 1;
		ll rfact = 1;
		ll n_minus_r = 1;
		for(ll i=2;i<=n;i++){
			nfact = (nfact%mod * i%mod)%mod;
			if(i<=n-r){
				n_minus_r = (n_minus_r%mod * i%mod)%mod;
			}
			if(i<=r){
				rfact = (rfact%mod * i%mod)%mod;
			}

		}
		
		cout<< ((nfact%mod)*(mod_expo(rfact,mod-2)%mod)*(mod_expo(n_minus_r,mod-2)%mod))%mod;

	}
	return 0;
}