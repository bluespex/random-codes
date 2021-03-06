struct Tree {
	int Par[N][M], dep[N], timer = 0, dis[N], tin[N], tout[N];
	int val[N], flat[N], a[N];
	vector<P> gr[N];

	void input_value(int n) {
		for (int i = 1; i <= n; i++) {
			cin >> val[i];
		}
	}

	void input(int n, bool weighted) {
		for (int i = 1; i < n; i++) {
			int x, y, w;
			cin >> x >> y;
			if (weighted) cin >> w;
			else w = 1;
			gr[x].pb({y, w});
			gr[y].pb({x, w});
		}
		tin[0] = 0; tout[0] = n; // universal parent 0
		timer = 0;
	}

	void dfs(int cur, int par) {
		dep[cur] = dep[par] + 1;
		tin[cur] = ++timer;
		for (auto x : gr[cur]) {
			if (par != x.F) {
				dis[x.F] = dis[cur] + x.S;
				dfs(x.F, cur);
			}
		}
		tout[cur] = timer;
	}

	void flat_tree(int n) {
		// tin[1]=0; tout[1]=n-1
		// flat array is 0 based;
		for (int i = 1; i <= n; i++) {
			flat[tin[i]] = i;
		}
	}

	void cal_sparse_matrix(int cur, int par) {
		Par[cur][0] = par;
		for (int i = 1; i < M; i++) {
			Par[cur][i] = Par[Par[cur][i - 1]][i - 1];
		}
		for (auto x : gr[cur]) {
			if (par != x.F) {
				cal_sparse_matrix(x.F, cur);
			}
		}
	}

	int LCAD(int u, int v) {
		if (dep[u] < dep[v]) swap(u, v);
		int diff = dep[u] - dep[v];
		for (int i = M - 1; i >= 0; i--) {
			if (diff & (1 << i)) u = Par[u][i];
		}
		if (u == v) return v;
		for (int i = M - 1; i >= 0; i--) {
			if (Par[u][i] != Par[v][i]) {
				u = Par[u][i]; v = Par[v][i];
			}
		}
		return Par[u][0];
	}

	bool is_ancestor(int u, int v) {
		//is u ancestor of v?
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	}

	int LCAT(int u, int v) {
		if (is_ancestor(u, v)) return u;
		if (is_ancestor(v, u)) return v;
		for (int i = M - 1; i >= 0; i--) {
			if (!is_ancestor(Par[u][i], v)) u = Par[u][i];
		}
		return Par[u][0];
	}

} tr;