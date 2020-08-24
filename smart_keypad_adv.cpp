#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

string n;
vector<string> v;
int sz;
void keypad(int i,string ans){
	if(i==sz){
		//cout<<ans<<"\n";
		v.pb(ans);
		return;
	}
	for(auto ele:table[n[i]-'0']){
		keypad(i+1,ans+ele);
	}
}

void check(string a, string b){
	if(a.size()>b.size()){
		return;
	}
	for(int i=0;i<b.size();i++){
		int t = i;
		int k = 0;
		while(a[k] == b[t] && k<a.size() && t<b.size()){
			t++;
			k++;
			//cout<<k<<"\n";
		}
		if(k == a.size()){
			cout<<b<<"\n";
			break;
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
		int i,j,k,m,ans=0;

		cin>>n;
		sz = n.size();
		keypad(0,"");
		
		for(i=0;i<v.size();i++){
			for(j=0;j<11;j++){
				//cout<<v[i]<<" "<<searchIn[j]<<"\n";
				check(v[i],searchIn[j]);
			}
		}

	}
	return 0;
}