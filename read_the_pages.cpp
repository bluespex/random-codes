#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

vector<ll> pages;

ll check(ll mid, ll n){
	ll students = 1;
	ll sum_pages = 0;
	for(auto ele:pages){
		sum_pages += ele;
		if(sum_pages > mid){
			sum_pages = ele;
			students++;
		}
	}

	return students;
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
		ll i,j,k,n,m,ans=0,left=-1,right=0;
		cin>>n>>m;
		for(i=0;i<n;i++){
			ll j;
			cin>>j;
			pages.pb(j);
			left = max(left,j);
			right += j;
		}

		while(left<right){
			ll mid = left + ((right - left)/2);
			//cout<<check(mid,m)<<" "<<left<<" "<<right<<"\n";
			if(check(mid,m)>m){
				left = mid+1;
			}else{
				right = mid;
			}
		}
		cout<<left;

	}
	return 0;
}