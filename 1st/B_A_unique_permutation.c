#include <stdio.h>
#include <stdlib.h>

#define MAXN 10000

int anti_permutation[MAXN];
int temp[MAXN];

void dfs(int left, int right)
{
    if(left >= right)
    {
        return;
    }
    
    int i, j, mid;

    for(i = left; i <= right; i++)
    {
        temp[i] = anti_permutation[i];
    }
    for(i = left, j = left; i <= right; i += 2, j++)
    {
        anti_permutation[j] = temp[i];
    }

    mid = j;

    for(i = left + 1; i <= right; i += 2, j++)
    {
        anti_permutation[j] = temp[i];
    }

    dfs(left, mid - 1);
    dfs(mid, right);
}

int main()
{
    int n, i;

    while((scanf("%d", &n) != EOF) && n)
    {
        for(i = 0; i < n; i++)
        {
            anti_permutation[i] = i;
        }

        dfs(0, n - 1);

        printf("%d:", n);

        for(i = 0; i < n; i++)
        {
            printf(" %d", anti_permutation[i]);
        }

        printf("\n");
    }

    return 0;
}