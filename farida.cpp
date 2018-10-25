#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[10005];
ll a[10005];
ll n;

ll f(ll ini)
{
	if(ini>=n)
	return 0;
	if(dp[ini]==-1)
	{
		dp[ini] = max(f(ini+1),a[ini]+f(ini+2));
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
		ll i;
		for(i=0;i<n;i++)
			cin>>a[i];
		cout<<"Case "<<j++<<": "<<f(0)<<endl;
	}
	return 0;
}
