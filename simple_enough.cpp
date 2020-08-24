#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> v;

void fillmid(ll left,ll right,ll n){
	if(left > right){
		return ;
	}
	ll mid = left + (right-left)/2;
	v[mid] = (n&1);
	fillmid(left,mid-1,n/2);
	fillmid(mid+1,right,n/2);
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
		ll i,j,k,n,ans=0;
		cin>>n;
		cin>>j>>k;
		ll size = log(n)/log(2) + 1;
		v.resize(2*n,1);
		fillmid(1,1<<size,n);
		for(ll i=j;i<=k;i++){
			if(v[i] == 1) ans++;
		}

		cout<<ans;

	}
	return 0;
}