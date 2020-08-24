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

	int i,j=0,k,n,ans=0;

	cin>>n;

	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
		j ^= v[i];
	}

	for(int i=1;i<=10;i++){
		ans^=i;
	}

	ans ^= j;

	cout<<ans;

	

	return 0;
}