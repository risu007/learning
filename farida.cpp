#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll f(ll *a,ll n,ll ini)
{
	ll sum,temp=0,i;
	for(i=ini;i<n;i++)
	{
		sum=a[i]+f(a,n,i+2);
		temp=max(sum,temp);
	}
	return temp;
}
int main()
{
	int t,j=1;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll a[n],i;
		for(i=0;i<n;i++)
			cin>>a[i];
		cout<<"Case "<<j++<<": "<<f(a,n,0)<<endl;
	}
	return 0;
}
