/*
给定 V种货币（单位：元），每种货币使用的次数不限。
不同种类的货币，面值可能是相同的。
现在，要你用这 V种货币凑出 N元钱，请问共有多少种不同的凑法。
*/
#include<bits/stdc++.h>
using namespace std;
const int M = 30,N = 10010;
int n,m;
int coin[M];
long long int f[M][N];
int main(){
	cin>>n>>m;
	for(int i = 1; i <= n; ++i){
		cin>>coin[i];
	}
	f[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= m; ++j){
			for(int k = 0; k *coin[i] <= j; ++k){
				f[i][j] += f[i-1][j-k*coin[i]];
			}
		}
	}
	cout<<f[n][m];
	return 0;
} 
