#include <stdio.h>
#include <math.h>

#define MAX_N 1000

double calculateDistance(int siteX, int siteY, int agentX, int agentY) {
    return sqrt(pow(siteX - agentX, 2) + pow(siteY - agentY, 2));
}

double minDistance(int N, int sites[][2], int agents[][2]) {
    double dp[MAX_N];
    
    // 初始化 dp 数组
    for (int i = 0; i < N; i++) {
        dp[i] = calculateDistance(sites[i][0], sites[i][1], agents[0][0], agents[0][1]);
    }
    
    // 动态规划计算最小距离
    for (int j = 1; j < N; j++) {
        for (int i = 0; i < N; i++) {
            double dist = calculateDistance(sites[i][0], sites[i][1], agents[j][0], agents[j][1]);
            dp[i] = fmin(dp[i], dist);
        }
    }
    
    double minDist = dp[0];
    for (int i = 1; i < N; i++) {
        minDist = fmin(minDist, dp[i]);
    }
    
    return minDist;
}

int main() {
    int T, N;
    scanf("%d", &T);
    
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        
        int sites[MAX_N][2];
        int agents[MAX_N][2];
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &sites[i][0], &sites[i][1]);
        }
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &agents[i][0], &agents[i][1]);
        }
        
        double minDist = minDistance(N, sites, agents);
        printf("%.3f\n", minDist);
    }
    
    return 0;
}