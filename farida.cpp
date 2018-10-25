#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[1005];
ll a[1005];
ll n;
ll f(ll ini)
{
	if(ini==n)
		return 0;
	if(dp[ini]==-1)
	{
		dp[ini] = 0;
		dp[ini] = max(dp[ini+1],a[ini]+dp[ini+2]);
	}
	return dp[ini];
}
int main()
{
	int t,j=1;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof dp);
		cin>>n;
		ll a[n],i;
		for(i=0;i<n;i++)
			cin>>a[i];
		cout<<"Case "<<j++<<": "<<f(a,n,0)<<endl;
	}
	return 0;
}
