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
typedef int64_t ll;
#define   pi              pair<ll, int>



// weighted undirected djisktra  algo based question
//  question_url:https://www.spoj.com/problems/ADATRIP/
void solve()
{
	int n, m, q;
	cin >> n >> m >> q;
	std::vector<pair<int, int>>adj[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int c1, c2, w;
		cin >> c1 >> c2 >> w;
		adj[c1].pb({w, c2});
		adj[c2].pb({w, c1});
	}
	while (q--)
	{
		int x;
		cin >> x;
		vector<ll>dist(n + 1, 1e18);
		dist[x] = 0;
		vector<int>visited(n + 1, 0);
		priority_queue<pi, vector<pi>, greater<pi>>q;
		q.push({0, x});
		int maxl = -1;
		int no = 0;
		while (!q.empty())
		{
			ll d = q.top().first;
			int node = q.top().second;
			q.pop();
			if (visited[node])
			{
				continue;
			}
			visited[node] = 1;

			for (auto it : adj[node])
			{
				ll w1 = it.first;
				int n2 = it.second;
				if (dist[node] + w1 < dist[n2])
				{
					dist[n2] = dist[node] + w1;
					q.push({dist[n2], n2});
				}
			}
			if (d == maxl)
			{
				no++;
			}
			if (d > maxl)
			{
				maxl = d;
				no = 1;
			}

		}
		cout << maxl << " " << no << endl;

	}
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

