#include<bits/stdc++.h>
using namespace std;

#define int             long long
#define ld              long double
#define pb              push_back
#define P               pair<int,int>
#define F               first
#define S               second
#define vi              vector<int>
#define ps(x,y)         fixed<<setprecision(y)<<x
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define db(...)         __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cerr << " "<< name << " : " << arg1 <<'\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 100005;
const int mod = 1e9 + 7;
int mx = -1e18 , mn = 1e18;

void inp_out()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("debug.txt", "w", stderr);
    #endif
}

int32_t main(){

    FIO;
    inp_out();
    
    //int t; cin>>t; while(t--)
    {
        int i,j,k,n,m,ans = 0,cnt = 0,sum = 0;
        cin>>n>>m;
        bool g[n][n];
        memset(g,0,sizeof(g));

        for(i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            g[u][v] = 1;
            g[v][u] = 1;
        }

        bool dp[n][1<<n];

        for(i=0;i<n;i++){
            for(j=0;j<(1<<n);j++){
                dp[i][j] = false;
            }
            dp[i][1<<i] = true;
        }

        for(i=0;i<(1<<n);i++){
            for(j=0;j<n;j++){
                if(i & (1<<j)){
                    for(k=0;k<n;k++){
                        if(k!= j && i&(1<<k) && g[k][j] && dp[k][i ^ (1<<j)]){
                            dp[j][i] = 1;
                            break;
                        }
                    }
                }
            }
        }

        bool f = 0;
        for(i=0;i<n;i++){
            if(dp[i][(1<<n) - 1]){
                f = 1;
                break;
            }
        }

        cout<<((f) ? "YES" : "NO")<<"\n";
    }
    return 0;
}

// https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/