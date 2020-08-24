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
	
	int t; cin>>t; while(t--)
	{
		ll i,j,k,n,temp=0,ans=0;
		cin>>n;
		vector<ll> v(n);
		map<ll,ll> m;
		for(ll i=0;i<n;i++){
			cin>>v[i];
			temp+=v[i];
			v[i] = temp%n;
			m[v[i]]++;
		}
		m[0]++;
		for(auto ele:m){
			ll comb = ((ele.second)*(ele.second-1))/2;
			ans += comb;
		}
		cout<<ans<<"\n";


	}
	return 0;
}