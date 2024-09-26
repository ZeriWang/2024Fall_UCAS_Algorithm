#include <stdio.h>
#include <limits.h>

void solve_case(int N, int D, int weights[]) {
    int dp[D + 1];
    int count[D + 1];

    // 初始化 dp 和 count 数组
    for (int i = 0; i <= D; i++) {
        dp[i] = INT_MAX; // 设置为无穷大
        count[i] = 0;    // 初始化组合数量为 0
    }

    dp[0] = 0;   // 0重量需要0个物品
    count[0] = 1; // 只有一种方式达到0重量

    // 动态规划更新
    for (int i = 0; i < N; i++) {
        int weight = weights[i];
        for (int w = D; w >= weight; w--) {
            if (dp[w - weight] + 1 < dp[w]) {
                dp[w] = dp[w - weight] + 1;
                count[w] = count[w - weight];
            } else if (dp[w - weight] + 1 == dp[w]) {
                count[w] += count[w - weight];
            }
        }
    }

    // 输出结果
    if (dp[D] == INT_MAX) {
        printf("IMPOSSIBLE\n");
    } else if (count[D] > 1) {
        printf("AMBIGUOUS\n");
    } else {
        printf("%d\n", dp[D]);
    }
}

int main() {
    int T;
    scanf("%d", &T); // 读取测试用例数量
    for (int case_num = 1; case_num <= T; case_num++) {
        int N, D, i = 0;
        char c;
        scanf("%d %d", &N, &D); // 读取物品数量和目标重量
        int weights[N];
        
        c = getchar(); // 读取换行符

        while((c = getchar()) != '\n') {
            if (c == ' ') {
                continue;
            }
            weights[i++] = c - '0';
        }

        printf("Case #%d: ", case_num);
        solve_case(N, D, weights); // 解决当前测试用例
    }
    return 0;
}