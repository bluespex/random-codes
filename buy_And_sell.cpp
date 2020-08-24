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
} bit;

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int i,j,k,n,ans=0;
	cin>>n;
	vector<pair<int,string> > v(n);
	map<string,int> m,m1;
	for(i=0;i<n;i++){
		cin>>v[i].S;
		cin>>v[i].F;
	}
	sort(v.rbegin(), v.rend());
	for(i=0;i<n;i++){
		m[v[i].S] = i;
		m1[v[i].S] = 0;

	}
	bit.init(n);
	
	int t; cin>>t; while(t--)
	{
		char ch;
		cin>>ch;
		if(ch == '+'){
			string s;
			cin>>s;
			int pos = m[s];
			m1[s]++;
			// cout<<pos<<" ";
			bit.add(pos+1,1);
		}else if(ch == '-'){
			string s;
			cin>>s;
			int pos = m[s];
			if(m1[s]>0){
				m1[s]--;
				bit.add(pos+1,-1);
			}
		}else if(ch == '?'){
			int temp;
			cin>>temp;
			for(i=0;i<n;i++){
				if(v[i].F == temp || v[i].F <temp){
					break;
				}
			}
			cout<<bit.sum(i)<<"\n";
		}

	}
	return 0;
}