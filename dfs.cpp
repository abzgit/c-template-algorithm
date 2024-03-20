#include<bits/stdc++.h>
using namespace std;
bool ans;
bool un;//不可能事件
int newx,newy;
bool isok(){
	//越界
}
vector<vector<bool>> visit;
void dfs(int x,int y){
	if(ans){	//找到答案 
		ans;	//保存答案 
	}
	if(un){	//剪枝 
		return;
	} 
	for(isok()&&visit[newx][newy]){	//边界处理，且没访问过 
		dfs(newx,newy);
	} 
}