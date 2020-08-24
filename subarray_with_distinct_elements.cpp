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
		int i,j,k,ans=1;
		int n;
		cin>>n;
		vector<int> v(n);
		for(i=0;i<n;i++){
			cin>>v[i];
		}
		for(i=0;i<n-1;i++){
			map<int,int> m;
			m[v[i]] = 1;
			j=i+1;
			ans++;
			while((j<n)&&(m[v[j]]==0)){
				ans +=j-i+1;
				m[v[j]] = 1;
				j++;
			}
		}
		cout<<ans;

	}
	return 0;
}