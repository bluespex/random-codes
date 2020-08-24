#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define N 100000001


int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		//int i,j,k,ans=0;
		ll n;
		cin>>n;
		vector<ll> pr;
		vector<bool>primes(N,true);
		pr.push_back(2);
		for(ll i=3;i<N;i+=2){
			if(primes[i]){
				pr.push_back(i);
				
				for(ll j=i*i; j<N;j+=i){
					primes[j] = false;
				}
			}
		}

		cout<<pr[n-1];

	}
	return 0;
}