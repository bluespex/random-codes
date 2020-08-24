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
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,n,ans=0;
		cin>>n;
		vector<int> v(n);
		for( i = 0; i < n; i++){
			cin>>v[i];
		}
		if(n>=70){
			cout<<"YES";
			return 0;
		}

		for(int i=0;i<=66;i++){
			for(int j=i+1;j<=67;j++){
				for(int k=j+1;k<=68;k++){
					for(int l=k+1;l<=69;l++){
						if(v[i]^v[j]^v[k]^v[l]){
							cout<<"YES";
							return 0;
						}
					}	
				}

			}
		}

		cout<<"NO";

	}
	return 0;
}