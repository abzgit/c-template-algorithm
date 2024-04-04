#include<iostream>
using namespace std;
int a[100];
int tmp;
bool check(int mid){
	//符合条件返回true，不符合条件返回false 
	if(mid > tmp){
		return false;
	}
	return true;
}
//二分结果是找第一个true 
int search_1(int l,int r){
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}
//当结果显示.........vooooooo时，用search_1，其中.为false,vo为true 
int search_2(int l,int r){
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}
//反之ooooooov.......时用search_2 
int main(){
	int n;
	cin>>n>>tmp;
	int ans1 = search_1(0,n);
	int ans2 = search_2(0,n);
	cout<<ans1<<"   "<<ans2;
	return 0;
}
