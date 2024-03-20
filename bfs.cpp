bfs(){
	queue<point> q;	//创建队列 
	q.push(start);	//初始状态入队
	while(!q.empty){	//广度搜索 
		auto a = q.front();
		q.pop();
		if(ans)	return;	//找到答案退出 
		for(isok()){	//满足条件入队列 
			q.push(); 
		}
	} 
}