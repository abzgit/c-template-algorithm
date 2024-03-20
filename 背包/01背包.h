const int len = 1000;
int v[len], w[len];
int f[len];
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		cin >> v[i] >> w[i];
	}
	f[0] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = v[i]; j <= n; ++j) {		//如果从小到大,求dp[2]会用到第i-1行dp[i-1][2]以及在这之前的数据后面计算dp[3]、dp[4]等dp值时，若再要用到dp[2]，拿到的不再是想要dp[i-1][2]值，而是新求得的dp[2]值。
				f[j] = max(f[j - v[i]] + w[i], f[j]);
		}
	}
	cout << f[n];
	return 0;
}