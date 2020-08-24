#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define N 100001

unordered_map<ll,ll> m;
unordered_map<ll,ll> m1;

void sieve(){
	for(ll i=2;i<N;i++){
		for(ll j=i; j<N;j+=i){
			if(m[j]>0){
				m1[i] += m[j];
			}
		}
	}
}


int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	ll n;
	cin>>n;
	vector<int> v(n);
	for(ll i=0;i<n;i++){
		cin>>v[i];
		m[v[i]]++;
	}
	sieve();
	m1[1] = n;
	ll t; cin>>t; while(t--)
	{
		ll i,j,k,n,ans=0;
		cin>>k;
		cout<<m1[k]<<"\n";

	}
	return 0;
}