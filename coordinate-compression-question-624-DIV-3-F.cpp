#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

struct fenwick {
	vector<int> fn;
	int n;
	void init(int _n) {
		n = _n + 10;
		fn.clear(); fn.resize(n, 0);
	}
	void add(int x, int val) {
		x++;// 1 based indexing
		while (x <= n) {
			fn[x] += val;
			x += (x & (-x));
		}
	}
	int sum(int x) {
		x++;//1 basaed indexing
		int ans = 0;
		while (x) {
			ans += fn[x];
			x -= (x & (-x));
		}
		return ans;
	}
} bit,bit1;

int32_t main(){

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
		vector<P> velocity(n);
		vector<int> compress;
		for(i=0;i<n;i++){
			cin>>velocity[i].S;
			compress.pb(velocity[i].S);
		}
		for(i=0;i<n;i++){
			cin>>velocity[i].F;
		}

		//coordinate-compression
		sort(compress.begin(), compress.end());
		compress.resize(unique(compress.begin(), compress.end()) - compress.begin());


		sort(velocity.begin(), velocity.end());
		bit.init(n);
		bit1.init(n);
		for(i=0;i<n;i++){
			//position from coordinate-compression.......
			int pos = lower_bound(compress.begin(), compress.end(), velocity[i].S) - compress.begin();

			bit.add(pos,1);
			bit1.add(pos,-velocity[i].S);
			int s = bit.sum(pos - 1);
			int s_ = bit1.sum(pos - 1);
			// cout<<velocity[i].S<<" "<<s<<" "<<s_<<"\n";
			ans += s*velocity[i].S + s_;
		}
		cout<<ans;
		

	}
	return 0;
}