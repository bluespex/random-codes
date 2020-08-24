bool cycle ;
void cycle_detect(int cur, int par) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) {
			cycle_detect(x, cur);
		}
		else if (x != par && vis[x] == 1) {
			cycle = 1;
		}
	}
	vis[cur] = 2;
}

//cycle detection in directed graph