#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

#define N 1000001

vector<int> pr;
vector<bool>primes(N,true);

void sieve(){
	for(int i=2;i<N;i++){
		if(primes[i]){
			pr.push_back(i);
			
			for(int j=i*i; j<N;j+=i){
				primes[j] = false;
			}
		}
	}
}

int32_t main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	sieve();
	int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,ans=1;
		cin>>n;
		vector<int> inp(n);
		for(i = 0; i < n; i++){
			cin>>inp[i];
		}
		map<int,int> PD;
		for(auto ele:inp){
			int temp = ele;
			j=0;
			for(j=0;j<pr.size();j++){
				if(temp == 1){
					break;
				}
				if(temp%pr[j] == 0 && PD.count(pr[j])==0){
					PD[pr[j]] = 0;
				}
				while(temp%pr[j] == 0 && temp!=1){
					temp = temp/pr[j];
					PD[pr[j]]++;
				}
			}

		}
		for(auto ele:PD){
			ans *= ele.S+1;
		}
		cout<<ans<<"\n";
	
	}
	return 0;
}