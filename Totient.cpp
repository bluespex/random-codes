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
	
		// vector<int> v(N+1);
		// iota(v.begin(), v.end(), 0);
		// v[1] = 0;
		// for (int i = 2; i < N+1; ++i)
		// {
		// 	if(v[i] == i){
		// 		for (int j = i; j < N+1; j += i)
		// 		{
		// 			v[j] = (v[j]/i) * (i-1);
		// 		}
		// 	}
		// }

	sieve();
	int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,ans=0;
		cin>>n;
		vector<int> p;
		int temp = n;
		j=0;
		for(j=0;j<pr.size();j++){
			if(temp == 1){
				break;
			}
			if(temp%pr[j] == 0){
				p.pb(pr[j]);
			}
			while(temp%pr[j] == 0 && temp!=1){
				temp = temp/pr[j];
			}
		}
		ans = n;
		for(auto ele:p){
			ans = ans - ans/ele ;
		}
		cout<<ans<<"\n";
	}
	return 0;
}