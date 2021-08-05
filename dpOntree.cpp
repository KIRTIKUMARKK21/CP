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
#define all(x) (x).begin(), (x).end()
#define nline "\n"
// vector<vector<int>> vec( n , vector<int> (m, 0));
// priority_queue<pi, vector<pi>, greater<pi>>q;
typedef int64_t ll;


         // Nice Question on DP on Tree
 // Main idea is consider a tree with one root and other three all leafs and child of root
 // then in this case you have to visit all weights twice except one where we end our journey
 // so greedily we have to chose that leaf on which ending or journey will take overall leat cost
 // so lets define dp[i] to be distance of furthermost leaf from ith node so so we will visit each leaf
 // and comeback but in case for leaf where dp[1] is max we will vist it at last thus total anser will be
 // ans=2*total weights-dp[1]
 // if(there is only two node then dp[1]=total wights  


// https://codeforces.com/problemset/problem/61/D





vector<ll>dp(200005, 0);
void dfs(int node, vector<pair<int, int>>adj[], int parent = 0)
{
	dp[node] = 0;
	for (auto it : adj[node])
	{
		int next = it.first;
		int w = it.second;
		if (next != parent)
		{
			dfs(next, adj, node);
			dp[node] = max(dp[node], w + dp[next]);
		}
	}

}
void solve()
{
	int n;
	cin >> n;
	vector<pair<int, int>>adj[n + 1];
	ll ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
		ans += w;
	}
	dfs(1, adj);
	if (dp[1] == ans)
	{
		cout << ans << nline;
	}
	else
	{
		cout << 2 * ans - dp[1] << nline;
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


