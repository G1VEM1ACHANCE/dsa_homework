#include <cstdio>

const int MAX_N = 200000 + 7;

int A[MAX_N];
long long S[MAX_N];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
        S[i] = S[i - 1] + A[i];
    }
    while (M--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n", S[r] - S[l - 1]);    
    }
    return 0;
}
