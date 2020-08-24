#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

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

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,sum,ans=0;
		cin>>n>>m>>sum;
		tuple<int, int, int> edges[m];
		for(i=0;i<m;i++){
			int x,y,w;
			cin>>x>>y>>w;
			edges[i] = {w,x,y};
		}
		sort(edges,edges+m);
		G.init(n+1);
		vector<int> v;
		for(i=m-1;i>=0;i--){
			int w,x,y;
			w = get<0>(edges[i]);
			x = get<1>(edges[i]);
			y = get<2>(edges[i]);
			if(G.get(x) != G.get(y)){
				G.unite(x,y);
			}else{
				v.pb(w);
			}
		}
		int temp = 0;
		for(i = v.size()-1; i>=0; i--){
			if(sum <= 0){
				break;
			}
			sum -= v[i];
			if(sum<0){
				break;
			}
			temp++;
			ans += v[i];
		}
		cout<<temp<<" "<<ans;

	}
	return 0;
}