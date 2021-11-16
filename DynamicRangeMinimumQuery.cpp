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
#define   print(ans)      printf("%.9f\n",ans)
#define all(x) (x).begin(), (x).end()
typedef int64_t ll;
typedef unsigned long long ull;
typedef long double lld;
#define   pi              pair<ll, int>
#define nline "\n"



 
                        // USING SEGMENT TREE




const int N = 8e5 + 10;
ll tree[N];
ll a[N];


void build(int node , int start, int end)
{
	if (start == end)
	{
		tree[node] = a[start];
	}
	else
	{
		int mid = (start + end) >> 1;
		int left = 2 * node;
		int right = 2 * node + 1;
		build(left, start, mid);
		build(right, mid + 1, end);
		tree[node] = min(tree[left], tree[right]);

	}


}



int getmin(int node,int start,int end,int l,int r)
{
	if(end<l || r<start)
	{
		return INT_MAX;
	}
	if(start==end)
	{
		return tree[node];
	}
	else if(l<=start && end<=r)
	{
		return tree[node];
	}
	else
	{
		int mid=(start+end)>>1;
		int left=getmin(2*node,start,mid,l,r);
		int right=getmin(2*node+1,mid+1,end,l,r);
		return min(left,right);
	}
}



void update(int node,int start,int end,int pos,int val)
{
	if(start==end)
	{
		a[start]=val;
		tree[node]=val;
	}
	else
	{
		int mid=(start+end)>>1;
		if(start<=pos && pos<=mid)
		{
			update(node*2,start,mid,pos,val);
		}
		else
		{
			update(node*2+1,mid+1,end,pos,val);
		}
		tree[node]=min(tree[node*2],tree[node*2+1]);
	}
}



void solve()
{
	ll n,q;
	cin >>n>>q;
	rep(i, 0, n)
	{
		cin >> a[i];
	}
	build(1,0,n-1);
	while(q--)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			int x,y;
			cin>>x>>y;
			x--;
			update(1,0,n-1,x,y);
		}
		else{
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			cout<<getmin(1,0,n-1,l,r)<<nline;
		}
	}



}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	solve();
	return 0;
}