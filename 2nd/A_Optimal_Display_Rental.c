// 存在未知错误
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 3000000001

long long min_rent_cost(int n, long long s[], long long c[]) {
    long long** dp = (long long**)malloc(n * sizeof(long long*));
    for (int i = 0; i < n; i++) {
        dp[i] = (long long*)malloc(4 * sizeof(long long));
    }
    long long min_cost = MAX;
    int found = 0;
    
    for (int i = 0; i < n; i++) {
        dp[i][0] = c[i];
        dp[i][1] = MAX;
        dp[i][2] = MAX;
        for(int j = 1; j < 3; j++) {
            for(int k = 0; k < i; k++) {
                if(s[k] < s[i])
                {
                    dp[i][j] = fmin(dp[i][j], dp[k][j - 1] + c[i]);
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(dp[i][2] < min_cost)
        {
            found = 1;
            min_cost = dp[i][2];
        }
    }
   
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);

    if (found) {
        return min_cost;
    } else {
        return -1;
    }
}

int main() {
    int n, i;
    long long temp;
    i = 0;
    temp = 0;

    scanf("%d", &n);
    getchar();

    long long* s = (long long*)malloc(n * sizeof(long long));
    long long* c = (long long*)malloc(n * sizeof(long long));
    
    char ch;

    while((ch = getchar()) != EOF && ch != '\n') {
        if(ch == ' ')
        {
            s[i] = temp;
            temp = 0;
            i++;
            continue;
        }
        else if('0' <= ch && ch <= '9')
        {
            temp = temp + (ch - '0');
        }
    }
    s[i] = temp;

    i = 0;
    temp = 0;

    while((ch = getchar()) != EOF && ch != '\n') {
        if(ch == ' ')
        {
            c[i] = temp;
            temp = 0;
            i++;
            continue;
        }
        else if('0' <= ch && ch <= '9')
        {
            temp = temp * 10 + (ch - '0');
        }
    }
    c[i] = temp;
    
    long long result = min_rent_cost(n, s, c);
    printf("%lld\n", result);

    free(s);
    free(c);
    
    return 0;
}