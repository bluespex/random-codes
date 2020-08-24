#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int t; cin>>t; while(t--)
	{
		int i,x,j,k,n,ans=0;
		cin>>n;
		vector<int> v(n);
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		cout<<v[0]<<" ";
		for(i = 1;i<n;i++){
			x = v[i];
			for(j=i-1;j>=0;j--){
				if(v[j]>x){
					v[j+1] = v[j];
				}else{
					break;
				}
			}
			v[j+1] = x;

			if(i%2 == 0){
				cout<<v[i/2]<<" ";
			}else{
				cout<<((v[i/2] + v[i/2 +1]) / 2)<<" ";
			}
		}


		cout<<"\n";


	}
	return 0;
}