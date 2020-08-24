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

ll digit_sum(int n){
	ll ans=0;
	while(n){
		ans+=n%10;
		n/=10;
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
	
	//int t; cin>>t; while(t--)
	{
		ll i,j,k,n,t,ans=0;
		cin>>n;
		k = n;
		sieve();
		unordered_map<int,int> m;
		for(int i=0;i<pr.size();i++){
            if(k==1){
                break;
            }
			t=0;
			if(pr[i]>n) break;
			while(k%pr[i] == 0){
				k /= pr[i];
				t++;
			}
			
			if(t>0) m[pr[i]] = t;
		}
		for(auto ele:m){
			ans += digit_sum(ele.first) * ele.second;
		}
		//cout<<ans;
		if(digit_sum(n)==ans){
			cout<<1;
		}else{
			cout<<0;
		}



	}
	return 0;
}