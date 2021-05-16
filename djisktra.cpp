void solve()
{
	int n;
	cin >> n;
	std::vector<pi>adj[n+1];
	for (int i = 0; i < n; ++i)
	{
		int c1, c2, w;
		cin >> c1 >> c2 >> w;
		adj[c1].pb({c2, w});
		adj[c2].pb({c1, w});
	}
	int start;
	cin >> start;
	std::vector<int>visited(n+1, 0);
	std::vector<ll>dist(n+1, 1e18);
	// pi=pair<ll,int
	priority_queue<pi, vector<pi>, greater<pi>>q;
	dist[start] = 0;
	q.push({0, start});
	while (!q.empty())
	{
		ll w = q.top().first;
		int city = q.top().second;
		q.pop();
		if (!visited[city])
		{
			visited[city] = 1;
			for (auto it : adj[city])
			{
				int c2 = it.first;
				ll w2 = it.second;
				if (dist[city] + w2 < dist[c2])
				{
					dist[c2] = dist[city] + w2;
					q.push({dist[c2], c2});
				}
			}
		}
	}
}
