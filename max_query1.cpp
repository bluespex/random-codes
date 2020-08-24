#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin>>n;
	

	vector<int> v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}

	int t; cin>>t; while(t--)
	{
		int l,r,k,ans=0;
		cin>>l>>r>>k;

		for(int i=l;i<=r;i++){
			if(v[i]>=k){
				ans++;
			}
		}
		cout<<ans<<"\n";

	}
	return 0;
}