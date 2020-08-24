#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second
int N;
void generate(int open,int closed,int pos,char* ans){
	if(pos==2*N){
		for(int i=0;i<2*N;i++){
			cout<<ans[i];
		}
		cout<<"\n";
		return;
	}
	if(open == closed){
		char*one = ans;
		one[pos] = '(';
		generate(open-1,closed,pos+1,one);
		return;
	}
	if(open == 0){
		char*two = ans;
		two[pos] = ')';
		generate(open,closed-1,pos+1,two);
		return;
	}
	char* a1 = ans;
	char* a2 = ans;
	a2[pos] = ')';
	generate(open,closed-1,pos+1,a2);

	a1[pos] = '(';
	generate(open-1,closed,pos+1,a1);
	
	return;
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
		int i,j,k,n,m;
		cin>>n;
		N = n;
		char ans[n*2];
		generate(n,n,0,ans);

	}
	return 0;
}