#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define N 100001

vector<ll> pr;
vector<bool>primes(N,true);

void sieve(){
	pr.push_back(2);
	for(ll i=3;i<N;i+=2){
		if(primes[i]){
			pr.push_back(i);
			
			for(ll j=i*i; j<N;j+=i){
				primes[j] = false;
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
	
	sieve();
	int t; cin>>t; while(t--)
	{
		

		ll l,r;
		ll n;
		cin>>l>>r;
		n=r-l+1;

		vector<bool> p(n,true);

		for(auto prime : pr){
			if(prime*prime > r) break;
			ll start = (l/prime)*prime;
			if(prime>l) start = prime*prime;

			for(ll i = start; i<=r; i+=prime){
				if(i < l) continue;
				p[i-l] = false;
			}
		}

		for(ll i = 0;i<n;i++){
			if(p[i]&&(i+l)!=1){
				cout<<i+l<<"\n";
			}
		}

		cout<<"\n";

	}
	return 0;
}