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
void bellmanford()
{
	int n , m;
	cin >> n >> m;
	vector<pair<pair<int, int>, ll>>adj;

	for (int i = 0; i < m; ++i)
	{
		int c1, c2, w;
		cin >> c1 >> c2 >> w;
		adj.pb({{c1, c2}, w});

	}

	vector<ll>dist(n + 1, 1e18);
	vector<int>parent(n + 1, 0);
	dist[1] = 0;
	int s;
	// bellmanford

	for (int i = 0; i < n; i++)
	{
		s = -1;
		for (auto it : adj)
		{
			int c1 = it.first.first;
			int c2 = it.first.second;
			ll d = it.second;
			if (dist[c2] > dist[c1] + d)
			{
				parent[c2] = c1;
				dist[c2] = dist[c1] + d;
				s = c2;
			}
		}
	}

	if (s == -1)
	{
		// negative cycle not detected
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;

	// backtracking path

	for (int i = 0; i < n; i++)
	{
		s = parent[s];
	}


	int start = s;
	cout << s << " ";
	s = parent[s];
	vector<int>path;
	while (s != start)
	{
		// cout << s << " ";
		path.pb(s);
		s = parent[s];
	}
	reverse(path.begin(), path.end());
	for (auto it : path)
	{
		cout << it << " ";
	}
	cout << start << endl;



}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	// int t;
	bellmanford();
	return 0;
}


