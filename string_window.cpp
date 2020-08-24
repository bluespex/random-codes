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
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,ans=1e9,t=0;
		string result = "";
		string s1,s2;
		getline(cin,s1);
		getline(cin,s2);
		map<char,int> M;
		map<char,int> temp;
		for(auto ele:s2){
			M[ele]++;
			//temp[ele]++;
		}
		temp = M;
	
		n = s2.size();
		for(i=0;i<s1.size();i++){
			if(temp.count(s1[i]) == 0){
				continue;
			}
			j = i;
			while(!temp.empty()){
				if(j>=s1.size()){
					break;
				}
				if(temp.count(s1[j])){
					temp[s1[j]]--;
					if(temp[s1[j]] == 0){
						temp.erase(s1[j]);
					}
				}
				j++;

				if(temp.empty()){
					int x;
					x = j-i;
					if(x<ans){
						result = s1.substr(i,x);
					}
					ans = min(x,ans);
					// cout<<x<<" ";
					// for(int y=i;y<j;y++){
					// 	cout<<s1[y];
					// }
					// cout<<"\n";
				}

			}
			temp = M;

		}

		if(result == ""){
			cout<<"No string";
			return 0;
		}

		cout<<result;


	}
	return 0;
}