#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define pii pair<int, int> 

const int INF = 0x7FFFFFFF;
const int MAXN = 1e5 + 1;
int cnt[MAXN], dis[MAXN]; // 记录到达次数和距离
bool ch[MAXN]; // 记录是否在队列中

vector<pii> G[MAXN];

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
	return x * f;
}

bool spfa(int n, int s) {
	for (int i = 1; i <= n; i++) dis[i] = INF;
	dis[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> que;
	que.push({0, s});
	while (!que.empty()) {
		int cur = que.top().second;
		que.pop();
		ch[cur] = false;
		for (pii& node : G[cur]) {
			int to = node.second, w = node.first;
			if (dis[to] > dis[cur] + w) {
				dis[to] = dis[cur] + w;
				cnt[to] = cnt[cur] + 1;
				if (cnt[to] >= n) return true;
				if (ch[to] == false) {
					ch[to] = true;
					que.push({dis[to],to});
				}
			}
		}
	}
	return false;
}


int main() {
	int n, m, s, u, v, w;
	n = read(); m = read(); s = read();
	for (int i = 0; i < m; i++) {
		u = read(); v = read(); w = read();
		G[u].push_back({w, v});
	}
	spfa(n, s);
	for (int i = 1; i <= n; i++) cout << dis[i] << " ";
	return 0;
}