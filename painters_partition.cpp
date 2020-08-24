#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> v;
ll n;

bool check (ll mid,ll k){
	ll t=0;
	ll sum=0;
	for(int i=0;i<n;i++){
		sum+=v[i];
		if(sum>mid){
			sum=0;
			t++;
		}
	}
	return t>k;
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
		ll i,j,k,ans=0,max=0,sum=0;
		cin>>n;
		cin>>k;
		for(int i=0;i<n;i++){
			cin>>j;
			v.push_back(j);
			if(v[i]>max){
				max = v[i];
			}
			sum+=v[i];
		}
		ll left = max;
		ll right = sum;
		while(right>left){
			ll mid = left + (right-left)/2;
			if(check(mid,k)){
				left = mid + 1;
			}else{

				right = mid;
			}
		}

		cout<<left;



	}
	return 0;
}