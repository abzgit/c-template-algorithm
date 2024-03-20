#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f; // 表示无穷大
struct Edge {
    int to; // 边的终点
    int weight; // 边的权重
    Edge(int t, int w) : to(t), weight(w) {}
};
vector<Edge> adj[100010]; // 邻接表
int dist[100010]; // 顶点的最短路径值
bool in_queue[100010]; // 顶点是否在队列中
bool visited[100010]; // 顶点是否被访问过

void spfa(int n, int start) {
    memset(dist, INF, sizeof(dist));
    memset(in_queue, false, sizeof(in_queue));
    memset(visited, false, sizeof(visited));

    dist[start] = 0;
    in_queue[start] = true;
    visited[start] = true;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        for (auto& edge : adj[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                if (!in_queue[v] && !visited[v]) {
                    q.push(v);
                    in_queue[v] = true;
                    visited[v] = true;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cout << "请输入顶点数和边数：";
    cin >> n >> m;

    cout << "请输入边的连接关系和权重（每行输入一个边，格式为：u v w）：" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));
        // 如果图是有向图，则还需要添加反向边
        // adj[v].push_back(Edge(u, w));
    }

    cout << "请输入源点：";
    int start;
    cin >> start;

    spfa(n, start);

    cout << "顶点的最短路径值：" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "dist[" << i << "] = " << dist[i] << endl;
    }

    return 0;
}
