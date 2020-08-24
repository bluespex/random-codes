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
	
	int t,k; 
	cin>>t>>k;
	priority_queue<int, vector<int>, greater<int> > q;
	while(t--)
	{
		int i,x,y,ans=0;
		cin>>i;
		if(i==1){
			cin>>x>>y;
			int temp = x*x + y*y;
			q.push(temp);
		}else if(i == 2){
			std::vector<int> v(k);
			for(int j=0;j<k;j++){
				v[j]=q.top();
				q.pop();

			}

			cout<<v[k-1]<<"\n";
			for(int j=0;j<k;j++){
				q.push(v[j]);
			}
		}


	}
	return 0;
}