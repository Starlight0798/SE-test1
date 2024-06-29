#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define pii pair<int, int>
typedef long long ll;

const ll INF = 1e9;
const int MAXN = 3001;
ll cnt[MAXN], d[MAXN], dis[MAXN];
bool ch[MAXN], vis[MAXN];

vector<pii> G[MAXN];

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
	return x * f;
}

bool spfa(int n, int s) {
	priority_queue<pii, vector<pii>, greater<pii>> que;
	for (int i = 0; i <= n; i++) d[i] = INF;
	d[s] = 0;
	que.push({0,s});
	while (!que.empty()) {
		int cur = que.top().second;
		que.pop();
		ch[cur] = false;
		for (pii& node : G[cur]) {
			int to = node.second;
			ll w = node.first;
			if (d[to] > d[cur] + w) {
				d[to] = d[cur] + w;
				cnt[to] = cnt[cur] + 1;
				if (cnt[to] >= n) return true;
				if (!ch[to]) {
					ch[to] = true;
					que.push({d[to],to});
				}
			}
		}
	}
	return false;
}

void dijkstra(int n, int s) {
	priority_queue<pii, vector<pii>, greater<pii>> que;
	for (int i = 0; i <= n; i++) {dis[i] = INF; vis[i] = false;}
	dis[s] = 0;
	que.push({0, s});
	while (!que.empty()) {
		int cur = que.top().second;
		que.pop();
		if (vis[cur]) continue;
		vis[cur] = true;
		for (pii& node : G[cur]) {
			int to = node.second;
			ll w = node.first + d[cur] - d[to]; // 修正边权
			if (dis[to] > dis[cur] + w) {
				dis[to] = dis[cur] + w;
				que.push({ dis[to], to});
			}
		}
	}
}

int main() {
	int n, m, u, v, w;
	n = read(); m = read();
	for (int i = 1; i <= m; i++) {
		u = read(); v = read(); w = read();
		G[u].push_back({ w, v });
	}
	for (int i = 1; i <= n; i++) G[0].push_back({0, i});
	if (spfa(n+1, 0)) { cout << "-1"; return 0; }
	for (int i = 1; i <= n; i++) {
		dijkstra(n, i);
		ll ans = 0;
		for (int j = 1; j <= n; j++) {
			if (dis[j] == INF) ans += j * INF;
			else ans += j * (dis[j] + d[j] - d[i]);
		}
		cout << ans << endl;
	}
	return 0;
}