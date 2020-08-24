#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

string s;
vector<string> v;
void code(int i, string ans){
	if(i==s.size()){
		//cout<<ans<<", ";
		v.pb(ans);
		return ;
	}
	code(i+1,ans + (char)(s[i]-'0'+96));
	if(i+1 < s.size()){
		int temp = (s[i]-'0')*10 + s[i+1]-'0';
		if(temp<27){
			code(i+2,ans + (char)(96+temp));
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
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,n,m,ans=0;
		cin>>s;
		cout<<"[";
		code(0,"");
		for(i=0;i<v.size();i++){
			if(i==v.size()-1){
				cout<<v[i];
				continue;
			}
			cout<<v[i]<<", ";
		}
		cout<<"]";

	}
	return 0;
}