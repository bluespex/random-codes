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

	int i,j,k,n,ans=0;

	cin>>n;
	map <int,int> m;

	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
		m[v[i]]++;
	}

	for(auto ele : m){
		if(ele.second>1){
			cout<<"yess";
			return 0;
		}
	}


	cout<<"NO";






	
	return 0;
}