#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x,k;
int qmi(int a,int b,int mod){
	int ret = 1;
	while(b){
		if(b&1){
			ret = ll(ret*a)%mod;
		}
		b>>=1;
		a = ll(a*a)%mod;
	}
	return ret;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&x);
	printf("%d",(x+ll(qmi(10,k,n)*m)%n)%n);
	return 0;
} 
