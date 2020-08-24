#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define mod 1000000007

int mod_expo(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans = (ans*a)%mod;
		}
		a = (a*a)%mod;
		b = b/2;
	}
	return ans;
}

struct segment_tree_lazy{
	vector<int> st;
	vector<int> lz;
	void init(int n){
		st.clear();lz.clear();
		st.resize(4*n,0);
		lz.resize(4*n,-1);
	}	
	
	void update(int start,int end, int node,int left,int right,int value){
		if(lz[node] != -1){
			if(lz[node] == 1){
				st[node] = mod_expo(2,(end - start + 1)) - 1;
			}else{
				st[node] = 0;
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
			if(value == 1){
				st[node] = mod_expo(2,(end - start + 1)) - 1;
			}else{
				st[node] = 0;
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

		st[node] = ((st[2*node+1]*mod_expo(2,end-mid))%mod + st[2*node+2])%mod;
	}
	int query(int start,int end, int node,int left,int right){
		if(lz[node] != -1){
			if(lz[node] == 1){
				st[node] = mod_expo(2,(end - start + 1)) - 1;
			}else{
				st[node] = 0;
			}
			if(start != end){
				lz[2*node+1] = lz[node];
				lz[2*node+2] = lz[node];
			}
			lz[node] = -1;
		}
		if(end<left||start>right){
			return 0;
		}
		if(start >= left && end <= right){
			return st[node];
		}
		int mid = start + ((end - start)/2);

		int q1 = query(start,mid,2*node+1,left,right);
		int q2 = query(mid+1,end,2*node+2,left,right);
		if(right<mid){
			return q1;
		}
		return ((q1*mod_expo(2,min(end,right)-mid))%mod + q2)%mod;
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
			int l,r;
			cin>>l>>r;
			cout<<g.query(0,n-1,0,l,r)<<"\n";
		}
	}
	return 0;
}