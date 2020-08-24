#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct dsu {
	vector<int> p, sz;
	int comp;
	void init(int NN) {
		sz.clear(); p.clear();
		p.resize(NN); sz.resize(NN, 1);
		iota(p.begin(), p.end(), 0);
		comp = NN;
	}
	int get(int x) {
		return (x == p[x] ? x : (p[x] = get(p[x])));
	}
	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x != y) {
			p[x] = y;
			sz[y] += sz[x];
			sz[x] = 0;
			comp--;
		}
	}
} G;

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,ans=0;
		cin>>n;
		G.init(n);
		cin>>m;
		for (int i = 0; i < m; ++i)
		{
			int x,y;
			cin>>x>>y;
			G.unite(x,y);
		}
		int total = 0;
		total = accumulate(G.sz.begin(), G.sz.end(),0);

		for(auto ele :  G.sz){
			if(ele>0){
				ans += ele * (total - ele);
			}
		}
		cout<<ans/2;

	}
	return 0;
}