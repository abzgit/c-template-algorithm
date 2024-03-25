#include<iostream>
#include<cstdio>
int n,a[3000005],sta[3000005],tp,ans[3000005];//´æÏÂ±ê
using namespace std;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i <= n;++i)
	{
		while(tp&&sta[tp] >= a[i]) tp--;
		ans[i] = sta[tp];
		sta[++tp] = a[i];
	}
	cout<<ans[1];
	for(int i=2;i<=n;i++)
	cout<<' '<<ans[i];
	return 0;
}

