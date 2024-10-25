#include <stdio.h>
#include <stdlib.h>

#define MAX_N 2500
#define MAX_INT 0x7fffffff

int n, m;
int* cows_time;
int dp[MAX_N + 1], time[MAX_N];

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    // input
    scanf("%d %d", &n, &m);
    cows_time = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cows_time[i]);
    }
    
    time[0] = cows_time[0] + 2 * m;

    for (int i = 1; i < n; i++)
    {    
        time[i] = time[i - 1] + cows_time[i];
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = MAX_INT;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] = min(dp[j - i] + time[i - 1], dp[j]);
        }
    }

    printf("%d\n", dp[n] - m);

    return 0;
}