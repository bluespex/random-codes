#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool comp(pair<int,int> a, pair<int,int> b){
	if(a.second != b.second) return a.second<b.second;
	return a.first < b.first;
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
		int i,j,k,n,ans=1;
		int m;
		cin>>n;
		vector< pair<int,int> > v(n);
		for(int i=0;i<n;i++){
			cin>>v[i].first>>v[i].second;
		}

		sort(v.begin(),v.end(),comp);

		int end = v[0].second;

		for(int i=1;i<n;i++){
			if(v[i].first>=end){
				end = v[i].second;
				ans++;
			}
		}

		cout<<ans<<"\n";



	}
	return 0;
}