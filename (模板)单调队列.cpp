#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int a[N];
deque<int> q;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
	return x * f;
}

int main(){
    int n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		while(!q.empty() && q.front() <= i - k) q.pop_front();
		while(!q.empty() && a[q.back()] >= a[i]) q.pop_back();
		q.push_back(i);
		if(i >= k) printf("%d ", a[q.front()]);
	}
	putchar('\n');
	q.clear();
	for(int i = 1; i <= n; i++) {
		while(!q.empty() && q.front() <= i - k) q.pop_front();
		while(!q.empty() && a[q.back()] <= a[i]) q.pop_back();
		q.push_back(i);
		if(i >= k) printf("%d ", a[q.front()]);
	}
    return 0;
}