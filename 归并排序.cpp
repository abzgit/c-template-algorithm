int merge_sort(int l, int r)
{
    if (l >= r) return 0;
    int mid = l + r >> 1;
    int res = (merge_sort(l, mid) + merge_sort(mid + 1, r)) % MOD;

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
        if (b[i] < b[j]) p[k ++ ] = b[i ++ ];
        else p[k ++ ] = b[j ++ ], res = (res + mid - i + 1) % MOD;
    while (i <= mid) p[k ++ ] = b[i ++ ];
    while (j <= r) p[k ++ ] = b[j ++ ];

    for (i = l, j = 0; j < k; i ++, j ++ ) b[i] = p[j];
    return res;
}