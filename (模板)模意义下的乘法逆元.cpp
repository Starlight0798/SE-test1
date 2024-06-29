#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e6 + 1;
int ind[N] = {0, 1};

int main(){
    int n, p;
    scanf("%d%d", &n, &p);
    printf("%d\n", ind[1]);
    for(int i = 2; i <= n; i++){
        ind[i] = (ll)(p - p / i) * ind[p % i] % p;
        printf("%d\n", ind[i]);
    }
    return 0;
}