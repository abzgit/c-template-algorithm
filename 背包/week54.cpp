/*
���� V�ֻ��ң���λ��Ԫ����ÿ�ֻ���ʹ�õĴ������ޡ�
��ͬ����Ļ��ң���ֵ��������ͬ�ġ�
���ڣ�Ҫ������ V�ֻ��Ҵճ� NԪǮ�����ʹ��ж����ֲ�ͬ�Ĵշ���
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
