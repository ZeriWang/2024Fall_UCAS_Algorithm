#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct  waypoint
{
    int value;
    int direction; // 1：right 2：down
};

// 读取一行整数
void read_int(int* arr)
{
    int i = 0;
    char c;
    while((c = getchar()) != '\n' && c != EOF)
    {
        if(c == ' ')
        {
            i++;
        }
        else
        {
            arr[i] = arr[i] * 10 + c - '0';
        }
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n); // 读取矩阵的行数和列数
    getchar();

// 读取矩阵
    int** grid = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        grid[i] = (int*)malloc(n * sizeof(int));
    }

    for(int i = 0; i < m; i++)
    {
        read_int(grid[i]);
    }

// 动态规划
    struct waypoint** dp = (struct waypoint**)malloc(m * sizeof(struct waypoint*));
    for(int i = 0; i < m; i++)
    {
        dp[i] = (struct waypoint*)malloc(n * sizeof(struct waypoint));
    }

// 从左上角到右下角的最大路径和
    dp[0][0].value = grid[0][0];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)
            {
                continue;
            }
            if(i == 0)
            {
                dp[i][j].value = dp[i][j - 1].value + grid[i][j];
                dp[i][j].direction = 1;
            }
            else if(j == 0)
            {
                dp[i][j].value = dp[i - 1][j].value + grid[i][j];
                dp[i][j].direction = 2;
            }
            else
            {
                if(dp[i][j - 1].value > dp[i - 1][j].value)
                {
                    dp[i][j].value = dp[i][j - 1].value + grid[i][j];
                    dp[i][j].direction = 1;
                }
                else
                {
                    dp[i][j].value = dp[i - 1][j].value + grid[i][j];
                    dp[i][j].direction = 2;
                }
            }
        }
    }
}
