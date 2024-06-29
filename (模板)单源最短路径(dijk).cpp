#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int, int> 

const int INF = 0x7FFFFFFF;
const int MAXN = 1e5 + 1;
int dis[MAXN];
bool vis[MAXN];

vector<pii> G[MAXN];

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
	return x * f;
}

void dijkstra(int n, int s) {
	priority_queue<pii, vector<pii>, greater<pii>> que;
	for (int i = 1; i <= n; i++) dis[i] = INF;
	dis[s] = 0;
	que.push({0, s});
	while (!que.empty()) {
		int cur = que.top().second;
		que.pop();
		if (vis[cur]) continue;
		vis[cur] = true;
		for (pii& nd : G[cur]) {
			int to = nd.second, w = nd.first;
			if (dis[to] > dis[cur] + w) {
				dis[to] = dis[cur] + w;
				que.push({dis[to], to});
			}
		}
	}
}

int main()
{
	int n, m, s, u, v, w;
	n = read(); m = read(); s = read();
	for (int i = 0; i < m; i++) {
		u = read(); v = read(); w = read();
		G[u].push_back({w, v});
	}
	dijkstra(n, s);
	for (int i = 1; i <= n; i++) cout << dis[i] << " ";
	return 0;
}