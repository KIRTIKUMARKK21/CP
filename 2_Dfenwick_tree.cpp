#include<bits/stdc++.h>
using namespace std;
// vector<vector<int>> vec( n , vector<int> (m, 0));
typedef int64_t ll;
// max N=1000






// 2-D fenwick tree code starts here
ll fenwick[1002][1002];
int arr[1002][1002];
void update(int x, int y, int val)
{
	for (int i = x; i <= 1000; i = i | (i + 1))
		for (int j = y; j <= 1000; j = j | (j + 1))
			fenwick[i][j] += val;
}
// A function to get sum from (0, 0) to (x, y)
ll sum(int x, int y)
{
	ll s = 0;

	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			s += fenwick[i][j];

	return s;
}
// 2-D fenwick tree ends here

 






void solve()
{ 
    // Total sum of points in reactangle region problem
	int q;
	cin >> q;
	memset(arr, 0, sizeof arr);
	memset(fenwick , 0, sizeof fenwick);
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 0)
		{
			int x, y;
			cin >> x >> y;
			if (arr[x][y] == 0)
			{
				update(x, y, 1);

			}
			arr[x][y] = 1;
		}
		if (t == 1)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << sum(x2, y2) - sum(x1 - 1, y2  ) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1) << endl;
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
	int t;
	cin >> t;
	int cnt = 1;
	while (t--)
	{
		cout << "Case " << cnt << ":" << endl;
		cnt++;
		solve();
	}
	return 0;
}

