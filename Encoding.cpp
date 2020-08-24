#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll m = 1000000007;

ll f(string s, ll n) {
    ll rv=0;
    for(ll i=n-1; i>=0; i--){
        if(s[i-1]==s[i]){
            continue;
        }
        rv += ((s[i]-'0')*(ll)pow(10,n-1-i))%m;
    }
    return rv%m;
}

string next(string s,ll &n){
    ll i=n-1;
    for(i; i>=0; i--){
        if(s[i]=='9'){
            continue;
        }
        s[i]=s[i]+1;
        for(ll j = i+1; j<n; j++){
            s[j]='0';
        }
        break;
    }
    if(i<0){
            s+="0";
            s[0]='1';
            n+=1;
            for(ll j = 1; j<n; j++){
                s[j]='0';
            }
        }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll Nl,Nr,n,sum=0;
        string L,R;
        cin>>Nl>>L;
        cin>>Nr>>R;
        n=Nl;
        for(string i = L; i!=next(R,Nr) ; i=next(i,n)){
            sum+=f(i,n)%m;
        }
        cout<<sum%m<<"\n";
    }
    return 0;
}



