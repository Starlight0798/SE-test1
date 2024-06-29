#include<iostream>
using namespace std;

const int MAXN = 10001;
int df[MAXN], ra[MAXN];

int find(int x) { return df[x] == x ? x : df[x] = find(df[x]); }
void init(int n) { for(int i = 1; i <= n; i++) df[i] = i, ra[i] = 1; }

inline void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (ra[x] < ra[y]) swap(x, y);
	else if (ra[x] == ra[y]) ra[x]++;
	df[y] = x;
}

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
	return x * f;
}

int main() {
	int n, m, x, y, z;
	n = read(); m = read(); 
	init(n);
	for (int i = 0; i < m; i++) {
		z = read(); x = read(); y = read();
		if (z == 1) merge(x, y);
		if (z == 2) {
			char s = find(x) == find(y) ? 'Y' : 'N';
			cout << s << endl;
		}
	}
	return 0;
}