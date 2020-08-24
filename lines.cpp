#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long ans,neven = 0,nodd = 0,meven = 0,modd = 0;
		int n,m,p,qn;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>p;
			if(p%2==0){
				neven++;
			}else{
				nodd++;
			}
		}

		cin>>m;
		for(int i=0;i<m;i++){
			cin>>q;
			if(q%2==0){
				meven++;
			}else{
				modd++;
			}
		}
		ans = (neven*meven)+(nodd*modd);
		cout<<ans<<"\n";
	}
}