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

// bfs algorithm to travel all nodes and find shortest distnce from
// starting node to all other node
// https://www.hackerrank.com/challenges/bfsshortreach/problem

void solve()
{
	int n, p;
	cin >> n >> p;
	std::vector<int>adj[n + 2];
	for (int i = 0; i < p; i++)
	{
		int a1, a2;
		cin >> a1 >> a2;
		adj[a1].pb(a2);
		adj[a2].pb(a1);
	}
	int start;
	cin >> start;



	// ********->>>>>     BFS   <<<<<-******* 
 
	vector<int>visited(n + 1, 0);
	std::vector<ll>dist(n + 1, -1);
	queue<int>q;
	q.push(start);
	visited[start] = 1;
	dist[start] = 0;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (auto it : adj[node])
		{
			if (!visited[it])
			{
				q.push(it);
				visited[it] = 1;
				dist[it] = dist[node] + 1;
			}
		}
	}
	

	// ********->>>>>     BFS End Here   <<<<<-******* 
 

	// printing distance array

	for (int i = 1; i < n + 1; i++)
	{
		if (i != start)
		{	cout << dist[i] << " ";
		}
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
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}


