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


// Floyd Marshall for all pair of shortest path o(n^(3))
// https://cses.fi/problemset/task/1672/




void solve()
{
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<ll>>dp( n + 1 , vector<ll> (n + 1, 1e18));
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (i == j)
			{
				dp[i][j] = 0;
			}
			else
			{
				dp[i][j] = 1e18;
			}
		}
	}


	for (int i = 0; i < m; ++i)
	{
		ll c1, c2, w;
		cin >> c1 >> c2 >> w;
		dp[c1][c2] = min(dp[c1][c2], w);
		dp[c2][c1] = min(dp[c2][c1], w);



		/* code */
	}


	for (int k = 1; k < n + 1; ++k) {
		for (int i = 1; i < n + 1; ++i) {
			for (int j = 1; j < n + 1; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	while (q--)
	{
		ll c1, c2;
		cin >> c1 >> c2;
		if (d[c1][c2] >= 1e18)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << d[c1][c2] << endl;

		}
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


