#include<iostream>
using namespace std;
int a[100];
int tmp;
bool check(int mid){
	//������������true����������������false 
	if(mid > tmp){
		return false;
	}
	return true;
}
//���ֽ�����ҵ�һ��true 
int search_1(int l,int r){
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}
//�������ʾ.........voooooooʱ����search_1������.Ϊfalse,voΪtrue 
int search_2(int l,int r){
	while(l < r){
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}
//��֮ooooooov.......ʱ��search_2 
int main(){
	int n;
	cin>>n>>tmp;
	int ans1 = search_1(0,n);
	int ans2 = search_2(0,n);
	cout<<ans1<<"   "<<ans2;
	return 0;
}
