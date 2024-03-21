#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000;//数组大小 
int tr[N]; 
int n,tmp;
ll pre[N];	//前缀和数组 
int lowbit(int x){
	return x & (-x);
}
void add(int x,int c){	//在x位置上加上c 
	for(int i = x; i <= n; i += lowbit(i)){
		tr[i] += c;
	}
}
ll sum(int x){//查询前n项和 
	ll ret = 0;
	for(int i = x;i; i -= lowbit(i)){
		ret += tr[i];
	} 
	return ret;
}
int main(){
	cin>>n;//数组长度0 
	pre[0] = 0;
	memset(tr,0,sizeof tr);
	for(int i = 1; i <= n; ++i){
		cin>>tmp;
		pre[i] = tmp + pre[i-1];
		tr[i] = pre[i] - pre[i-lowbit(i)];
	}
	return 0;
}
