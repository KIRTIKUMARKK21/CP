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
bool prime[100000];




// finding Tree diamter using two bfs.
// https://cses.fi/problemset/task/1131/
pair<int, ll> bfs(int node, vector<int>adj[], int n)
{
	std::vector<int>visited(n + 1, 0);
	std::vector<ll>dist(n + 1, -1);
	queue<int>q;
	q.push(node);
	dist[node] = 0;
	visited[node] = 1;
	int last;
	while (!q.empty())
	{
		int n1 = q.front();
		last = n1;
		q.pop();
		for (auto it : adj[n1])
		{
			if (!visited[it])
			{
				visited[it] = 1;
				q.push(it);
				dist[it] = dist[n1] + 1;

			}

		}

	}
	return {last, dist[last]};
}



void solve()
{
	int n;
	cin >> n;
	vector<int>adj[n + 1];
	for (int i = 0; i < n - 1; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		adj[n1].pb(n2);
		adj[n2].pb(n1);
	}
	pair<int, ll>p1 = bfs(1, adj, n);
	pair<int, ll>p2 = bfs(p1.first, adj, n);
	cout << p2.second << endl;
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


