#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 30
#define MAX_D 30000000000LL

bool dp[MAX_N + 1][MAX_D + 1];
int count[MAX_D + 1];

void solve(int N, long long D, int *weights, int case_num) {
    memset(dp, 0, sizeof(dp));
    memset(count, 0, sizeof(count));
    dp[0][0] = true;
    count[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (long long j = D; j >= weights[i - 1]; j--) {
            if (dp[i - 1][j - weights[i - 1]]) {
                dp[i][j] = true;
                count[j] += count[j - weights[i - 1]];
            }
        }
    }

    if (!dp[N][D]) {
        printf("Case #%d: IMPOSSIBLE\n", case_num);
    } else {
        int min_items = N + 1;
        for (int i = 1; i <= N; i++) {
            if (dp[i][D]) {
                min_items = i;
                break;
            }
        }
        if (count[D] > 1) {
            printf("Case #%d: AMBIGIOUS\n", case_num);
        } else {
            printf("Case #%d: %d\n", case_num, min_items);
        }
    }
}

int main() {
    int T, N;
    long long D;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %lld", &N, &D);
        int *weights = (int *)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &weights[i]);
        }
        solve(N, D, weights, t);
        free(weights);
    }
    return 0;
}