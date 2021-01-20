https://www.codechef.com/COW42020/problems/COW3E/
// 2-d prefix sum with modifications

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
        int u,q;
        cin>>u>>q;
        int a[n][m];
        int pre_array[n+1][m+1];
        int update[n+1][m+1];
        memset(update , 0ll ,sizeof(update));
        memset(pre_array , 0ll ,sizeof(pre_array));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>a[i][j];
            }
        }

        while(u--){
            int k,r1,c1,r2,c2;
            cin>>k>>r1>>c1>>r2>>c2;
            update[r1][c1] += k;
            update[r2+1][c1] -= k;
            update[r1][c2+1] -= k;
            update[r2+1][c2+1] += k;
        }


        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                pre_array[i+1][j+1] = a[i][j] + pre_array[i+1][j];
                update[i][j+1] += update[i][j];
            }
        }


        for(i=0;i<n+1;i++){
            for(j=0;j<n;j++){
                pre_array[j+1][i] += pre_array[j][i];
                update[j+1][i] += update[j][i];
            }
        }



        int pre_update[n+1][m+1];
        memset(pre_update,0ll,sizeof(pre_update));


        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                pre_update[i+1][j+1] = update[i][j] + pre_update[i+1][j];
            }
        }

        for(i=0;i<n+1;i++){
            for(j=0;j<n;j++){
                pre_update[j+1][i] += pre_update[j][i];
            }
        }


        while(q--){
            int r1,c1,r2,c2;
            cin>>r1>>c1>>r2>>c2;

            ans = 0;
            ans += pre_array[r2+1][c2+1] - pre_array[r1][c2+1];
            ans += pre_array[r1][c1] - pre_array[r2+1][c1];

            ans += pre_update[r2+1][c2+1] - pre_update[r1][c2+1];
            ans += pre_update[r1][c1] - pre_update[r2+1][c1];
            

            cout<<ans<<"\n";
        }


    }
    return 0;
}