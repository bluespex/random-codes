#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
const int N = 100005;

bool check(int a[], int n, int dis, int k) {
	int  i, placed = 1, prev = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] - prev >= dis) {
			placed++;
			prev = a[i];
		}
	}
	return placed >= k;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> m;
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int lf = 1, rt = 1e10;
		while (lf <= rt) {
			int mid = (lf + rt) / 2;
			if (check(a, n, mid, m)) {
				ans = mid;
				lf = mid + 1;
			}
			else {
				rt = mid - 1;
			}
		}
		cout << ans;
	}
}