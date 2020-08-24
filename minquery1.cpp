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
	
	int n;
	cin>>n;
	int t; cin>>t;

	vector<int> v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}

	while(t--)
	{
		int ch;
		cin>>ch;
		if(ch == 1){
			int min = 1e9;
			int l,r;
			cin>>l>>r;
			for (int i = l; i <= r; ++i)
			{
				if(v[i]<min){
					min = v[i];
				}

			}
			cout<<min<<"\n";
		}else if(ch == 2){
			int x,y;
			cin>>x>>y;
			v[x] = y;
		}


	}
	return 0;
}