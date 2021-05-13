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
bool prime[100000];
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
void SieveOfEratosthenes()
{
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= 100000; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= 100000; i += p)
				prime[i] = false;
		}
	}
}
long long binpow(long long a, long long b) {
	a %= MOD;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res % MOD
	       ;
}
ll invmd(ll n)
{
	return (binpow(n, MOD - 2));
}
vector<ll>fenwick(200005, 0);
ll arr[200005];
void update(int index, int value, int n)
{
	while (index <= n)
	{
		fenwick[index] += value;
		index = index + (index & (-index));
	}

}
ll sum(int index)
{
	ll ans = 0;
	while (index > 0)
	{
		ans += fenwick[index];
		index = index - (index & (-index));
	}
	return ans;

}
void solve()
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n + 1; i++)
	{
		cin >> arr[i];
		update(i, arr[i], n);
	}
	while (q--)
	{
		int q1, n1, n2;
		cin >> q1 >> n1 >> n2;
		if (q1 == 1)
		{
			update(n1, n2 - arr[n1], n);
			arr[n1] = n2;


		}
		else
		{
			cout << sum(n2) - sum(n1 - 1) << endl;

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

