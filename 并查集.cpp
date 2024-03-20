class uset {
public:
	int par;		//父节点
	int rank;		//路径压缩，子节点个数
	uset(int a, int b) :par(a), rank(b) {}
};
class solu
{
public:
	vector<uset*> node;
	solu(int n);
	~solu();
	int findr(int i) {	//找根节点
		if (node[i]->par != i) {
			node[i]->par = findr(node[i]->par);
		}
		return node[i]->par;
	}
	void unionset(int a,int b) {	//合并
		int roota = findr(a);
		int rootb = findr(b);
		if (roota != rootb) {
			if (node[roota]->rank > node[rootb]->rank) {
				node[roota]->rank += node[rootb]->rank;
				node[rootb]->par = roota;
			}
			else if (node[roota]->rank < node[rootb]->rank) {
				node[rootb]->rank += node[roota]->rank;
				node[roota]->par = rootb;
			}
			else {
				node[roota]->par = rootb;
				node[rootb]->rank += 1;
			}
		}
	}
private:

};

solu::solu(int n)
{
	for (int i = 0; i < n; ++i) {
		node.push_back(new uset(i, 0));
	}
}

solu::~solu()
{
}