#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005, M = 17, mod = 1e7 +7;
int ptr = 0, chain_no = 0;

vector<int> gr[N]; //edges;
int subsize[N], dep[N], Par[N][M], cost[N];
int chain_head[N], chain_Ind[N], chain_size[N];
int pos_in_Base[N];
map<int,int> PD[N],Base_array[N];

class segmenttree
{
public:
    map<int,int> st[N * 4];
    void build(int l, int r, int node) {
        if (l == r) {
            st[node] = Base_array[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, node * 2 + 1);
        build(mid + 1, r, node * 2 + 2);
        for(auto ele:st[2 * node + 1]){
            st[node][ele.F] = (st[node][ele.F] + ele.S)%mod; 
        }
        for(auto ele:st[2 * node + 2]){
            st[node][ele.F] = (st[node][ele.F] + ele.S)%mod; 
        }
    }

    map<int,int> query(int si, int se, int l, int r, int node) {
        if (se < l || si > r || l > r) {
            map<int,int> rv;
            return rv;
        }
        if (si >= l && se <= r) {
            return st[node];
        }
        int mid = (si + se) / 2;
        map<int,int> q1 = query(si, mid, l, r, node * 2 + 1);
        map<int,int> q2 = query(mid + 1, se, l, r, node * 2 + 2);
        map<int,int> rv;
        for(auto ele:q1){
            rv[ele.F] = (rv[ele.F] + ele.S)%mod;
        }
        for(auto ele:q2){
            rv[ele.F] = (rv[ele.F] + ele.S)%mod;
        }
        return rv;
    }
} tr;

void HLD(int cur, int par) {
    if (chain_head[chain_no] == 0) {
        chain_head[chain_no] = cur;
    }
    chain_Ind[cur] = chain_no;
    pos_in_Base[cur] = ptr;
    Base_array[ptr++] = PD[cur];
    chain_size[chain_no]++;

    int sp_chld = -1;
    for (auto x : gr[cur]) {
        if (x != par && (sp_chld == -1 || subsize[x] > subsize[sp_chld])) {
            sp_chld = x;
        }
    }
    if (sp_chld != -1) {
        HLD(sp_chld, cur);
    }
    for (auto x : gr[cur]) {
        if (x != par && x != sp_chld) {
            chain_no++;
            HLD(x, cur);
        }
    }
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    int diff = dep[u] - dep[v];
    for (int i = M - 1; i >= 0; i--) {
        if (diff & (1 << i)) {
            u = Par[u][i];
        }
    }
    if (u == v) return v;
    for (int i = M - 1; i >= 0; i--) {
        if (Par[u][i] != Par[v][i]) {
            u = Par[u][i];
            v = Par[v][i];
        }
    }
    return Par[u][0];
}


void cal_sparse_matrix(int cur, int par) {
    Par[cur][0] = par;
    for (int i = 1; i < M; i++) {
        Par[cur][i] = Par[Par[cur][i - 1]][i - 1];
    }
    for (auto x : gr[cur]) {
        if (par != x) {
            cal_sparse_matrix(x, cur);
        }
    }
}

void dfs(int cur, int par) {
    subsize[cur] = 1;
    dep[cur] = dep[par] + 1;
    for (auto x : gr[cur]) {
        if (x != par) {
            dfs(x, cur);
            subsize[cur] += subsize[x];
        }
    }
}

void edge() {
    int x, y;
    cin >> x >> y;
    gr[x].pb(y);
    gr[y].pb(x);
    // edges.pb({x, y});
}

void calc_PD(int n){
    for(int i=1;i<=n;i++){
        {
            int temp = cost[i];
            while(temp%2 == 0){
                temp = temp/2;
                PD[i][2] = (PD[i][2] + 1)%mod;
            }
            for(int j=3;j*j<=cost[i];j+=2){
                if(temp == 1){
                    break;
                }

                while(temp%j == 0){
                    temp = temp/j;
                    PD[i][j] = (PD[i][j] + 1)%mod;
                }
            }
            if(temp!=1){
                PD[i][temp] = (PD[i][temp]+1)%mod;
            }
            
        }
    }
}

map<int,int> query_up(int u, int v) {
    if (u == v){
        return PD[u];  
    }
    int uchain = chain_Ind[u], vchain = chain_Ind[v];
    map<int,int> ans;
    bool check = true;
    while (1) {
        uchain = chain_Ind[u];
        if (uchain == vchain) {
            if (v == u) break;
            map<int,int> temp = tr.query(0, ptr - 1, pos_in_Base[v], pos_in_Base[u], 0);
            for(auto ele:temp){
                ans[ele.F] = (ans[ele.F] + ele.S)%mod;
            }
            break;
        }
        else {
            check =false;
            map<int,int> temp = tr.query(0, ptr - 1, pos_in_Base[chain_head[uchain]], pos_in_Base[u], 0);
            for(auto ele:temp){
                ans[ele.F] = (ans[ele.F] + ele.S)%mod;
            }
            u = Par[chain_head[uchain]][0];
        }
    }
    if(!check){
        for(auto ele:PD[v]){
            ans[ele.F] = (ans[ele.F] + ele.S)%mod;
        }
    }
    return ans;
}

void clr(int n) {
    // edges.clear();
    for (int i = 0; i <= n; i++) {
        gr[i].clear();
        subsize[i] = 0;
        dep[i] = 0;
        chain_head[i] = 0;
        chain_Ind[i] = 0;
        chain_size[i] = 0;
        chain_size[i] = 0;
        Base_array[i].clear();
        PD[i].clear();
        pos_in_Base[i] = 0;
        for (int j = 0; j < M; j++) {
            Par[i][j] = 0;
        }
    }
    ptr = 0;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t; while (t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        for (i = 1; i < n; i++) {
            edge();
        }
        for(i=1;i<=n;i++){
            cin>>cost[i];
        }
        ptr = 0;
        chain_no = 0;
        dfs(1, 0);
        calc_PD(n);
        cal_sparse_matrix(1, 0);
        HLD(1, 0);
        tr.build(0, ptr - 1, 0);
        cin>>k;
        while (k--) {
            int u,v;
            cin>>u>>v;
            int ans = 1;
            int lca = LCA(u,v);
            map<int,int> temp1,temp2;
            temp1 = query_up(u, lca);
            temp2 = query_up(v, lca);
            for(auto ele:temp2){
                temp1[ele.F] = (temp1[ele.F] + ele.S)%mod;
            }
            for(auto ele:PD[lca]){
                temp1[ele.F] -= ele.S;
            }
            
            for(auto ele:temp1){
                ans = (ans* (ele.S + 1)%mod)%mod;
            }
            cout<<ans<<"\n";
        }
        clr(n);
    }
}