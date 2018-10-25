#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int a[1000];
int size;

int f(int n,int ini)
{
	if(n==0)
	return 1;
	if(n<0)
	return 0;
	if(ini==size)
	return 0;
	if(dp[n][ini]==-1)
	{
		dp[n][ini]=0;
		for(int i=ini;i<size;i++)
		{
			dp[n][ini]+=f(n-a[i],i);
		}
	}
	return dp[n][ini];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
	int n;
	memset(dp,-1,sizeof dp);
	cin>>size;
	for(int i=0;i<size;i++)
		cin>>a[i];
	cin>>n;
	
	cout<<f(n,0)<<endl;
	}
	return 0;
}
