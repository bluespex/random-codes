#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct dsu{
	vector<int> p,sz;
	int comp;
	void init(int NN){
		sz.clear(); p.clear();
		p.resize(NN); sz.resize(NN,1);
		comp = NN;
		iota(p.begin(), p.end(), 0);
	}
	int get(int x){
		return (x == p[x] ? x : (p[x] = get(p[x])));
	}
	void unite(int x, int y){
		x = get(x);
		y = get(y);
		if(x != y){
			p[x] = y;
			sz[y] += sz[x];
			sz[x] = 0;
			comp--;
		}
	}
}G;

int main(){

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
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}

		G.init(n);
		G.unite(1,2);
		for(auto ele : G.p){
			cout<<ele<<" ";
		}
		cout<<"\n"<<G.comp;

	}
	return 0;
}