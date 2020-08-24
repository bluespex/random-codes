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
	
	ll check[8] = {2,3,5,7,11,13,17,19};
	ll endnumber = (1<<8);
	int t; cin>>t; while(t--)
	{
		ll i,j,k,n,ans=0;
		cin>>n;
		

		for(i=1;i<endnumber;i++){
			ll div = 1;
			ll temp = i;
			ll numberof1=0;
			j=0;
			//bool iseven = (__builtin_popcount(i)%2 == 0);
			while(temp){
				if(temp&1){
					div*=check[j];
					numberof1++;
				}
				temp = temp>>1;
				j++;
			}

			(numberof1 % 2 == 1) ?ans += n/div :ans -= n/div;
		}

		cout<<ans<<"\n";


	}
	return 0;
}