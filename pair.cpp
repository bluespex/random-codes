#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll binary_search(ll start,ll end,ll value,vector<ll> v){
	
	while(start<end){
		ll mid = start + (end - start)/2;
		if(v[mid]<value){
			start =mid+1;
		}else if(v[mid]>value){
			end = mid-1;
		}else{
			return mid;
		}
	}
	return start;

}

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int t; cin>>t; while(t--)
	{
		ll i,j,k,n,ans=0;
		cin>>n;
		vector<ll> v(n);
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		ll M;
		cin>>M;
		ll find = M/2;
		sort(v.begin(),v.end());

		//ll pivot = binary_search(0,n-1,find,v);
		pair<ll,ll> p;

		i=0;
		j=i+1;
		// for (i = pivot;i>=0;i--){
		// 	if(v[i]+v[j]==M){
		// 		cout<<"Deepak should buy roses whose prices are "<<v[i]<<" and "<<v[second]<<".\n";
		// 		break;
		// 	}
		// 	if(v[i] + v[j]<)
		// }

		while(i<n){
			if(v[i]+v[j]<M){
				if(j>n-1) i++; j=i+1;
				j++;
			}else if(v[i]+v[j]>M){
				i++;
				j=i+1;
			}else{
				p = {i,j};
			}
		}
		cout<<"Deepak should buy roses whose prices are "<<v[p.first]<<" and "<<v[p.second]<<".\n";



	}
	return 0;
}