// longest non decreasing sequnece
int ldns(vector<int>v)
{
	int n = v.size();
	vector<int>dp;
	for (auto it : v)
	{
		auto  j = upper_bound(dp.begin(), dp.end(), it);
		if (j==dp.end())
		{
			dp.pb(it);

		}
        else
        {
            *j=it;
        }
     }
     return dp.size();

}

// longest incresing sequnece
int lis(vector<int>v)
{
	int n = v.size();
	vector<int>dp;
	for (auto it : v)
	{
		auto  j = lower_bound(dp.begin(), dp.end(), it);
		if (j==dp.end())
		{
			dp.pb(it);

		}
        else
        {
            *j=it;
        }
     }
     return dp.size();

}
