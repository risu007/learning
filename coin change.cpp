using namespace std;

int f(int n,int *a,int ini,int size)
{
	int i,sum=0,temp;
	for(i=ini;i<size;i++)
	{
		temp=n-a[i];
		if(temp==0)
			sum++;
		else if(temp>0)
			sum+=f(temp,a,i,size);
	}
	return sum;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,size;
	cin>>size;
	int a[size];
	for(int i=0;i<size;i++)
		cin>>a[i];
	cin>>n;
	cout<<f(n,a,0,size)<<endl;
	}
	return 0;
}
