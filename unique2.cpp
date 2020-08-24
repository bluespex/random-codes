#include<bits/stdc++.h>
using namespace std;

#define ll long long

int kthsetbit(int ans){
	int k =0;
	while(ans>0){
		if(ans&1 == 1){
			break;
		}
		ans = ans>>1;
		k++;
	}
	return k;
}

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		int k=0,n,ans=0;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
			ans^=v[i];
		}

		k = kthsetbit(ans);
		int mask = 1<<k;

		int x=0,y=0;

		for(auto ele:v){
			if((ele&mask) > 0){
				x ^= ele;
			}
		}

		y = ans^x;
		
		(x>y) ?cout<<y<<" "<<x :cout<<x<<" "<<y;
	
	}
	return 0;
}