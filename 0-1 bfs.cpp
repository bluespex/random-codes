// 0-1 bfs


//https://codeforces.com/blog/entry/22276


//problem (where I needed it)	https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
//psuedocode
for all v in vertices:
	dist[v] = inf
dist[source] = 0;
deque d
d.push_front(source)
while d.empty() == false:
	vertex = get front element and pop as in BFS.
	for all edges e of form (vertex , u):
		if travelling e relaxes distance to u:
			relax dist[u]
			if e.weight = 1:
				d.push_back(u)
			else:
				d.push_front(u)