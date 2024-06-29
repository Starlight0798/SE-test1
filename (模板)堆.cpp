#include<iostream>
using namespace std;

const int MAXN = 1e6 + 1;
int heap[MAXN], len;

void insert(int n) {
	heap[++len] = n;
	int pa = len >> 1, now = len;
	while (pa) {
		if (heap[pa] > heap[now]) swap(heap[pa], heap[now]);
		now = pa;
		pa >>= 1;
	}
}

void pop() {
	heap[1] = heap[len--];
	int pa = 1;
	while (pa * 2 <= len) {
		int cur = pa << 1;
		if (cur < len && heap[cur] > heap[cur + 1]) cur++;
		if (heap[pa] > heap[cur]) swap(heap[pa], heap[cur]);
		pa = cur;
	}
}
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, op;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> op;
		if (op == 1) {
			cin >> op;
			insert(op);
		}
		else if (op == 2) {
			cout << heap[1] << '\n';
		}
		else if (op == 3) {
			pop();
		}
	}
	return 0;
}