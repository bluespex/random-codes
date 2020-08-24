#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007;

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
		std::vector<ll> v(n);
		vector <int> alpha(n);

		for(int i =0;i<n;i++){
			cin>>v[i];
			int a= 0;
			for(int j = 0;j<i;j++){
				if(v[j]<v[i]){
					a+=v[j]%mod;
				}
			}
			alpha[i] = a%mod;
		}

		ans = accumulate(alpha.begin(), alpha.end(), ans);
		ans %= mod;
		cout<<ans;
	}
	return 0;
}