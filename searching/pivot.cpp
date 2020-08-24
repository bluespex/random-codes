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

	map <int,int> m;
	vector<int> v(n);
	for(i=0; i<n; i++){
		cin>>v[i];
		m[i] = j;
		j += v[i];
	}

	for (int i = 0; i < n; ++i)
	{
		if(m[i] == j-m[i]-v[i]){
			cout<<i<<"\n";
			return 0;
		}
	}
	cout<<-1;

	return 0;
}