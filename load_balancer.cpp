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
		int i,j,k,n,ans=0,sum = 0;
		cin>>n;
		std::vector<int> v(n);
		for(int i = 0;i<n;i++){
			cin>>v[i];
			ans += v[i];
			//q.push(v[i]);
		}
		int final = ans/n;
		for(int i = 0;i<n;i++){
			int temp = v[i];
			if(v[i-1]<10&&v[i-1]<v[i]){
				v[i-1]++;
				v[i]--;
			}
			if(v[i+1]<10&&v[i+1]<v[i]){
				v[i+1]++;
				v[i]--;
			}
			if(v[i]!=temp){
				sum++;
			}
		}
		cout<<sum;


	}
	return 0;
}