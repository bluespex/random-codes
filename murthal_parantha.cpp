#include<bits/stdc++.h>
using namespace std;

#define ll long long



bool check(ll time,ll p,vector<ll> ranks){
	ll paranthas = 0;

	for(auto ele:ranks){
		ll t=1;
		ll temp = ele;
		while(temp <= time){
			t++;
			temp = ele * (t*(t+1)/2);	
		}
		paranthas += t-1;
	}

	return paranthas>=p;
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
		ll k,n,p,ans=0;
		cin>>p;
		cin>>n;
		vector<ll> ranks(n);
		for(ll i=0;i<n;i++){
			cin>>ranks[i];
		}
		sort(ranks.begin(), ranks.end());
		ll left = 0,right = 1e5;
		while(left<right){
			ll mid = left + (right-left)/2;
			if(check(mid,p,ranks)){
				right = mid;
			}else{
				left = mid+1;
			}
		}
		cout<<right;

	}
	return 0;
}