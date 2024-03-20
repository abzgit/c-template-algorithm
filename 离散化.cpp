void work(int a[])
{
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    sort(p + 1, p + n + 1, [&](int x, int y) {
        return a[x] < a[y];
    });
    for (int i = 1; i <= n; i ++ ) a[p[i]] = i;
}