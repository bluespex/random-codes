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
		ll i,j,k,n,ans=0;
		cin>>n;
		//bool iseven = (n&1 == 0);
		ll evendiv = 0;
		ll odddiv = 0;
		for(ll i = 2; i*i<=n; i+=2){
			if(n%i == 0){
				evendiv += i;
				if(i == n/i) continue;
				((n/i)%2 == 0) ? evendiv+=n/i : odddiv+=n/i;
			}
		}
		for(ll i = 1; i*i<=n; i+=2){
			if(n%i == 0){
				odddiv += i;
				if(i == n/i) continue;
				((n/i)%2 == 0) ? evendiv+=n/i : odddiv+=n/i;
			}
		}

		cout << evendiv - odddiv <<"\n";


	}
	return 0;
}