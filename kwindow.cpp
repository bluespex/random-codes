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
		int j,k,n,ans=0;
		cin>>n;
		cin>>k;
		vector <int> v(n);
		deque<int> q;
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		q.push_back(0);
		for(int i = 1;i<k;i++){
			while(!q.empty() && v[q.back()]>v[i]){
				q.pop_back();
			}
			q.push_back(i);
		}

		cout<<v[q.front()]<<" \n";

		for(int i = k;i<n;i++){
			while(!q.empty() && v[q.back()]>v[i]){
				q.pop_back();
			} 
				
			q.push_back(i);
			if(q.front() == i-k)
				q.pop_front();
			cout<<v[q.front()]<<" \n";
		}

	}
	return 0;
}