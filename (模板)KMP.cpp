#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int nxt[N];

void getnxt(const string &str){
	memset(nxt, 0, sizeof(nxt));
	int len = str.length();
	nxt[0] = -1;
	int k = -1, j = 0;
	while(j < len){
		if(k == -1 || str[j] == str[k]){
			++k;
			++j;
			// nxt[j] = k;
			if(str[j] == str[k]) nxt[j] = nxt[k];
			else nxt[j] = k;
		}
		else k = nxt[k];
	}
}

vector<int> kmp(const string &s, const string &t){
	vector<int> pos;
	int i = 0, j = 0;
	int s_len = s.length(), t_len = t.length();
	while(i < s_len){
		if(j == -1 || s[i] == t[j]){
			++i;
			++j;
		}
		else j = nxt[j];
		if(j == t_len){
			pos.push_back(i - j + 1);
			j = nxt[j];
		}
	}
	return pos;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    string s1, s2;
	cin >> s1 >> s2;
	getnxt(s2);
	vector<int> ans = kmp(s1, s2);
	for(auto &x : ans){
		cout << x << "\n";
	}
	for(size_t i = 1; i <= s2.length(); ++i){
		cout << nxt[i] << " ";
	}
    return 0;
}