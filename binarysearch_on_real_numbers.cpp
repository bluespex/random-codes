#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define P pair<int,int>
#define F first
#define S second

const int N = 100005;

vector<int> v;
int n , d;
bool check(long double t){
    long double timer = 0.0;
    for(int i = 0 ; i < n; i++){
        if(timer <= v[i] + d){
            timer = max((long double)v[i] , timer) + t;
        }else{
            return false;
        }
    }
    return true;
}

int32_t main(){

    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin>>t; while(t--)
    {
        int i,j;
        double ans;
        cin>>n>>d;
        v.clear();
        v.resize(n);
        for(i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(), v.end());

        // int l = 0 , r = v[n-1] + d;

        long double l=0.00000000,r=2e9;
        while((r-l)>1e-7){
            long double mid = ((l+r)/2.0);
            if(check(mid)){
                l=mid;
            } 
            else{
                r=mid;
            }
        }


        cout<<fixed;
        cout << setprecision(6) << l << '\n';



    }
    return 0;
}