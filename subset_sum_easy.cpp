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
	
	int t; cin>>t; while(t--)
	{
		int i,j,k,n,ans=0;
		bool check = false;
		cin>>n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}

		int total = (1<<n);

		for(int i =1; i<total; i++){
			int sum = 0;
			int j=0;
			int bin = i;
			while(bin){
				if(bin&1){
					sum += v[j];
				}
				j++;
				bin = bin>>1;
			}
			if(sum == 0){
				check = true;
			}
		}

		(check) ? cout<<"YES\n" : cout<<"NO\n";

	}
	return 0;
}