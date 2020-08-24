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
		int k,n,ans=0;
		cin>>n;
		vector<int> v(n);
		vector<int> sumsetbit(64,0);

		for(int i =0; i<n; i++){
			cin>>v[i];
		}

		for(int i=0;i<64;i++){
			for(auto ele:v){
				sumsetbit[i] += ((ele>>i) & 1);
			}
			sumsetbit[i] = sumsetbit[i]%3;
		}
		
		int power = 1;
		for(int i = 0;i<64;i++){
			ans += sumsetbit[i]*power;
			power*=2;
		}

		cout<<ans;

	}
	return 0;
}