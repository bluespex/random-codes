#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 1000001

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

bool isprime(ll a){
	ll left = 0, right = pr.size()-1, mid;
	while(left<=right){
		mid = left + (right-left)/2;
		if(pr[mid]>a){
			right = mid-1;
		}else if(pr[mid]<a){
			left = mid+1;
		}else{
			return true;
		}
	}
	return false;

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
		int i,j,k,n,ans=0;
		cin>>n;
		vector<ll> v(n);
		sieve();

		for(int i=0;i<n;i++){
			cin>>v[i];
			ll t = sqrt(v[i]);
			//cout<<t<<" "<<isprime(t)<<"\n";

			if((t*t)==v[i] && isprime(t)){
				cout<<"YES\n";
			}else{
				cout<<"NO\n";
			}
		}	
	}
	return 0;
}