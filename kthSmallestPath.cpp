#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define   pb              push_back
#define   rep(i,a,b)      for(int i=a;i<b;i++)
#define   vl              vector<ll>
#define   vi              vector<int>
#define   lb              lower_bound
#define   ub              upper_bound
// vector<vector<int>> vec( n , vector<int> (m, 0));
// priority_queue<pi, vector<pi>, greater<pi>>q;
typedef int64_t ll;
#define   pi              pair<ll, int>


// https://cses.fi/problemset/task/1196
// finding kth smallest path with slightb variation in djisktra

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	std::vector<pi>adj[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int c1, c2, w;
		cin >> c1 >> c2 >> w;
		adj[c1].pb({w, c2});
	}
	int start = 1;

	// d[n][k-1] denotes kth smallest distance from node source to nth node

	vector<vector<ll>>dist( n + 1 , vector<ll> (12, 1e18));
	priority_queue<pi, vector<pi>, greater<pi>>q;
	q.push({0, start});
	while (!q.empty())
	{
		ll d = q.top().first;
		int city = q.top().second;
		q.pop();
		if (dist[city][k - 1] < d)
		{
			continue;
		}
		for (auto it : adj[city])
		{
			int city2 = it.second;
			ll d2 = it.first;
			if (dist[city2][k - 1] > d + d2)
			{
				dist[city2][k - 1] = d + d2;
				q.push({dist[city2][k - 1], city2});
				sort(dist[city2].begin(), dist[city2].end());
			}
		}
	}
	// printing first kth smallest path from start node to end node
	for (int i = 0; i < k; i++)
	{
		cout << dist[n][i] << " ";
	}
	cout << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	solve();
	return 0;
}


