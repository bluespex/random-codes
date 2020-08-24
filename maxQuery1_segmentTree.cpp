#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 200005;

int a[N];

struct segmentTree
{
	vector<int> st[N*4];
	// void init(int n){
	// 	st.resize(4*n);
	// }
	void build(int start, int end, int node){			
		if(start == end){
			st[node].push_back(a[start]);
			return;
		}
		int mid = start + ((end-start)>>1);
		build(start,mid,2*node+1);
		build(mid+1,end,2*node+2);
		merge(st[2*node+1].begin(), st[2*node+1].end(), st[2*node+2].begin(), st[2*node+2].end(), back_inserter(st[node]));
	}
	int query(int start,int end,int node, int left, int right, int k){
		if( right < start || left > end){
			return 0;
		}
		if(end<=right && start>=left){
			return st[node].size() - (lower_bound(st[node].begin(), st[node].end(), k) - st[node].begin());
		}

		int mid = start + ((end - start)>>1);
		return query(start,mid,2*node+1,left,right,k) + query(mid+1,end,2*node+2,left,right,k);
	}
	// void update(int start,int end,int node,int index,int value){
	// 	if(start == end){
	// 		a[index] = value;
	// 		st[node].clear();
	// 		st[node].push_back(value);
	// 		return;
	// 	}
	// 	int mid = start + ((end-start)>>1);
	// 	if(index<=mid){
	// 		update(start,mid,2*node+1,index,value);
	// 	}else{
	// 		update(mid+1,end,2*node+2,index,value);
	// 	}
	// 	merge(st[2*node+1].begin(), st[2*node+1].end(), st[2*node+2].begin(), st[2*node+2].end(), back_inserter(st[node]));
	// }
}g;

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	g.build(0,n-1,0);
	
	int t; cin>>t; while(t--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		cout<<g.query(0,n-1,0,l-1,r-1,k)<<"\n";


	}
	return 0;
}