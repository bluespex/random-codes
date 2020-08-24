#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 300005;
int a[N];



struct segment_tree_lazy{
	vector<int> st;
	vector<int> lz;
	void init(int n){
		st.clear();lz.clear();
		st.resize(4*n,0);
		lz.resize(4*n,0);
	}	
	void build(int start,int end,int node){
		if(start == end){
			st[node] = a[start];
			return;
		}
		int mid = start + ((end-start)/2);
		build(start,mid,2*node+1);
		build(mid+1,end,2*node+2);
		st[node] = st[2*node+1] + st[2*node+2];
	}
	void update(int start,int end, int node,int left,int right,int value){
		if(lz[node] != 0){
			st[node] += lz[node] * (end - start +1);
			if(start != end){
				lz[2*node+1] += lz[node];
				lz[2*node+2] += lz[node];
			}
			lz[node] = 0;
		}

		if(end<left||start>right){
			return;
		}
		if(start >= left && end <= right){
			st[node] += value * (end-start+1);
			if(start != end){
				lz[2*node+1] += value;
				lz[2*node+2] += value;
			}

			return ;
		}
		int mid = start + (end - start)>>1;
		update(start,mid,2*node+1,left,right,value);
		update(mid+1,end,2*node+2,left,right,value);

		st[node] = st[2*node+1] + st[2*node+2];
	}
	int query(int start,int end, int node,int left,int right){
		if(lz[node] != 0){
			st[node] += lz[node];
			if(start != end){
				lz[2*node+1] += lz[node];
				lz[2*node+2] += lz[node];
			}
			lz[node] = 0;
		}
		if(end<left||start>right){
			return 0;
		}
		if(start >= left && end <= right){
			return st[node];
		}
		int mid = start + ((end - start)>>1);
		return query(start,mid,2*node+1,left,right) + query(mid+1,end,2*node+2,left,right);
	}
}g;

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
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		g.init(n);
		g.build(0,n-1,0);
		g.update(0,n-1,0,1,2,1);
		cout<<g.query(0,n-1,0,0,3);		


	}
	return 0;
}