
void lis()
{

	int n;
	cin >> n;
	std::vector<int>v(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		/* code */
	}
	std::vector<int>dp;
	//nlogn solution
	dp.pb(v[0]);
	for (int i = 1; i < n; i++)
	{
		if (dp.back() < v[i])
		{
			dp.pb(v[i]);
		}
		else
		{
			int it = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
			dp[it] = v[i];
		}
	}
	cout << dp.size() << endl;


}
