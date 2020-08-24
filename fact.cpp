#include<bits/stdc++.h>
using namespace std;

#define ll long long

string mul(string a, string b){
	int carry=0;
	int mult ;
	string rv = ""; 
	(b.size()==1) ? mult = b[0]-'0' : mult = (b[0]-'0')*10 + (b[1]-'0');
	for(int i = a.size()-1; i>=0; i--){
		int t = a[i]-'0';
		t = t*mult;
		rv+= '0' + ((t) + carry)%10;
		carry = (t+carry)/10;
		
	}
	if(carry>0){
		rv+=(carry%10) + '0';
		if(carry>9){
			rv+=(carry/10) + '0';	
		}
			
	} 
	//cout<<"\n"<<rv;
	reverse(rv.begin(),rv.end());
	//cout<<"\n"<<rv;
	return rv;

}

int main(){

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	
	//int t; cin>>t; while(t--)
	{
		int i,j,k,n,ans=0;
		cin>>n;
		vector<string> v(n+1);
		v[0]="1";
		for(ll i=1;i<n+1;i++){
			string temp="";
			if(i>9) temp+=(i/10) + '0';
			temp+=(i%10) + '0';
			//cout<<temp;
			v[i] = mul(v[i-1],temp);
			cout<<v[i]<<"\n";
		}
		//cout<<v[n];

	}
	return 0;
}