#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 1;
int a[N], f[N];
stack<int> st;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch > '9' || ch < '0') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
	return x * f;
}

int main(){
    int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = n; i >= 1; i--) {
		while(!st.empty() && a[i] >= a[st.top()]) st.pop();
		f[i] = st.empty() ? 0 : st.top();
		st.push(i);
	}
	for(int i = 1; i <= n; i++) printf("%d ", f[i]);
    return 0;
}