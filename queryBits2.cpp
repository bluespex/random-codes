#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define mod 1000000007

struct segment_tree_lazy{
	vector<vector<int> > st;
	vector<int> lz;
	void init(int n){
		st.clear();lz.clear();
		st.resize(4*n);
		lz.resize(4*n,-1);
	}	
	
	void update(int start,int end, int node,int left,int right,int value){
		if(lz[node] != -1){
			st[node].resize(end - start + 1);
			if(lz[node] == 1){
				fill(st[node].begin(), st[node].end(), 1);
			}else{
				fill(st[node].begin(), st[node].end(), 0);
			}
			if(start != end){
				lz[2*node+1] = lz[node];
				lz[2*node+2] = lz[node];
			}
			lz[node] = -1;
		}

		if(end<left||start>right){
			return;
		}
		if(start >= left && end <= right){
			st[node].resize(end - start + 1);
			if(value == 1){
				fill(st[node].begin(), st[node].end(), 1);
			}else{
				fill(st[node].begin(), st[node].end(), 0);
			}
			if(start != end){
				lz[2*node+1] = value;
				lz[2*node+2] = value;
			}

			return ;
		}
		int mid = start + (end - start)/2;
		update(start,mid,2*node+1,left,right,value);
		update(mid+1,end,2*node+2,left,right,value);

		st[node] = st[2*node+1];
		st[node].insert(st[node].end(),st[2*node+2].begin(), st[2*node+2].end());
	}
	vector<int> query(int start,int end, int node,int left,int right){
		if(lz[node] != -1){
			st[node].resize(end - start + 1);
			if(lz[node] == 1){
				fill(st[node].begin(), st[node].end(), 1);
			}else{
				fill(st[node].begin(), st[node].end(), 0);
			}
			if(start != end){
				lz[2*node+1] = lz[node];
				lz[2*node+2] = lz[node];
			}
			lz[node] = -1;
		}
		if(end<left||start>right){
			return {};
		}
		if(start >= left && end <= right){
			return st[node];
		}
		int mid = start + ((end - start)/2);

		vector<int> q1 = query(start,mid,2*node+1,left,right);
		vector<int> q2 = query(mid+1,end,2*node+2,left,right);
		q1.insert(q1.end(),q2.begin(), q2.end());
		return q1;
	}
}g;

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	g.init(n);
	for(int i = 0; i<n; i++){
		g.update(0,n-1,0,i,i,0);
	}
	
	int t; cin>>t; while(t--)
	{
		int ans=0;
		int choice;
		cin>>choice;
		if(choice == 0){
			int l,r;
			cin>>l>>r;
			g.update(0,n-1,0,l,r,0);
		}else if(choice == 1){
			int l,r;
			cin>>l>>r;
			g.update(0,n-1,0,l,r,1);
		}else if(choice == 2){
			int l,r,ans = 0;
			cin>>l>>r;
			vector<int> v = g.query(0,n-1,0,l,r);
			int sz = v.size();
			for(int i = 0; i<sz; i++)
				ans = (ans + ((1<<i)*(v[sz-i-1]))%mod)%mod; 
			cout<<ans<<"\n";
		}
	}
	return 0;
}