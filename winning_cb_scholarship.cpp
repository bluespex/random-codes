#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

int n,m,x,y;
bool check(int gstud){
	int rem = n - gstud;
	if( (m + y*(rem)) >= gstud*x ){
		return true;
	}
	return false;
}

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,ans=0;
		cin>>n>>m>>x>>y;
		int left = 0, right = n;
		while(left <= right){
			int mid = (left + right )/ 2;
			if(check(mid)){
				ans = mid;
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}

		cout<<ans;


	}
	return 0;
}