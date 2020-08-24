#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool comp(string a,string b){
	if(a.size()<b.size()){
		for(int i = 0; i<a.size(); i++){
			if(a[i]!=b[i]){
				return a[i]<b[i];
			}
		}
		return b.size()>a.size();
	}else{
		for(int i = 0; i<b.size(); i++){
			if(a[i]!=b[i]){
				return a[i]<b[i];
			}
		}
		return b.size()<a.size();
	}
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
		int i,j,k,n,ans=0;
		cin>>n;
		std::vector<string> v(n);

		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}

		sort(v.begin(),v.end(),comp);

		for (int i = 0; i < n; ++i)
		{
			cout<<v[i]<<"\n";
		}

	}
	return 0;
}