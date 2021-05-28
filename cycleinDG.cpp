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


           // cycyle in directed graph with cycle path

           // https://cses.fi/problemset/task/1678


const int N = 2e5 + 5;
vector<int>vis(N, 0);
vector<int>pathvis(N, 0);
vector<int>par(N, 0);
int start ;
int endp;
bool cycleindg(int node, vector<int>adj[], int parent = -1)
{
	vis[node] = 1;
	pathvis[node] = 1;
	par[node] = parent;
	for (auto it : adj[node])
	{
		if (!vis[it])
		{
			if (cycleindg(it, adj, node))
			{
				return true;
			}
		}
		else if ( pathvis[it])
		{
			start = it;
			endp = node;
			return true;
		}
	}
	pathvis[node] = 0;
	return false;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int>adj[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int c1, c2;
		cin >> c1 >> c2;
		adj[c1].pb(c2);
		/* code */
	}
	bool flag = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			if (cycleindg(i, adj))
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag == 0)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}


	   // finding cyclic path code


	int p = endp;
	vector<int>ans;
	ans.pb(endp);
	while (true)
	{
		p = par[p];
		if (p == start)
		{
			ans.pb(p);
			break;
		}
		ans.pb(p);
	}
	ans.pb(endp);
	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (auto it : ans)
	{
		cout << it << " ";
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


