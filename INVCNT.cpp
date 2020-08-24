#include<bits/stdc++.h>
using namespace std;

#define int long long
#define push_back pb
#define F first
#define S second

struct fenwick {
	vector<int> fn;
	int n;
	void init(int n_){
		n = n_+10;;
		fn.clear(); fn.resize(n,0);
	}
	void add(int x, int val){
		x++;
		while(x<=n){
			fn[x] += val;
			x += (x & (-x));
		}
	}
	int sum(int x){
		x++;
		int ans = 0;
		while(x){
			ans += fn[x];
			x -= (x & (-x));
		}
		return ans;
	}
}bit;

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,ans=0;
		cin>>n;
		vector< pair<int,int> > v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i].F;
			v[i].S = i;
		}
		bit.init(n);
		sort(v.begin(), v.end());
		for(auto ele:v){
			bit.add(ele.S,1);
			// int sum = accumulate(temp.begin()+ele.S+1,temp.end(),0);
			ans += bit.sum(n) - bit.sum(ele.S);
		}
		cout<<ans<<"\n";

	}
	return 0;
}