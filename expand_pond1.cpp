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
		int i,j,k,n,m,ans=0;
		cin>>n>>m;
		vector<int> dry((n*m) + 1,0);
		G.init(n*m+1);
		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				int x;
				cin>>x;
				if(x==0)
					dry[(m*(i-1)) + j] = 1;
				if(x==1){
					if( i>1 && dry[(m*(i-2)) + j] == 0){
						G.unite((m*(i-1)) + j,(m*(i-2)) + j);
					}
					if( j>1 && dry[(m*(i-1)) + j-1] == 0){	
						G.unite(((m*(i-1)) + j),((m*(i-1)) + j-1));
					}
				}

			}
		}

		for(i=1; i<=n; i++){
			for(j=1; j<=m; j++){
				if(dry[m*(i-1) + j] == 0)
					continue;

				int left=0,right=0,top=0,bottom=0;
				int li,ri,ti,bi;
				if( i>1 && dry[m*(i-2) + j] == 0 )
				{	
					top = G.sz[(G.get(m*(i-2) + j))];
					ti = G.get(m*(i-2) + j);
				}

				if( j>1 && dry[(m*(i-1)) + j-1] == 0 )
				{	
					left = G.sz[(G.get((m*(i-1)) + j-1))];
					li = G.get((m*(i-1)) + j-1);
					if(top > 0){
						if(ti == li)
							left=0;
					}
				}

				if( i<n && dry[(m)*(i) + j] == 0 )
				{	
					bottom = G.sz[(G.get((m)*(i) + j))];
					bi = G.get((m)*(i) + j);
					if(top > 0){
						if(ti == bi)
							bottom=0;
					}
					if(left > 0){
						if(bi == li)
							bottom=0;
					}
				}

				if( j<m && dry[(m*(i-1)) + j+1] == 0 )
				{	
					right = G.sz[(G.get((m*(i-1)) + j+1))];
					ri = G.get((m*(i-1)) + j+1);
					if(top > 0){
						if(ti == ri)
							right=0;
					}
					if(bottom > 0){
						if(bi == ri)
							right=0;
					}
					if(left > 0){
						if(li == ri)
							right=0;
					}
				}


				ans = max(ans,left+right+bottom+top+1);
			}
		}
		cout<<ans ;

	}
	return 0;
}