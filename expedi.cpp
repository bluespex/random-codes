#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second


int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	int t; cin>>t; while(t--)
	{
		int i,j,n,m,ans=0;
		cin>>n;
		bool check = false;
		vector<P> v(n);
		priority_queue<P> q;
		for(i=0;i<n;i++){
			cin>>v[i].F>>v[i].S;
			q.push(v[i]);
		}
		P start;
		cin>>start.F>>start.S;
		
		int entering = 0, leaving = start.S, cur = start.F, k=0;
		while(!q.empty()){
			k++;
			vector<P> vect;
			int temp = cur - leaving;
			while(temp <= q.top().F && !q.empty()){
				vect.pb(q.top());
				//cout<<q.top().F<<" ";
				q.pop();
			}
			int enter = entering;
			int leave = leaving;
			int ans = 0,ind;
			if(vect.empty()){
				break;
			}
			for(int i=0;i<vect.size();i++){
				P ele = vect[i];
				enter = leave - (cur - ele.F);
				leave = enter + ele.S;
				if(leave>ans){
					ans = leave;
					ind = i;
				}
				enter = entering;
				leave = leaving;
			}
			entering = leaving - (cur - vect[ind].F);
			leaving = entering + vect[ind].S;
			cur = vect[ind].F;
			if(cur - leaving <=0){
				//cout<<cur<<" ";
				check = true;
				cout<<k<<"\n";
				break;
			}
		}

		if(check){
			//return 0;
			continue;
		}
		cout<<-1<<"\n";


	}
	return 0;
}