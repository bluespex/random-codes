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
		cin>>l>>r;

		std::vector<int> temp(r-l+1);

		if(v[l]<0){
			temp[0] = 0;
		}else{
			temp[0] = v[l];
		}

		for(int i=l+1;i<=r;i++){
			temp[i-l] = temp[i-l-1] + v[i];
			if(temp[i-l]<0){
				temp[i-l] = 0;
			}

			if(temp[i-l]>ans){
				ans = temp[i-l];
			}
		}
		cout<<ans<<"\n";

	}
	return 0;
}