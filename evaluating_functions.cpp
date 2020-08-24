#include<bits/stdc++.h>
using namespace std;

#define ll long long

string sub(string a, string b){
	if(a.size()<b.size()){
		swap(a,b);
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for(int i=0;i<b.size();i++){
		int A = a[i]-'0', B = b[i]-'0';
		if(a[i]<b[i]){
			A += 10;
			int t=1;
			while(a[i+t]=='0'){
				a[i+t] = '9';
				t++;
			}
			a[i+t]--;
		}
		a[i] = A-B+'0';
	}
	reverse(a.begin(), a.end());
	return a;
}

string add(string a,string b){
	string ans="";
	int carry = 0;
	int add,i;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	bool a_greater = (a.size()>b.size());

	int n = min(a.size(),b.size());
	for(i=0;i<n;i++){
		int add = (a[i]-'0') + (b[i]-'0') +carry ;
		ans += add%10 +'0';
		carry = add/10;
	}
	if(a_greater){
		for(i;i<a.size();i++){
			int add = (a[i]-'0') +carry ;
			ans += add%10 +'0';
			carry = add/10;
		}
	}else{
		for(i;i<b.size();i++){
			int add = (b[i]-'0') +carry ;
			ans += add%10 +'0';
			carry = add/10;
		}
	}
	if(carry>0) ans += carry + '0';
	
	reverse(ans.begin(), ans.end());
	return ans;
	
}

string mul(string a, string b){
	int n = b.size();
	int carry = 0;
	string ans = "0";
	for(int i = n-1;i>=0;i--){
		string temp = "";
		carry = 0;
		for(int j = a.size()-1;j>=0;j--){
			int mul = (b[i]-'0')*(a[j]-'0') + carry;
			temp += (mul%10) + '0';
			carry = mul/10;
		}
		if(carry>0) temp += carry + '0';
		reverse(temp.begin(), temp.end());
		for(int k = i; k<n-1;k++){
			temp+='0';
		}
		//cout<<temp<<" "<<ans<<"\n";
		ans = add(ans,temp);
	}
	return ans;
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
		int i,j,k,n;
		string x;
		
		cin>>x;
		string ans = mul(mul(mul(x,x),x),"4");
		ans = add(ans,mul(mul(x,x),"5"));
		ans = add(ans,"14");
		ans = sub(ans,mul("6",x));
		cout<<ans;


	}
	return 0;
}