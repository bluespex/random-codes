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
	cin>>k;

	map <int,int> m;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
		if(m.find(v[i]) == m.end()){
			m[v[i]] = k-v[i];
			m[k-v[i]] = v[i];
		}else{
			cout<<"found "<<v[i]<<" "<<m[v[i]]<<"\n";
		}
	}

	return 0;
}