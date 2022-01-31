


                                    // 0 based indexing used  query(0,4) gives gcd of aelemts between 0 index to 4th index inclusive
const int N=2e5+5;
const int K=21;
ll st[N][K+1];
void buildSparseTable(ll arr[], ll n)
{
    
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];
    for (int j = 1; j <= log2(n); j++)
        for (int i = 0; i <= n - (1 << j); i++)
            st[i][j] = __gcd(st[i][j - 1],
                    st[i + (1 << (j - 1))][j - 1]);
}
int query(int L, int R)
{
    int j = (int)log2(R - L + 1);
 

    return __gcd(st[L][j], st[R - (1 << j) + 1][j]);
}

void solve()
{
    ll n;
    cin>>n;
    ll arr[n];
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    buildSparseTable(arr,n);
}
